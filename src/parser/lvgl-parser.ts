import { FontData, Glyph, CmapRange, CmapType } from '../model/font-model.js';

/**
 * Error thrown when parsing an LVGL font file fails.
 */
export class ParseError extends Error {
  /** The parsing phase that failed. */
  section: string;

  constructor(message: string, section: string) {
    super(`Parse error in ${section}: ${message}`);
    this.name = 'ParseError';
    this.section = section;
  }
}

/**
 * Maps LVGL C enum names to CmapType values.
 */
function parseCmapType(typeStr: string): CmapType {
  const trimmed = typeStr.trim();
  if (trimmed === 'LV_FONT_FMT_TXT_CMAP_FORMAT0_TINY') return CmapType.FORMAT0_TINY;
  if (trimmed === 'LV_FONT_FMT_TXT_CMAP_FORMAT0_FULL') return CmapType.FORMAT0_FULL;
  if (trimmed === 'LV_FONT_FMT_TXT_CMAP_SPARSE_TINY') return CmapType.SPARSE_TINY;
  throw new ParseError(`Unknown cmap type: ${trimmed}`, 'cmap');
}

/**
 * Extracts key-value fields from the header comment block.
 */
function parseHeader(source: string): { size: number; bpp: number; opts: string; headerComment: string } {
  const headerMatch = source.match(/\/\*{3,}[\s\S]*?\*{3,}\//);
  if (!headerMatch) {
    throw new ParseError('Header comment block not found', 'header');
  }
  const headerComment = headerMatch[0];

  const sizeMatch = headerComment.match(/Size:\s*(\d+)\s*px/i);
  const bppMatch = headerComment.match(/Bpp:\s*(\d+)/i);
  const optsMatch = headerComment.match(/Opts:\s*(.+)/i);

  if (!sizeMatch) throw new ParseError('Size not found in header', 'header');
  if (!bppMatch) throw new ParseError('Bpp not found in header', 'header');

  return {
    size: parseInt(sizeMatch[1], 10),
    bpp: parseInt(bppMatch[1], 10),
    opts: optsMatch ? optsMatch[1].trim() : '',
    headerComment,
  };
}

/**
 * Extracts the font guard name (e.g. "TINY_MONO_3X5") from #if directives.
 */
function parseFontGuard(source: string): string {
  const guardMatch = source.match(/#if\s+([A-Z_][A-Z0-9_]+)\s*\n/);
  if (!guardMatch) throw new ParseError('Font guard macro not found', 'guard');
  return guardMatch[1];
}

/**
 * Decodes continuously-packed bitmap bytes into a 2D boolean array.
 * Bits are packed MSB-first in a flat stream: pixel (row, col) is at
 * bit index (row * boxWidth + col). No per-row byte alignment.
 */
export function decodeBitmap(bytes: number[], boxWidth: number, boxHeight: number): boolean[][] {
  const bitmap: boolean[][] = [];

  for (let row = 0; row < boxHeight; row++) {
    const rowPixels: boolean[] = [];
    for (let col = 0; col < boxWidth; col++) {
      const bitIndex = row * boxWidth + col;
      const byteIndex = Math.floor(bitIndex / 8);
      const bitPos = 7 - (bitIndex % 8);
      const byteVal = byteIndex < bytes.length ? bytes[byteIndex] : 0;
      rowPixels.push(((byteVal >> bitPos) & 1) === 1);
    }
    bitmap.push(rowPixels);
  }

  return bitmap;
}

/**
 * Parses the glyph_bitmap[] array, extracting raw bytes and Unicode associations.
 */
function parseGlyphBitmaps(source: string): { unicode: number; char: string; bytes: number[] }[] {
  const bitmapMatch = source.match(
    /static\s+LV_ATTRIBUTE_LARGE_CONST\s+const\s+uint8_t\s+glyph_bitmap\[\]\s*=\s*\{([\s\S]*?)\};/
  );
  if (!bitmapMatch) throw new ParseError('glyph_bitmap array not found', 'bitmap');

  const bitmapBody = bitmapMatch[1];
  const glyphEntries: { unicode: number; char: string; bytes: number[] }[] = [];

  // Match each /* U+XXXX "c" */ comment and collect hex bytes until next comment or end
  const commentPattern = /\/\*\s*U\+([0-9A-Fa-f]+)\s+"((?:[^"\\]|\\.)*)"\s*\*\//g;
  const comments: { unicode: number; char: string; index: number }[] = [];

  let commentMatch;
  while ((commentMatch = commentPattern.exec(bitmapBody)) !== null) {
    let charStr = commentMatch[2];
    // Handle escaped characters
    if (charStr === '\\\\') charStr = '\\';
    else if (charStr === '\\"') charStr = '"';

    comments.push({
      unicode: parseInt(commentMatch[1], 16),
      char: charStr,
      index: commentMatch.index + commentMatch[0].length,
    });
  }

  for (let i = 0; i < comments.length; i++) {
    const startIdx = comments[i].index;
    const endIdx = i + 1 < comments.length
      ? bitmapBody.lastIndexOf('/*', bitmapBody.indexOf('/*', startIdx + 1))
      : bitmapBody.length;

    const segment = bitmapBody.substring(startIdx, endIdx > startIdx ? endIdx : bitmapBody.length);

    // Extract hex byte values
    const hexPattern = /0x([0-9A-Fa-f]+)/g;
    const bytes: number[] = [];
    let hexMatch;
    while ((hexMatch = hexPattern.exec(segment)) !== null) {
      bytes.push(parseInt(hexMatch[1], 16));
    }

    glyphEntries.push({
      unicode: comments[i].unicode,
      char: comments[i].char,
      bytes,
    });
  }

  return glyphEntries;
}

/**
 * Parses the glyph_dsc[] array.
 */
function parseGlyphDescriptors(source: string): {
  bitmapIndex: number;
  advW: number;
  boxW: number;
  boxH: number;
  ofsX: number;
  ofsY: number;
}[] {
  const dscMatch = source.match(
    /static\s+const\s+lv_font_fmt_txt_glyph_dsc_t\s+glyph_dsc\[\]\s*=\s*\{([\s\S]*?)\};/
  );
  if (!dscMatch) throw new ParseError('glyph_dsc array not found', 'glyph_dsc');

  const dscBody = dscMatch[1];
  const entryPattern =
    /\.bitmap_index\s*=\s*(\d+)\s*,\s*\.adv_w\s*=\s*(\d+)\s*,\s*\.box_w\s*=\s*(\d+)\s*,\s*\.box_h\s*=\s*(\d+)\s*,\s*\.ofs_x\s*=\s*(-?\d+)\s*,\s*\.ofs_y\s*=\s*(-?\d+)/g;

  const descriptors: {
    bitmapIndex: number;
    advW: number;
    boxW: number;
    boxH: number;
    ofsX: number;
    ofsY: number;
  }[] = [];

  let match;
  while ((match = entryPattern.exec(dscBody)) !== null) {
    descriptors.push({
      bitmapIndex: parseInt(match[1], 10),
      advW: parseInt(match[2], 10),
      boxW: parseInt(match[3], 10),
      boxH: parseInt(match[4], 10),
      ofsX: parseInt(match[5], 10),
      ofsY: parseInt(match[6], 10),
    });
  }

  // First entry is reserved (id=0), skip it
  if (descriptors.length > 0) {
    descriptors.shift();
  }

  return descriptors;
}

/**
 * Parses uint16_t or uint8_t named arrays from source (e.g. unicode_list_1, glyph_id_ofs_list_2).
 */
function parseNamedArrays(source: string): Map<string, number[]> {
  const result = new Map<string, number[]>();
  const pattern = /static\s+const\s+uint(?:8|16)_t\s+(\w+)\[\]\s*=\s*\{([^}]*)\}/g;

  let match;
  while ((match = pattern.exec(source)) !== null) {
    const name = match[1];
    const body = match[2];
    const values: number[] = [];
    const numPattern = /0x([0-9A-Fa-f]+)|\b(\d+)\b/g;
    let numMatch;
    while ((numMatch = numPattern.exec(body)) !== null) {
      if (numMatch[1]) {
        values.push(parseInt(numMatch[1], 16));
      } else if (numMatch[2] !== undefined) {
        values.push(parseInt(numMatch[2], 10));
      }
    }
    result.set(name, values);
  }

  return result;
}

/**
 * Parses the cmaps[] array.
 */
function parseCmaps(source: string): CmapRange[] {
  const cmapMatch = source.match(
    /static\s+const\s+lv_font_fmt_txt_cmap_t\s+cmaps\[\]\s*=\s*\{([\s\S]*?)\};/
  );
  if (!cmapMatch) throw new ParseError('cmaps array not found', 'cmap');

  const namedArrays = parseNamedArrays(source);
  const cmapBody = cmapMatch[1];
  const cmaps: CmapRange[] = [];

  // Match each { ... } block within cmaps
  const blockPattern = /\{([^}]+)\}/g;
  let blockMatch;

  while ((blockMatch = blockPattern.exec(cmapBody)) !== null) {
    const block = blockMatch[1];

    const rangeStartM = block.match(/\.range_start\s*=\s*(\d+)/);
    const rangeLengthM = block.match(/\.range_length\s*=\s*(\d+)/);
    const glyphIdStartM = block.match(/\.glyph_id_start\s*=\s*(\d+)/);
    const typeM = block.match(/\.type\s*=\s*(LV_FONT_FMT_TXT_CMAP_\w+)/);
    const unicodeListM = block.match(/\.unicode_list\s*=\s*(\w+)/);
    const ofsListM = block.match(/\.glyph_id_ofs_list\s*=\s*(\w+)/);

    if (!rangeStartM || !rangeLengthM || !glyphIdStartM || !typeM) continue;

    let unicodeList: number[] | null = null;
    if (unicodeListM && unicodeListM[1] !== 'NULL') {
      unicodeList = namedArrays.get(unicodeListM[1]) ?? null;
    }

    let glyphIdOfsList: number[] | null = null;
    if (ofsListM && ofsListM[1] !== 'NULL') {
      glyphIdOfsList = namedArrays.get(ofsListM[1]) ?? null;
    }

    cmaps.push({
      rangeStart: parseInt(rangeStartM[1], 10),
      rangeLength: parseInt(rangeLengthM[1], 10),
      glyphIdStart: parseInt(glyphIdStartM[1], 10),
      type: parseCmapType(typeM[1]),
      unicodeList,
      glyphIdOfsList,
    });
  }

  return cmaps;
}

/**
 * Parses the public font variable to extract line_height, base_line, name, and fallback.
 */
function parseFontVariable(source: string): {
  name: string;
  lineHeight: number;
  baseLine: number;
  fallbackFont: string | null;
} {
  const nameMatch = source.match(/const\s+lv_font_t\s+(\w+)\s*=/);
  if (!nameMatch) throw new ParseError('Public font variable not found', 'font_variable');

  const lineHeightMatch = source.match(/\.line_height\s*=\s*(\d+)/);
  const baseLineMatch = source.match(/\.base_line\s*=\s*(\d+)/);
  const fallbackMatch = source.match(/\.fallback\s*=\s*&?(\w+)/);

  return {
    name: nameMatch[1],
    lineHeight: lineHeightMatch ? parseInt(lineHeightMatch[1], 10) : 0,
    baseLine: baseLineMatch ? parseInt(baseLineMatch[1], 10) : 0,
    fallbackFont: fallbackMatch && fallbackMatch[1] !== 'NULL' ? fallbackMatch[1] : null,
  };
}

/**
 * Parses an LVGL font .c file and produces a FontData object.
 * @param source - The complete C file content as a string.
 * @returns The parsed FontData.
 * @throws ParseError if the file cannot be parsed.
 */
export function parseLvglFont(source: string): FontData {
  const header = parseHeader(source);
  parseFontGuard(source); // Validates font guard is present
  const bitmapEntries = parseGlyphBitmaps(source);
  const descriptors = parseGlyphDescriptors(source);
  const cmaps = parseCmaps(source);
  const fontVar = parseFontVariable(source);

  // Merge bitmap entries with descriptors
  if (bitmapEntries.length !== descriptors.length) {
    throw new ParseError(
      `Glyph count mismatch: ${bitmapEntries.length} bitmap entries vs ${descriptors.length} descriptors`,
      'merge'
    );
  }

  const glyphs: Glyph[] = bitmapEntries.map((entry, i) => {
    const desc = descriptors[i];
    const bitmap = decodeBitmap(entry.bytes, desc.boxW, desc.boxH);

    return {
      unicode: entry.unicode,
      char: entry.char,
      advanceWidth: desc.advW,
      boxWidth: desc.boxW,
      boxHeight: desc.boxH,
      offsetX: desc.ofsX,
      offsetY: desc.ofsY,
      bitmap,
    };
  });

  return {
    name: fontVar.name,
    size: header.size,
    bpp: header.bpp,
    lineHeight: fontVar.lineHeight,
    baseLine: fontVar.baseLine,
    glyphs,
    cmaps,
    headerComment: header.headerComment,
    fallbackFont: fontVar.fallbackFont,
    opts: header.opts,
  };
}
