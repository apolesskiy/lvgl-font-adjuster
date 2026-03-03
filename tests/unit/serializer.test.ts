import { describe, it, expect } from 'vitest';
import { encodeBitmap } from '../../src/serializer/lvgl-serializer.js';
import { FontData, CmapType } from '../../src/model/font-model.js';
import { serializeLvglFont } from '../../src/serializer/lvgl-serializer.js';

describe('encodeBitmap', () => {
  it('encodes a 1x1 true pixel', () => {
    expect(encodeBitmap([[true]], 1, 1)).toEqual([0x80]);
  });

  it('encodes a 1x1 false pixel', () => {
    expect(encodeBitmap([[false]], 1, 1)).toEqual([0x00]);
  });

  it('encodes a 3x2 bitmap (continuous packing)', () => {
    const bitmap = [
      [true, false, true],
      [false, true, true],
    ];
    const bytes = encodeBitmap(bitmap, 3, 2);
    // 6 bits total in 1 byte
    // bit 0=1, bit 1=0, bit 2=1, bit 3=0, bit 4=1, bit 5=1
    // byte: 10101100 = 0xac
    expect(bytes).toEqual([0xac]);
  });

  it('encodes empty bitmap', () => {
    expect(encodeBitmap([], 0, 0)).toEqual([]);
  });

  it('encodes a wider bitmap (9 bits wide, 1 row)', () => {
    const bitmap = [
      [true, false, true, false, true, false, true, false, true],
    ];
    const bytes = encodeBitmap(bitmap, 9, 1);
    // 9 bits in 2 bytes (continuous)
    // bit 0-7: 10101010 = 0xaa
    // bit 8: 1 => 10000000 = 0x80
    expect(bytes).toEqual([0xaa, 0x80]);
  });
});

describe('serializeLvglFont', () => {
  it('produces valid C output for a minimal font', () => {
    const font: FontData = {
      name: 'test_font',
      size: 8,
      bpp: 1,
      lineHeight: 8,
      baseLine: 0,
      glyphs: [
        {
          unicode: 0x20,
          char: ' ',
          advanceWidth: 40,
          boxWidth: 1,
          boxHeight: 1,
          offsetX: 0,
          offsetY: 0,
          bitmap: [[false]],
        },
        {
          unicode: 0x41,
          char: 'A',
          advanceWidth: 80,
          boxWidth: 3,
          boxHeight: 3,
          offsetX: 0,
          offsetY: 0,
          bitmap: [
            [false, true, false],
            [true, false, true],
            [true, true, true],
          ],
        },
      ],
      cmaps: [
        {
          rangeStart: 32,
          rangeLength: 34,
          glyphIdStart: 1,
          type: CmapType.FORMAT0_TINY,
          unicodeList: null,
          glyphIdOfsList: null,
        },
      ],
      headerComment: '/*******************************************************************************\n * Size: 8 px\n * Bpp: 1\n * Opts: --bpp 1 --size 8\n *****************************************************************************/',
      fallbackFont: null,
      opts: '--bpp 1 --size 8',
    };

    const output = serializeLvglFont(font);

    expect(output).toContain('glyph_bitmap');
    expect(output).toContain('glyph_dsc');
    expect(output).toContain('cmaps');
    expect(output).toContain('test_font');
    expect(output).toContain('#if TEST_FONT');
    expect(output).toContain('.bpp = 1');
    expect(output).toContain('.line_height = 8');
    expect(output).toContain('fallback = NULL');
  });

  it('includes fallback font when specified', () => {
    const font: FontData = {
      name: 'fb_font',
      size: 5,
      bpp: 1,
      lineHeight: 5,
      baseLine: 1,
      glyphs: [{
        unicode: 0x20,
        char: ' ',
        advanceWidth: 40,
        boxWidth: 1,
        boxHeight: 1,
        offsetX: 0,
        offsetY: 0,
        bitmap: [[false]],
      }],
      cmaps: [{
        rangeStart: 32,
        rangeLength: 1,
        glyphIdStart: 1,
        type: CmapType.FORMAT0_TINY,
        unicodeList: null,
        glyphIdOfsList: null,
      }],
      headerComment: '/*******************************************************************************\n * Size: 5 px\n * Bpp: 1\n * Opts: --bpp 1\n *****************************************************************************/',
      fallbackFont: 'LV_FONT_UNSCII_8',
      opts: '--bpp 1',
    };

    const output = serializeLvglFont(font);
    expect(output).toContain('extern const lv_font_t LV_FONT_UNSCII_8');
    expect(output).toContain('.fallback = &LV_FONT_UNSCII_8');
  });
});
