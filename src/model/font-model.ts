/**
 * Enumeration of LVGL character map types.
 */
export enum CmapType {
  FORMAT0_TINY = 'LV_FONT_FMT_TXT_CMAP_FORMAT0_TINY',
  FORMAT0_FULL = 'LV_FONT_FMT_TXT_CMAP_FORMAT0_FULL',
  SPARSE_TINY = 'LV_FONT_FMT_TXT_CMAP_SPARSE_TINY',
}

/**
 * Represents a single glyph in the font.
 */
export interface Glyph {
  /** Unicode code point. */
  unicode: number;
  /** The character (for display). */
  char: string;
  /** Advance width (raw adv_w value). */
  advanceWidth: number;
  /** Bounding box width in pixels. */
  boxWidth: number;
  /** Bounding box height in pixels. */
  boxHeight: number;
  /** X offset. */
  offsetX: number;
  /** Y offset. */
  offsetY: number;
  /** 2D pixel grid, [row][col], true = pixel on. */
  bitmap: boolean[][];
}

/**
 * One entry in the character mapping table.
 */
export interface CmapRange {
  /** Starting Unicode code point. */
  rangeStart: number;
  /** Number of code points in range. */
  rangeLength: number;
  /** Starting glyph ID. */
  glyphIdStart: number;
  /** Map type. */
  type: CmapType;
  /** For sparse maps: unicode offset list. */
  unicodeList: number[] | null;
  /** For FORMAT0_FULL: glyph ID offset list. */
  glyphIdOfsList: number[] | null;
}

/**
 * Top-level container for a parsed LVGL font file.
 */
export interface FontData {
  /** Font variable name (e.g. "tiny_mono_3x5"). */
  name: string;
  /** Font size in px from header comment. */
  size: number;
  /** Bits per pixel (1 for initial scope). */
  bpp: number;
  /** Maximum line height. */
  lineHeight: number;
  /** Baseline measured from the bottom. */
  baseLine: number;
  /** Ordered array of parsed glyphs. */
  glyphs: Glyph[];
  /** Character mapping table. */
  cmaps: CmapRange[];
  /** Original header comment text to preserve. */
  headerComment: string;
  /** Fallback font reference or null. */
  fallbackFont: string | null;
  /** Original opts string from header comment. */
  opts: string;
}

/**
 * Creates a deep clone of a Glyph object.
 */
export function cloneGlyph(glyph: Glyph): Glyph {
  return {
    ...glyph,
    bitmap: glyph.bitmap.map(row => [...row]),
  };
}

/**
 * Creates a new empty bitmap of the given dimensions.
 */
export function createEmptyBitmap(width: number, height: number): boolean[][] {
  return Array.from({ length: height }, () => Array(width).fill(false) as boolean[]);
}

/**
 * Returns the Unicode label for a glyph (e.g. "U+0041").
 */
export function unicodeLabel(codePoint: number): string {
  return `U+${codePoint.toString(16).toUpperCase().padStart(4, '0')}`;
}
