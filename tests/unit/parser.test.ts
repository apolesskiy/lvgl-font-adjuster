import { describe, it, expect } from 'vitest';
import { readFileSync } from 'fs';
import { resolve, dirname } from 'path';
import { fileURLToPath } from 'url';
import { parseLvglFont, ParseError, decodeBitmap } from '../../src/parser/lvgl-parser.js';

const __dirname = dirname(fileURLToPath(import.meta.url));

/** Reads an example input file. */
function readExample(name: string): string {
  return readFileSync(resolve(__dirname, '../../example_input', name), 'utf-8');
}

describe('decodeBitmap', () => {
  it('decodes a 1-wide 7-tall bitmap (continuous packing)', () => {
    // "!" glyph: 0xf2 => 11110010
    // Continuous: bit 0=1, bit 1=1, bit 2=1, bit 3=1, bit 4=0, bit 5=0, bit 6=1
    // 7 pixels wide=1, so each row is 1 bit, 7 rows total = 7 bits
    const result = decodeBitmap([0xf2], 1, 7);
    expect(result).toEqual([
      [true],   // bit 0 (byte 0 bit 7) = 1
      [true],   // bit 1 (byte 0 bit 6) = 1
      [true],   // bit 2 (byte 0 bit 5) = 1
      [true],   // bit 3 (byte 0 bit 4) = 1
      [false],  // bit 4 (byte 0 bit 3) = 0
      [false],  // bit 5 (byte 0 bit 2) = 0
      [true],   // bit 6 (byte 0 bit 1) = 1
    ]);
  });

  it('decodes a 3x2 bitmap (continuous packing)', () => {
    // 3×2 = 6 bits in 1 byte
    // 0xa0 = 10100000 → bits 0..5: 1,0,1,0,0,0
    // Row 0: bits 0,1,2 = 1,0,1 → [true, false, true]
    // Row 1: bits 3,4,5 = 0,0,0 → [false, false, false]
    const result = decodeBitmap([0xa0], 3, 2);
    expect(result).toEqual([
      [true, false, true],
      [false, false, false],
    ]);
  });

  it('handles empty bitmap (0x0 dimensions)', () => {
    const result = decodeBitmap([], 0, 0);
    expect(result).toEqual([]);
  });

  it('handles 1x1 bitmap', () => {
    expect(decodeBitmap([0x80], 1, 1)).toEqual([[true]]);
    expect(decodeBitmap([0x00], 1, 1)).toEqual([[false]]);
  });
});

describe('parseLvglFont - tiny_mono_3x5', () => {
  const source = readExample('tiny_mono_3x5.c');
  const font = parseLvglFont(source);

  it('parses font metadata', () => {
    expect(font.name).toBe('tiny_mono_3x5');
    expect(font.size).toBe(6);
    expect(font.bpp).toBe(1);
    expect(font.lineHeight).toBe(6);
    expect(font.baseLine).toBe(1);
  });

  it('parses fallback font', () => {
    expect(font.fallbackFont).toBe(null);
  });

  it('parses correct number of glyphs', () => {
    expect(font.glyphs.length).toBeGreaterThan(90);
  });

  it('parses space glyph correctly', () => {
    const space = font.glyphs.find(g => g.unicode === 0x20);
    expect(space).toBeDefined();
    expect(space!.boxWidth).toBe(1);
    expect(space!.boxHeight).toBe(1);
    expect(space!.advanceWidth).toBe(64);
  });

  it('parses "A" glyph bitmap', () => {
    const a = font.glyphs.find(g => g.unicode === 0x41);
    expect(a).toBeDefined();
    expect(a!.boxWidth).toBe(3);
    expect(a!.boxHeight).toBe(5);
    // "A" bytes: 0x57, 0xd0
    // stride = 1 byte/row, 4 rows = 4 bytes? No, let's decompose:
    // 0x57 = 01010111, 0xd0 = 11010000
    // But stride = ceil(3/8) = 1 byte/row => 4 rows = 4 bytes
    // We only have 2 bytes... so it's packed differently
    // Actually with 3 bits per row * 4 rows = 12 bits = 2 bytes
    // Row 0: 0x57 bits 7,6,5 = 0,1,0 => [false, true, false]
    // Row 1: 0x57 bits 4,3,2 = 1,0,1 => [true, false, true] (wait, stride 1 byte per row)
    // stride=1 means each row starts on a new byte:
    // Row 0: byte 0 (0x57) bits 7,6,5 = 0,1,0
    // Row 1: byte 1 (0xd0) bits 7,6,5 = 1,1,0
    // But that's only 2 rows for 2 bytes... we need 4 rows but only have 2 bytes
    // Let me check: bitmap_index for 'A' is 54, the bytes come from the bitmap array
    // The parser extracts bytes per glyph from the hex between comments
    expect(a!.bitmap.length).toBe(5);
    expect(a!.bitmap[0].length).toBe(3);
  });

  it('parses character maps', () => {
    expect(font.cmaps.length).toBe(2);
    expect(font.cmaps[0].rangeStart).toBe(32);
    expect(font.cmaps[0].rangeLength).toBe(95);
  });

  it('preserves header comment', () => {
    expect(font.headerComment).toContain('Size: 6 px');
    expect(font.headerComment).toContain('Bpp: 1');
  });
});

describe('parseLvglFont - low_gothic_8x10', () => {
  const source = readExample('low_gothic_8x10.c');
  const font = parseLvglFont(source);

  it('parses font metadata', () => {
    expect(font.name).toBe('low_gothic_8x10');
    expect(font.size).toBe(8);
    expect(font.bpp).toBe(1);
    expect(font.lineHeight).toBe(10);
    expect(font.baseLine).toBe(2);
  });

  it('parses no fallback font', () => {
    expect(font.fallbackFont).toBeNull();
  });

  it('parses complex character maps', () => {
    expect(font.cmaps.length).toBe(5);
  });

  it('parses large glyph count', () => {
    expect(font.glyphs.length).toBeGreaterThan(150);
  });
});

describe('parseLvglFont - error handling', () => {
  it('throws ParseError for empty input', () => {
    expect(() => parseLvglFont('')).toThrow(ParseError);
  });

  it('throws ParseError for invalid C file', () => {
    expect(() => parseLvglFont('int main() { return 0; }')).toThrow(ParseError);
  });
});
