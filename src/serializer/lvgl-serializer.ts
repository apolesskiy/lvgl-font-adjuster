import { FontData, Glyph, CmapRange, CmapType } from '../model/font-model.js';

/**
 * Encodes a glyph's boolean[][] bitmap into continuously-packed bytes (MSB-first).
 * Pixel (row, col) maps to bit index (row * boxWidth + col) in a flat bit stream.
 * No per-row byte alignment.
 */
export function encodeBitmap(bitmap: boolean[][], boxWidth: number, boxHeight: number): number[] {
  const totalBits = boxWidth * boxHeight;
  const totalBytes = Math.ceil(totalBits / 8);
  const bytes = new Array<number>(totalBytes).fill(0);

  for (let row = 0; row < boxHeight; row++) {
    for (let col = 0; col < boxWidth; col++) {
      if (row < bitmap.length && col < bitmap[row].length && bitmap[row][col]) {
        const bitIndex = row * boxWidth + col;
        const byteIndex = Math.floor(bitIndex / 8);
        const bitPos = 7 - (bitIndex % 8);
        bytes[byteIndex] |= (1 << bitPos);
      }
    }
  }

  return bytes;
}

/**
 * Formats a hex byte as "0xNN".
 */
function formatHex(value: number): string {
  return '0x' + value.toString(16).padStart(1, '0');
}

/**
 * Escapes a character for use in a C comment.
 */
function escapeChar(ch: string): string {
  if (ch === '\\') return '\\\\';
  if (ch === '"') return '\\"';
  return ch;
}

/**
 * Returns the Unicode label for a code point (e.g. "U+0041").
 */
function unicodeLabel(codePoint: number): string {
  return 'U+' + codePoint.toString(16).toUpperCase().padStart(4, '0');
}

/**
 * Generates the glyph_bitmap[] array section.
 */
function serializeBitmapArray(glyphs: Glyph[]): string {
  const lines: string[] = [];
  lines.push('/*Store the image of the glyphs*/');
  lines.push('static LV_ATTRIBUTE_LARGE_CONST const uint8_t glyph_bitmap[] = {');

  for (let i = 0; i < glyphs.length; i++) {
    const g = glyphs[i];
    const bytes = encodeBitmap(g.bitmap, g.boxWidth, g.boxHeight);
    const hexVals = bytes.map(formatHex).join(', ');
    const comment = `    /* ${unicodeLabel(g.unicode)} "${escapeChar(g.char)}" */`;
    lines.push(comment);

    if (bytes.length > 0) {
      lines.push(`    ${hexVals}${i < glyphs.length - 1 ? ',' : ''}`);
    } else {
      lines.push(`    0x0${i < glyphs.length - 1 ? ',' : ''}`);
    }

    if (i < glyphs.length - 1) lines.push('');
  }

  lines.push('};');
  return lines.join('\n');
}

/**
 * Generates the glyph_dsc[] array section.
 */
function serializeGlyphDescriptors(glyphs: Glyph[]): string {
  const lines: string[] = [];
  lines.push('/*---------------------');
  lines.push(' *  GLYPH DESCRIPTION');
  lines.push(' *--------------------*/');
  lines.push('');
  lines.push('static const lv_font_fmt_txt_glyph_dsc_t glyph_dsc[] = {');
  lines.push('    {.bitmap_index = 0, .adv_w = 0, .box_w = 0, .box_h = 0, .ofs_x = 0, .ofs_y = 0} /* id = 0 reserved */,');

  // Pre-compute byte sizes for each glyph (min 1 byte for empty glyphs due to 0x0 placeholder)
  const byteSizes = glyphs.map(g => {
    const bytes = encodeBitmap(g.bitmap, g.boxWidth, g.boxHeight);
    return bytes.length > 0 ? bytes.length : 1;
  });

  let bitmapIndex = 0;

  for (let i = 0; i < glyphs.length; i++) {
    const g = glyphs[i];
    const comma = i < glyphs.length - 1 ? ',' : '';
    lines.push(
      `    {.bitmap_index = ${bitmapIndex}, .adv_w = ${g.advanceWidth}, .box_w = ${g.boxWidth}, .box_h = ${g.boxHeight}, .ofs_x = ${g.offsetX}, .ofs_y = ${g.offsetY}}${comma}`
    );
    bitmapIndex += byteSizes[i];
  }

  lines.push('};');
  return lines.join('\n');
}

/**
 * Maps CmapType enum to C enum string.
 */
function cmapTypeToC(type: CmapType): string {
  return type;
}

/**
 * Generates named arrays needed by cmaps (unicode lists, glyph offset lists).
 */
function serializeNamedArrays(cmaps: CmapRange[], cmapStartIdx: number): string {
  const lines: string[] = [];

  for (let i = 0; i < cmaps.length; i++) {
    const cmap = cmaps[i];
    const idx = cmapStartIdx + i;

    if (cmap.unicodeList) {
      lines.push(`static const uint16_t unicode_list_${idx}[] = {`);
      const hexVals = cmap.unicodeList.map(v => '0x' + v.toString(16));
      // Group into rows of 8
      for (let j = 0; j < hexVals.length; j += 8) {
        const row = hexVals.slice(j, j + 8).join(', ');
        const comma = j + 8 < hexVals.length ? ',' : '';
        lines.push(`    ${row}${comma}`);
      }
      lines.push('};');
      lines.push('');
    }

    if (cmap.glyphIdOfsList) {
      lines.push(`static const uint8_t glyph_id_ofs_list_${idx}[] = {`);
      const vals = cmap.glyphIdOfsList.map(v => v.toString());
      for (let j = 0; j < vals.length; j += 8) {
        const row = vals.slice(j, j + 8).join(', ');
        const comma = j + 8 < vals.length ? ',' : '';
        lines.push(`    ${row}${comma}`);
      }
      lines.push('};');
      lines.push('');
    }
  }

  return lines.join('\n');
}

/**
 * Generates the cmaps[] array section.
 */
function serializeCmaps(cmaps: CmapRange[]): string {
  const lines: string[] = [];
  lines.push('/*---------------------');
  lines.push(' *  CHARACTER MAPPING');
  lines.push(' *--------------------*/');
  lines.push('');

  const namedArraysStr = serializeNamedArrays(cmaps, 0);
  if (namedArraysStr.trim()) {
    lines.push(namedArraysStr);
  }

  lines.push('/*Collect the unicode lists and glyph_id offsets*/');
  lines.push('static const lv_font_fmt_txt_cmap_t cmaps[] =');
  lines.push('{');

  for (let i = 0; i < cmaps.length; i++) {
    const cmap = cmaps[i];
    const unicodeListRef = cmap.unicodeList ? `unicode_list_${i}` : 'NULL';
    const ofsListRef = cmap.glyphIdOfsList ? `glyph_id_ofs_list_${i}` : 'NULL';
    const listLength = cmap.unicodeList?.length ?? cmap.glyphIdOfsList?.length ?? 0;

    const comma = i < cmaps.length - 1 ? ',' : '';
    lines.push('    {');
    lines.push(`        .range_start = ${cmap.rangeStart}, .range_length = ${cmap.rangeLength}, .glyph_id_start = ${cmap.glyphIdStart},`);
    lines.push(`        .unicode_list = ${unicodeListRef}, .glyph_id_ofs_list = ${ofsListRef}, .list_length = ${listLength}, .type = ${cmapTypeToC(cmap.type)}`);
    lines.push(`    }${comma}`);
  }

  lines.push('};');
  return lines.join('\n');
}

/**
 * Generates the font descriptor section.
 */
function serializeFontDescriptor(font: FontData): string {
  const lines: string[] = [];
  lines.push('');
  lines.push('');
  lines.push('/*--------------------');
  lines.push(' *  ALL CUSTOM DATA');
  lines.push(' *--------------------*/');
  lines.push('');
  lines.push('#if LVGL_VERSION_MAJOR == 8');
  lines.push('/*Store all the custom data of the font*/');
  lines.push('static  lv_font_fmt_txt_glyph_cache_t cache;');
  lines.push('#endif');
  lines.push('');
  lines.push('#if LVGL_VERSION_MAJOR >= 8');
  lines.push('static const lv_font_fmt_txt_dsc_t font_dsc = {');
  lines.push('#else');
  lines.push('static lv_font_fmt_txt_dsc_t font_dsc = {');
  lines.push('#endif');
  lines.push('    .glyph_bitmap = glyph_bitmap,');
  lines.push('    .glyph_dsc = glyph_dsc,');
  lines.push('    .cmaps = cmaps,');
  lines.push('    .kern_dsc = NULL,');
  lines.push('    .kern_scale = 0,');
  lines.push(`    .cmap_num = ${font.cmaps.length},`);
  lines.push(`    .bpp = ${font.bpp},`);
  lines.push('    .kern_classes = 0,');
  lines.push('    .bitmap_format = 0,');
  lines.push('#if LVGL_VERSION_MAJOR == 8');
  lines.push('    .cache = &cache');
  lines.push('#endif');
  lines.push('');
  lines.push('};');
  return lines.join('\n');
}

/**
 * Generates the public font variable section.
 */
function serializePublicFont(font: FontData, guardName: string): string {
  const lines: string[] = [];

  if (font.fallbackFont) {
    lines.push('');
    lines.push(`extern const lv_font_t ${font.fallbackFont};`);
  }

  lines.push('');
  lines.push('');
  lines.push('/*-----------------');
  lines.push(' *  PUBLIC FONT');
  lines.push(' *----------------*/');
  lines.push('');
  lines.push('/*Initialize a public general font descriptor*/');
  lines.push('#if LVGL_VERSION_MAJOR >= 8');
  lines.push(`const lv_font_t ${font.name} = {`);
  lines.push('#else');
  lines.push(`lv_font_t ${font.name} = {`);
  lines.push('#endif');
  lines.push('    .get_glyph_dsc = lv_font_get_glyph_dsc_fmt_txt,    /*Function pointer to get glyph\'s data*/');
  lines.push('    .get_glyph_bitmap = lv_font_get_bitmap_fmt_txt,    /*Function pointer to get glyph\'s bitmap*/');
  lines.push(`    .line_height = ${font.lineHeight},          /*The maximum line height required by the font*/`);
  lines.push(`    .base_line = ${font.baseLine},             /*Baseline measured from the bottom of the line*/`);
  lines.push('#if !(LVGL_VERSION_MAJOR == 6 && LVGL_VERSION_MINOR == 0)');
  lines.push('    .subpx = LV_FONT_SUBPX_NONE,');
  lines.push('#endif');
  lines.push('#if LV_VERSION_CHECK(7, 4, 0) || LVGL_VERSION_MAJOR >= 8');
  lines.push('    .underline_position = 0,');
  lines.push('    .underline_thickness = 0,');
  lines.push('#endif');
  lines.push('    .static_bitmap = 0,');
  lines.push('    .dsc = &font_dsc,          /*The custom font data. Will be accessed by `get_glyph_bitmap/dsc` */');
  lines.push('#if LV_VERSION_CHECK(8, 2, 0) || LVGL_VERSION_MAJOR >= 9');

  if (font.fallbackFont) {
    lines.push(`    .fallback = &${font.fallbackFont},`);
  } else {
    lines.push('    .fallback = NULL,');
  }

  lines.push('#endif');
  lines.push('    .user_data = NULL,');
  lines.push('};');
  lines.push('');
  lines.push('');
  lines.push('');
  lines.push(`#endif /*#if ${guardName}*/`);
  return lines.join('\n');
}

/**
 * Serializes a FontData object back into a valid LVGL font .c file string.
 * @param font - The font data to serialize.
 * @returns The complete C file content.
 */
export function serializeLvglFont(font: FontData): string {
  const guardName = font.name.toUpperCase();

  const sections: string[] = [];

  // Header comment
  sections.push(font.headerComment);
  sections.push('');

  // Include guards
  sections.push('#ifdef __has_include');
  sections.push('    #if __has_include("lvgl.h")');
  sections.push('        #ifndef LV_LVGL_H_INCLUDE_SIMPLE');
  sections.push('            #define LV_LVGL_H_INCLUDE_SIMPLE');
  sections.push('        #endif');
  sections.push('    #endif');
  sections.push('#endif');
  sections.push('');
  sections.push('#ifdef LV_LVGL_H_INCLUDE_SIMPLE');
  sections.push('    #include "lvgl.h"');
  sections.push('#else');
  sections.push('    #include "lvgl/lvgl.h"');
  sections.push('#endif');
  sections.push('');
  sections.push('');
  sections.push('');
  sections.push(`#ifndef ${guardName}`);
  sections.push(`#define ${guardName} 1`);
  sections.push('#endif');
  sections.push('');
  sections.push(`#if ${guardName}`);
  sections.push('');
  sections.push('/*-----------------');
  sections.push(' *    BITMAPS');
  sections.push(' *----------------*/');
  sections.push('');

  // Bitmap array
  sections.push(serializeBitmapArray(font.glyphs));
  sections.push('');
  sections.push('');

  // Glyph descriptors
  sections.push(serializeGlyphDescriptors(font.glyphs));
  sections.push('');

  // Character mapping
  sections.push(serializeCmaps(font.cmaps));

  // Font descriptor
  sections.push(serializeFontDescriptor(font));

  // Public font variable
  sections.push(serializePublicFont(font, guardName));
  sections.push('');

  return sections.join('\n');
}
