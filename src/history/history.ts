import { Glyph, cloneGlyph } from '../model/font-model.js';

/**
 * A snapshot of a glyph's state for undo/redo.
 */
export interface Snapshot {
  /** The index of the glyph in the font's glyph array. */
  glyphIndex: number;
  /** A deep clone of the glyph at the time of capture. */
  glyph: Glyph;
}

/**
 * Manages undo/redo history using a snapshot-based approach.
 */
export class History {
  private undoStack: Snapshot[] = [];
  private redoStack: Snapshot[] = [];
  private maxSize: number;

  /**
   * Creates a new History instance.
   * @param maxSize - Maximum number of undo states to retain (default: 100).
   */
  constructor(maxSize = 100) {
    this.maxSize = maxSize;
  }

  /**
   * Saves the current state of a glyph before a mutation.
   * Clears the redo stack.
   */
  pushState(glyphIndex: number, glyph: Glyph): void {
    this.undoStack.push({
      glyphIndex,
      glyph: cloneGlyph(glyph),
    });

    if (this.undoStack.length > this.maxSize) {
      this.undoStack.shift();
    }

    this.redoStack = [];
  }

  /**
   * Undoes the last change, returning the snapshot to restore.
   * The caller should pass the current state so it can be pushed to redo.
   * @param currentGlyphIndex - Index of the currently selected glyph.
   * @param currentGlyph - Current state of the glyph.
   * @returns The snapshot to restore, or null if nothing to undo.
   */
  undo(currentGlyphIndex: number, currentGlyph: Glyph): Snapshot | null {
    const snapshot = this.undoStack.pop();
    if (!snapshot) return null;

    this.redoStack.push({
      glyphIndex: currentGlyphIndex,
      glyph: cloneGlyph(currentGlyph),
    });

    return snapshot;
  }

  /**
   * Redoes the last undone change, returning the snapshot to restore.
   * @param currentGlyphIndex - Index of the currently selected glyph.
   * @param currentGlyph - Current state of the glyph.
   * @returns The snapshot to restore, or null if nothing to redo.
   */
  redo(currentGlyphIndex: number, currentGlyph: Glyph): Snapshot | null {
    const snapshot = this.redoStack.pop();
    if (!snapshot) return null;

    this.undoStack.push({
      glyphIndex: currentGlyphIndex,
      glyph: cloneGlyph(currentGlyph),
    });

    return snapshot;
  }

  /**
   * Returns true if there are states to undo.
   */
  canUndo(): boolean {
    return this.undoStack.length > 0;
  }

  /**
   * Returns true if there are states to redo.
   */
  canRedo(): boolean {
    return this.redoStack.length > 0;
  }

  /**
   * Clears all undo/redo history.
   */
  clear(): void {
    this.undoStack = [];
    this.redoStack = [];
  }
}
