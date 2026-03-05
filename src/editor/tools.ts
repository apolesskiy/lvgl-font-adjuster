import { Glyph, FontData, createEmptyBitmap } from '../model/font-model.js';

/**
 * Toggles a pixel at the given position.
 */
export function togglePixel(glyph: Glyph, row: number, col: number): void {
  if (row < 0 || row >= glyph.boxHeight || col < 0 || col >= glyph.boxWidth) return;
  glyph.bitmap[row][col] = !glyph.bitmap[row][col];
}

/**
 * Sets a pixel to a specific value.
 */
export function setPixel(glyph: Glyph, row: number, col: number, value: boolean): void {
  if (row < 0 || row >= glyph.boxHeight || col < 0 || col >= glyph.boxWidth) return;
  glyph.bitmap[row][col] = value;
}

/**
 * Adjusts a glyph's offset by the given delta.
 */
export function moveOffset(glyph: Glyph, dx: number, dy: number): void {
  glyph.offsetX += dx;
  glyph.offsetY += dy;
}

/**
 * Resizes a single glyph to newBoxWidth × newBoxHeight, anchored at top-left.
 * New space is added/removed from the right and bottom edges.
 * Returns without changes if new dimensions are less than 1.
 */
export function resizeGlyph(glyph: Glyph, newBoxWidth: number, newBoxHeight: number): void {
  if (newBoxWidth < 1 || newBoxHeight < 1) return;

  const oldBitmap = glyph.bitmap;
  const newBitmap = createEmptyBitmap(newBoxWidth, newBoxHeight);

  const copyRows = Math.min(glyph.boxHeight, newBoxHeight);
  const copyCols = Math.min(glyph.boxWidth, newBoxWidth);

  for (let r = 0; r < copyRows; r++) {
    for (let c = 0; c < copyCols; c++) {
      newBitmap[r][c] = oldBitmap[r]?.[c] ?? false;
    }
  }

  glyph.bitmap = newBitmap;
  glyph.boxWidth = newBoxWidth;
  glyph.boxHeight = newBoxHeight;
}

/**
 * Resizes all glyphs in a font to newBoxWidth × newBoxHeight, centering existing data.
 */
export function resizeFont(font: FontData, newBoxWidth: number, newBoxHeight: number): void {
  for (const glyph of font.glyphs) {
    resizeGlyph(glyph, newBoxWidth, newBoxHeight);
  }
}

/**
 * Resizes all glyphs in a font by a delta, preserving individual size differences.
 * Each glyph's dimensions are adjusted by (dw, dh).
 * Glyphs whose resulting dimensions would be less than 1 are clamped to 1.
 */
export function resizeFontDelta(font: FontData, dw: number, dh: number): void {
  for (const glyph of font.glyphs) {
    const newW = Math.max(1, glyph.boxWidth + dw);
    const newH = Math.max(1, glyph.boxHeight + dh);
    resizeGlyph(glyph, newW, newH);
  }
}

/**
 * Extracts a rectangular selection from a glyph's bitmap.
 */
export function boxSelect(
  glyph: Glyph,
  r1: number, c1: number,
  r2: number, c2: number,
): boolean[][] {
  const minR = Math.max(0, Math.min(r1, r2));
  const maxR = Math.min(glyph.boxHeight - 1, Math.max(r1, r2));
  const minC = Math.max(0, Math.min(c1, c2));
  const maxC = Math.min(glyph.boxWidth - 1, Math.max(c1, c2));

  const result: boolean[][] = [];
  for (let r = minR; r <= maxR; r++) {
    const row: boolean[] = [];
    for (let c = minC; c <= maxC; c++) {
      row.push(glyph.bitmap[r]?.[c] ?? false);
    }
    result.push(row);
  }

  return result;
}

/**
 * Pastes a rectangular block of pixels onto a glyph's bitmap at the given position.
 */
export function pastePixels(
  glyph: Glyph,
  pixels: boolean[][],
  startRow: number,
  startCol: number,
): void {
  for (let r = 0; r < pixels.length; r++) {
    for (let c = 0; c < pixels[r].length; c++) {
      const tr = startRow + r;
      const tc = startCol + c;
      if (tr >= 0 && tr < glyph.boxHeight && tc >= 0 && tc < glyph.boxWidth) {
        glyph.bitmap[tr][tc] = pixels[r][c];
      }
    }
  }
}

/**
 * Moves selected pixels within a glyph by (dr, dc), clearing the source area.
 */
export function movePixels(
  glyph: Glyph,
  selection: { r1: number; c1: number; r2: number; c2: number },
  dr: number,
  dc: number,
): void {
  const minR = Math.min(selection.r1, selection.r2);
  const maxR = Math.max(selection.r1, selection.r2);
  const minC = Math.min(selection.c1, selection.c2);
  const maxC = Math.max(selection.c1, selection.c2);

  // Extract pixels
  const pixels = boxSelect(glyph, minR, minC, maxR, maxC);

  // Clear source area
  for (let r = minR; r <= maxR; r++) {
    for (let c = minC; c <= maxC; c++) {
      if (r >= 0 && r < glyph.boxHeight && c >= 0 && c < glyph.boxWidth) {
        glyph.bitmap[r][c] = false;
      }
    }
  }

  // Paste at new position
  pastePixels(glyph, pixels, minR + dr, minC + dc);
}
