import { describe, it, expect } from 'vitest';
import { History } from '../../src/history/history.js';
import type { Glyph } from '../../src/model/font-model.js';

/** Creates a simple test glyph. */
function makeGlyph(pixelValue: boolean): Glyph {
  return {
    unicode: 0x41,
    char: 'A',
    advanceWidth: 80,
    boxWidth: 1,
    boxHeight: 1,
    offsetX: 0,
    offsetY: 0,
    bitmap: [[pixelValue]],
  };
}

describe('History', () => {
  it('starts with empty stacks', () => {
    const h = new History();
    expect(h.canUndo()).toBe(false);
    expect(h.canRedo()).toBe(false);
  });

  it('can undo after push', () => {
    const h = new History();
    h.pushState(0, makeGlyph(true));
    expect(h.canUndo()).toBe(true);
  });

  it('undo returns the saved state', () => {
    const h = new History();
    const original = makeGlyph(true);
    h.pushState(0, original);

    const current = makeGlyph(false);
    const snapshot = h.undo(0, current);

    expect(snapshot).not.toBeNull();
    expect(snapshot!.glyphIndex).toBe(0);
    expect(snapshot!.glyph.bitmap[0][0]).toBe(true);
  });

  it('redo returns the state before undo', () => {
    const h = new History();
    h.pushState(0, makeGlyph(true));

    const afterEdit = makeGlyph(false);
    h.undo(0, afterEdit);

    const restored = makeGlyph(true);
    const snapshot = h.redo(0, restored);

    expect(snapshot).not.toBeNull();
    expect(snapshot!.glyph.bitmap[0][0]).toBe(false);
  });

  it('push clears redo stack', () => {
    const h = new History();
    h.pushState(0, makeGlyph(true));
    h.undo(0, makeGlyph(false));
    expect(h.canRedo()).toBe(true);

    h.pushState(0, makeGlyph(true));
    expect(h.canRedo()).toBe(false);
  });

  it('respects maxSize', () => {
    const h = new History(3);
    for (let i = 0; i < 5; i++) {
      h.pushState(0, makeGlyph(i % 2 === 0));
    }

    // Should only have 3 undo states
    let count = 0;
    while (h.canUndo()) {
      h.undo(0, makeGlyph(false));
      count++;
    }
    expect(count).toBe(3);
  });

  it('clear empties both stacks', () => {
    const h = new History();
    h.pushState(0, makeGlyph(true));
    h.undo(0, makeGlyph(false));
    h.clear();

    expect(h.canUndo()).toBe(false);
    expect(h.canRedo()).toBe(false);
  });

  it('undo on empty returns null', () => {
    const h = new History();
    expect(h.undo(0, makeGlyph(false))).toBeNull();
  });

  it('redo on empty returns null', () => {
    const h = new History();
    expect(h.redo(0, makeGlyph(false))).toBeNull();
  });
});
