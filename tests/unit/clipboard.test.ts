import { describe, it, expect } from 'vitest';
import { ClipboardStore } from '../../src/editor/clipboard.js';

describe('ClipboardStore', () => {
  it('starts empty', () => {
    const c = new ClipboardStore();
    expect(c.hasContent()).toBe(false);
    expect(c.paste()).toBeNull();
  });

  it('copies and pastes pixel data', () => {
    const c = new ClipboardStore();
    const pixels = [[true, false], [false, true]];
    c.copy(pixels);

    expect(c.hasContent()).toBe(true);
    const pasted = c.paste();
    expect(pasted).toEqual(pixels);
  });

  it('paste returns a deep copy', () => {
    const c = new ClipboardStore();
    const pixels = [[true]];
    c.copy(pixels);

    const p1 = c.paste()!;
    p1[0][0] = false;

    const p2 = c.paste()!;
    expect(p2[0][0]).toBe(true);
  });

  it('copy is a deep copy', () => {
    const c = new ClipboardStore();
    const pixels = [[true]];
    c.copy(pixels);

    pixels[0][0] = false;
    expect(c.paste()![0][0]).toBe(true);
  });
});
