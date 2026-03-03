import { describe, it, expect } from 'vitest';
import {
  togglePixel,
  setPixel,
  moveOffset,
  resizeFont,
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
    // The center pixel should still be set (shifted to new center)
    expect(font.glyphs[0].bitmap[2][2]).toBe(true);
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
