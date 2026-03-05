import { describe, it, expect } from 'vitest';
import {
  togglePixel,
  setPixel,
  moveOffset,
  resizeGlyph,
  resizeFont,
  resizeFontDelta,
  boxSelect,
  pastePixels,
  movePixels,
} from '../../src/editor/tools.js';
import type { Glyph, FontData } from '../../src/model/font-model.js';

/** Creates a 3x3 test glyph with all pixels off. */
function makeGlyph3x3(): Glyph {
  return {
    unicode: 0x41,
    char: 'A',
    advanceWidth: 80,
    boxWidth: 3,
    boxHeight: 3,
    offsetX: 0,
    offsetY: 0,
    bitmap: [
      [false, false, false],
      [false, false, false],
      [false, false, false],
    ],
  };
}

describe('togglePixel', () => {
  it('toggles a pixel on', () => {
    const g = makeGlyph3x3();
    togglePixel(g, 1, 1);
    expect(g.bitmap[1][1]).toBe(true);
  });

  it('toggles a pixel off', () => {
    const g = makeGlyph3x3();
    g.bitmap[0][0] = true;
    togglePixel(g, 0, 0);
    expect(g.bitmap[0][0]).toBe(false);
  });

  it('ignores out-of-bounds coordinates', () => {
    const g = makeGlyph3x3();
    togglePixel(g, -1, 0);
    togglePixel(g, 0, -1);
    togglePixel(g, 3, 0);
    togglePixel(g, 0, 3);
    // All should remain false
    expect(g.bitmap.flat().every(v => !v)).toBe(true);
  });
});

describe('setPixel', () => {
  it('sets a pixel to true', () => {
    const g = makeGlyph3x3();
    setPixel(g, 2, 2, true);
    expect(g.bitmap[2][2]).toBe(true);
  });

  it('sets a pixel to false', () => {
    const g = makeGlyph3x3();
    g.bitmap[1][1] = true;
    setPixel(g, 1, 1, false);
    expect(g.bitmap[1][1]).toBe(false);
  });

  it('ignores out-of-bounds', () => {
    const g = makeGlyph3x3();
    setPixel(g, 5, 5, true);
    expect(g.bitmap.flat().every(v => !v)).toBe(true);
  });
});

describe('moveOffset', () => {
  it('adjusts offset by delta', () => {
    const g = makeGlyph3x3();
    moveOffset(g, 2, -1);
    expect(g.offsetX).toBe(2);
    expect(g.offsetY).toBe(-1);
  });

  it('accumulates multiple moves', () => {
    const g = makeGlyph3x3();
    moveOffset(g, 1, 1);
    moveOffset(g, -3, 2);
    expect(g.offsetX).toBe(-2);
    expect(g.offsetY).toBe(3);
  });
});

describe('resizeFont', () => {
  it('expands glyph dimensions', () => {
    const font: FontData = {
      name: 'test',
      size: 5,
      bpp: 1,
      lineHeight: 5,
      baseLine: 0,
      glyphs: [makeGlyph3x3()],
      cmaps: [],
      headerComment: '',
      fallbackFont: null,
      opts: '',
    };

    font.glyphs[0].bitmap[1][1] = true;
    resizeFont(font, 5, 5);

    expect(font.glyphs[0].boxWidth).toBe(5);
    expect(font.glyphs[0].boxHeight).toBe(5);
    // Pixel stays at same position (top-left anchored)
    expect(font.glyphs[0].bitmap[1][1]).toBe(true);
  });
});

describe('resizeGlyph', () => {
  it('expands a single glyph, anchored at top-left', () => {
    const g = makeGlyph3x3();
    g.bitmap[1][1] = true;
    resizeGlyph(g, 5, 5);

    expect(g.boxWidth).toBe(5);
    expect(g.boxHeight).toBe(5);
    expect(g.bitmap.length).toBe(5);
    expect(g.bitmap[0].length).toBe(5);
    // Pixel stays at (1,1) — top-left anchored
    expect(g.bitmap[1][1]).toBe(true);
    // New border pixels should be false
    expect(g.bitmap[3][3]).toBe(false);
    expect(g.bitmap[4][4]).toBe(false);
  });

  it('shrinks a single glyph, clipping right/bottom', () => {
    const g = makeGlyph3x3();
    g.bitmap[0][0] = true; // top-left — preserved
    g.bitmap[2][2] = true; // bottom-right — clipped
    resizeGlyph(g, 1, 1);

    expect(g.boxWidth).toBe(1);
    expect(g.boxHeight).toBe(1);
    // Top-left pixel preserved
    expect(g.bitmap[0][0]).toBe(true);
  });

  it('does nothing if new dimensions are less than 1', () => {
    const g = makeGlyph3x3();
    g.bitmap[1][1] = true;
    resizeGlyph(g, 0, 5);
    expect(g.boxWidth).toBe(3);
    expect(g.boxHeight).toBe(3);
    expect(g.bitmap[1][1]).toBe(true);

    resizeGlyph(g, 5, 0);
    expect(g.boxWidth).toBe(3);
    expect(g.boxHeight).toBe(3);
  });

  it('handles asymmetric resize (width only)', () => {
    const g = makeGlyph3x3();
    g.bitmap[0][0] = true;
    g.bitmap[0][2] = true;
    resizeGlyph(g, 5, 3);

    expect(g.boxWidth).toBe(5);
    expect(g.boxHeight).toBe(3);
    // Pixels stay in place (top-left anchored)
    expect(g.bitmap[0][0]).toBe(true);
    expect(g.bitmap[0][2]).toBe(true);
  });

  it('handles asymmetric resize (height only)', () => {
    const g = makeGlyph3x3();
    g.bitmap[0][1] = true;
    g.bitmap[2][1] = true;
    resizeGlyph(g, 3, 5);

    expect(g.boxWidth).toBe(3);
    expect(g.boxHeight).toBe(5);
    // Pixels stay in place (top-left anchored)
    expect(g.bitmap[0][1]).toBe(true);
    expect(g.bitmap[2][1]).toBe(true);
  });

  it('preserves all pixels when expanding', () => {
    const g = makeGlyph3x3();
    g.bitmap[0][0] = true;
    g.bitmap[0][1] = true;
    g.bitmap[0][2] = true;
    g.bitmap[1][0] = true;
    g.bitmap[2][2] = true;

    resizeGlyph(g, 7, 7);

    // All pixels stay at original positions
    expect(g.bitmap[0][0]).toBe(true);
    expect(g.bitmap[0][1]).toBe(true);
    expect(g.bitmap[0][2]).toBe(true);
    expect(g.bitmap[1][0]).toBe(true);
    expect(g.bitmap[2][2]).toBe(true);
  });

  it('add then remove round-trips to identical bitmap', () => {
    const g = makeGlyph3x3();
    g.bitmap[0][0] = true;
    g.bitmap[1][2] = true;
    g.bitmap[2][1] = true;
    const original = g.bitmap.map(row => [...row]);

    // Add 1 width, then remove 1 width
    resizeGlyph(g, 4, 3);
    resizeGlyph(g, 3, 3);
    expect(g.bitmap).toEqual(original);

    // Add 1 height, then remove 1 height
    resizeGlyph(g, 3, 4);
    resizeGlyph(g, 3, 3);
    expect(g.bitmap).toEqual(original);

    // Add both, then remove both
    resizeGlyph(g, 5, 5);
    resizeGlyph(g, 3, 3);
    expect(g.bitmap).toEqual(original);
  });
});

describe('resizeFontDelta', () => {
  function makeFont(...glyphs: Glyph[]): FontData {
    return {
      name: 'test',
      size: 5,
      bpp: 1,
      lineHeight: 5,
      baseLine: 0,
      glyphs,
      cmaps: [],
      headerComment: '',
      fallbackFont: null,
      opts: '',
    };
  }

  it('increases width of all glyphs by delta', () => {
    const g1 = makeGlyph3x3();
    const g2: Glyph = { ...makeGlyph3x3(), boxWidth: 5, boxHeight: 4, bitmap: Array.from({ length: 4 }, () => Array(5).fill(false) as boolean[]) };
    const font = makeFont(g1, g2);

    resizeFontDelta(font, 2, 0);

    expect(font.glyphs[0].boxWidth).toBe(5);
    expect(font.glyphs[0].boxHeight).toBe(3);
    expect(font.glyphs[1].boxWidth).toBe(7);
    expect(font.glyphs[1].boxHeight).toBe(4);
  });

  it('increases height of all glyphs by delta', () => {
    const g1 = makeGlyph3x3();
    const g2: Glyph = { ...makeGlyph3x3(), boxWidth: 5, boxHeight: 4, bitmap: Array.from({ length: 4 }, () => Array(5).fill(false) as boolean[]) };
    const font = makeFont(g1, g2);

    resizeFontDelta(font, 0, 3);

    expect(font.glyphs[0].boxWidth).toBe(3);
    expect(font.glyphs[0].boxHeight).toBe(6);
    expect(font.glyphs[1].boxWidth).toBe(5);
    expect(font.glyphs[1].boxHeight).toBe(7);
  });

  it('decreases dimensions with clamping at 1', () => {
    const g1 = makeGlyph3x3();
    const g2: Glyph = { ...makeGlyph3x3(), boxWidth: 2, boxHeight: 2, bitmap: [[false, false], [false, false]] };
    const font = makeFont(g1, g2);

    resizeFontDelta(font, -2, -2);

    expect(font.glyphs[0].boxWidth).toBe(1);
    expect(font.glyphs[0].boxHeight).toBe(1);
    // g2 would be 0x0 unclamped, but clamped to 1x1
    expect(font.glyphs[1].boxWidth).toBe(1);
    expect(font.glyphs[1].boxHeight).toBe(1);
  });

  it('preserves individual size differences', () => {
    const g1 = makeGlyph3x3(); // 3x3
    const g2: Glyph = { ...makeGlyph3x3(), boxWidth: 5, boxHeight: 7, bitmap: Array.from({ length: 7 }, () => Array(5).fill(false) as boolean[]) };
    const font = makeFont(g1, g2);

    resizeFontDelta(font, 1, 1);

    // g1: 3+1=4, 3+1=4
    expect(font.glyphs[0].boxWidth).toBe(4);
    expect(font.glyphs[0].boxHeight).toBe(4);
    // g2: 5+1=6, 7+1=8
    expect(font.glyphs[1].boxWidth).toBe(6);
    expect(font.glyphs[1].boxHeight).toBe(8);
    // Difference preserved: g2 is still 2 wider and 4 taller than g1
    expect(font.glyphs[1].boxWidth - font.glyphs[0].boxWidth).toBe(2);
    expect(font.glyphs[1].boxHeight - font.glyphs[0].boxHeight).toBe(4);
  });

  it('preserves pixel data when resizing by delta', () => {
    const g = makeGlyph3x3();
    g.bitmap[1][1] = true;
    const font = makeFont(g);

    resizeFontDelta(font, 2, 2);

    // Pixel stays at (1,1) — top-left anchored
    expect(font.glyphs[0].bitmap[1][1]).toBe(true);
  });

  it('add then remove delta round-trips to identical bitmap', () => {
    const g = makeGlyph3x3();
    g.bitmap[0][0] = true;
    g.bitmap[1][2] = true;
    const original = g.bitmap.map(row => [...row]);
    const font = makeFont(g);

    resizeFontDelta(font, 1, 1);
    resizeFontDelta(font, -1, -1);

    expect(font.glyphs[0].bitmap).toEqual(original);
  });
});

describe('boxSelect', () => {
  it('extracts a rectangular selection', () => {
    const g = makeGlyph3x3();
    g.bitmap[0][0] = true;
    g.bitmap[0][1] = true;
    g.bitmap[1][0] = true;

    const selected = boxSelect(g, 0, 0, 1, 1);
    expect(selected).toEqual([
      [true, true],
      [true, false],
    ]);
  });

  it('handles reversed coordinates', () => {
    const g = makeGlyph3x3();
    g.bitmap[2][2] = true;

    const selected = boxSelect(g, 2, 2, 1, 1);
    expect(selected).toEqual([
      [false, false],
      [false, true],
    ]);
  });
});

describe('pastePixels', () => {
  it('writes pixels at the given position', () => {
    const g = makeGlyph3x3();
    const pixels = [[true, true], [true, false]];
    pastePixels(g, pixels, 1, 1);

    expect(g.bitmap[1][1]).toBe(true);
    expect(g.bitmap[1][2]).toBe(true);
    expect(g.bitmap[2][1]).toBe(true);
    expect(g.bitmap[2][2]).toBe(false);
  });

  it('clips to glyph bounds', () => {
    const g = makeGlyph3x3();
    const pixels = [[true, true, true], [true, true, true]];
    pastePixels(g, pixels, 2, 2);

    // Only (2,2) should be set
    expect(g.bitmap[2][2]).toBe(true);
    expect(g.bitmap[2][0]).toBe(false);
  });
});

describe('movePixels', () => {
  it('moves selected pixels by delta', () => {
    const g = makeGlyph3x3();
    g.bitmap[0][0] = true;
    g.bitmap[0][1] = true;

    movePixels(g, { r1: 0, c1: 0, r2: 0, c2: 1 }, 1, 1);

    // Original positions cleared
    expect(g.bitmap[0][0]).toBe(false);
    expect(g.bitmap[0][1]).toBe(false);
    // New positions set
    expect(g.bitmap[1][1]).toBe(true);
    expect(g.bitmap[1][2]).toBe(true);
  });
});
