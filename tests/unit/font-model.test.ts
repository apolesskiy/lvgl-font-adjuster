import { describe, it, expect } from 'vitest';
import {
  cloneGlyph,
  createEmptyBitmap,
  unicodeLabel,
  CmapType,
} from '../../src/model/font-model.js';
import type { Glyph } from '../../src/model/font-model.js';

describe('cloneGlyph', () => {
  it('creates a deep copy of a glyph', () => {
    const original: Glyph = {
      unicode: 0x41,
      char: 'A',
      advanceWidth: 80,
      boxWidth: 3,
      boxHeight: 2,
      offsetX: 0,
      offsetY: 0,
      bitmap: [
        [true, false, true],
        [false, true, false],
      ],
    };

    const clone = cloneGlyph(original);

    // Should be deeply equal
    expect(clone).toEqual(original);

    // Should not be the same reference
    expect(clone).not.toBe(original);
    expect(clone.bitmap).not.toBe(original.bitmap);
    expect(clone.bitmap[0]).not.toBe(original.bitmap[0]);

    // Modifying clone should not affect original
    clone.bitmap[0][0] = false;
    expect(original.bitmap[0][0]).toBe(true);
  });
});

describe('createEmptyBitmap', () => {
  it('creates a bitmap of the correct size', () => {
    const bitmap = createEmptyBitmap(4, 3);
    expect(bitmap.length).toBe(3);
    expect(bitmap[0].length).toBe(4);
  });

  it('initializes all pixels to false', () => {
    const bitmap = createEmptyBitmap(2, 2);
    expect(bitmap).toEqual([
      [false, false],
      [false, false],
    ]);
  });

  it('handles 0x0 dimensions', () => {
    const bitmap = createEmptyBitmap(0, 0);
    expect(bitmap).toEqual([]);
  });
});

describe('unicodeLabel', () => {
  it('formats ASCII code points', () => {
    expect(unicodeLabel(0x41)).toBe('U+0041');
  });

  it('formats low code points with padding', () => {
    expect(unicodeLabel(0x20)).toBe('U+0020');
  });

  it('formats higher code points', () => {
    expect(unicodeLabel(0x2122)).toBe('U+2122');
  });
});

describe('CmapType', () => {
  it('has expected values', () => {
    expect(CmapType.FORMAT0_TINY).toBe('LV_FONT_FMT_TXT_CMAP_FORMAT0_TINY');
    expect(CmapType.FORMAT0_FULL).toBe('LV_FONT_FMT_TXT_CMAP_FORMAT0_FULL');
    expect(CmapType.SPARSE_TINY).toBe('LV_FONT_FMT_TXT_CMAP_SPARSE_TINY');
  });
});
