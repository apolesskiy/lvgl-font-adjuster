import { describe, it, expect } from 'vitest';
import { readFileSync } from 'fs';
import { resolve, dirname } from 'path';
import { fileURLToPath } from 'url';
import { parseLvglFont } from '../../src/parser/lvgl-parser.js';
import { serializeLvglFont } from '../../src/serializer/lvgl-serializer.js';

const __dirname = dirname(fileURLToPath(import.meta.url));

/** Reads an example input file. */
function readExample(name: string): string {
  return readFileSync(resolve(__dirname, '../../example_input', name), 'utf-8');
}

describe('Parse-Serialize Roundtrip', () => {
  it('roundtrips tiny_mono_3x5 preserving glyph data', () => {
    const source = readExample('tiny_mono_3x5.c');
    const font1 = parseLvglFont(source);
    const serialized = serializeLvglFont(font1);
    const font2 = parseLvglFont(serialized);

    expect(font2.name).toBe(font1.name);
    expect(font2.size).toBe(font1.size);
    expect(font2.bpp).toBe(font1.bpp);
    expect(font2.lineHeight).toBe(font1.lineHeight);
    expect(font2.baseLine).toBe(font1.baseLine);
    expect(font2.fallbackFont).toBe(font1.fallbackFont);
    expect(font2.glyphs.length).toBe(font1.glyphs.length);

    for (let i = 0; i < font1.glyphs.length; i++) {
      const g1 = font1.glyphs[i];
      const g2 = font2.glyphs[i];
      expect(g2.unicode).toBe(g1.unicode);
      expect(g2.boxWidth).toBe(g1.boxWidth);
      expect(g2.boxHeight).toBe(g1.boxHeight);
      expect(g2.advanceWidth).toBe(g1.advanceWidth);
      expect(g2.offsetX).toBe(g1.offsetX);
      expect(g2.offsetY).toBe(g1.offsetY);
      expect(g2.bitmap).toEqual(g1.bitmap);
    }
  });

  it('roundtrips low_gothic_8x10 preserving glyph data', () => {
    const source = readExample('low_gothic_8x10.c');
    const font1 = parseLvglFont(source);
    const serialized = serializeLvglFont(font1);
    const font2 = parseLvglFont(serialized);

    expect(font2.name).toBe(font1.name);
    expect(font2.glyphs.length).toBe(font1.glyphs.length);

    for (let i = 0; i < font1.glyphs.length; i++) {
      const g1 = font1.glyphs[i];
      const g2 = font2.glyphs[i];
      expect(g2.unicode).toBe(g1.unicode);
      expect(g2.bitmap).toEqual(g1.bitmap);
    }
  });

  it('stabilizes after double roundtrip', () => {
    const source = readExample('tiny_mono_3x5.c');
    const font1 = parseLvglFont(source);
    const ser1 = serializeLvglFont(font1);
    const font2 = parseLvglFont(ser1);
    const ser2 = serializeLvglFont(font2);
    const font3 = parseLvglFont(ser2);

    // font2 and font3 should be identical
    expect(font3.glyphs.length).toBe(font2.glyphs.length);
    for (let i = 0; i < font2.glyphs.length; i++) {
      expect(font3.glyphs[i].bitmap).toEqual(font2.glyphs[i].bitmap);
    }
  });

  it('preserves character map count through roundtrip', () => {
    const source = readExample('low_gothic_8x10.c');
    const font1 = parseLvglFont(source);
    const serialized = serializeLvglFont(font1);
    const font2 = parseLvglFont(serialized);

    expect(font2.cmaps.length).toBe(font1.cmaps.length);
    for (let i = 0; i < font1.cmaps.length; i++) {
      expect(font2.cmaps[i].rangeStart).toBe(font1.cmaps[i].rangeStart);
      expect(font2.cmaps[i].rangeLength).toBe(font1.cmaps[i].rangeLength);
      expect(font2.cmaps[i].type).toBe(font1.cmaps[i].type);
    }
  });
});
