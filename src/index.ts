import { FontData, cloneGlyph } from './model/font-model.js';
import { parseLvglFont } from './parser/lvgl-parser.js';
import { serializeLvglFont } from './serializer/lvgl-serializer.js';
import { CanvasRenderer } from './editor/canvas-renderer.js';
import { togglePixel, setPixel, boxSelect, pastePixels, movePixels, resizeGlyph, resizeFontDelta } from './editor/tools.js';
import { ClipboardStore } from './editor/clipboard.js';
import { History } from './history/history.js';
import { GlyphList } from './ui/glyph-list.js';
import { Toolbar, ToolMode } from './ui/toolbar.js';
import { openFile, saveFile } from './ui/file-io.js';

/**
 * Main application class that wires all modules together.
 */
class App {
  private font: FontData | null = null;
  private selectedGlyphIndex = 0;
  private currentTool: ToolMode = ToolMode.DRAW;
  private renderer: CanvasRenderer;
  private glyphList: GlyphList;
  private toolbar: Toolbar;
  private history: History;
  private clipboard: ClipboardStore;
  private statusBar: HTMLElement;
  private canvas: HTMLCanvasElement;
  private fileName = 'font.c';

  // Selection state
  private selectionStart: { row: number; col: number } | null = null;
  private selectionEnd: { row: number; col: number } | null = null;
  private isDragging = false;
  private isDragMoving = false;
  private dragMoveAnchor: { row: number; col: number } | null = null;

  constructor() {
    this.canvas = document.getElementById('glyph-canvas') as HTMLCanvasElement;
    this.statusBar = document.getElementById('status-bar') as HTMLElement;
    this.history = new History();
    this.clipboard = new ClipboardStore();

    this.renderer = new CanvasRenderer(this.canvas, 24);

    this.glyphList = new GlyphList(
      document.getElementById('glyph-list') as HTMLElement,
      (index) => this.selectGlyph(index),
    );

    this.toolbar = new Toolbar(
      document.getElementById('toolbar') as HTMLElement,
      {
        onOpen: (): void => { this.handleOpen(); },
        onSave: (): void => this.handleSave(),
        onUndo: (): void => this.handleUndo(),
        onRedo: (): void => this.handleRedo(),
        onToolChange: (tool): void => { this.currentTool = tool; },
        onGlyphResize: (dw, dh): void => this.handleGlyphResize(dw, dh),
        onFontResize: (dw, dh): void => this.handleFontResize(dw, dh),
      },
    );

    this.setupCanvasEvents();
    this.setupKeyboardShortcuts();
  }

  /**
   * Sets up mouse event handlers on the canvas.
   */
  private setupCanvasEvents(): void {
    this.canvas.addEventListener('mousedown', (e) => this.onCanvasMouseDown(e));
    this.canvas.addEventListener('mousemove', (e) => this.onCanvasMouseMove(e));
    this.canvas.addEventListener('mouseup', (e) => this.onCanvasMouseUp(e));
    this.canvas.addEventListener('mouseleave', (e) => this.onCanvasMouseUp(e));
  }

  /**
   * Sets up keyboard shortcuts.
   */
  private setupKeyboardShortcuts(): void {
    document.addEventListener('keydown', (e) => {
      if (e.ctrlKey || e.metaKey) {
        switch (e.key.toLowerCase()) {
        case 'z':
          e.preventDefault();
          if (e.shiftKey) {
            this.handleRedo();
          } else {
            this.handleUndo();
          }
          break;
        case 'y':
          e.preventDefault();
          this.handleRedo();
          break;
        case 'c':
          e.preventDefault();
          this.handleCopy();
          break;
        case 'v':
          e.preventDefault();
          this.handlePaste();
          break;
        }
      }
    });
  }

  /**
   * Opens a font file.
   */
  private async handleOpen(): Promise<void> {
    const content = await openFile();
    if (!content) return;

    try {
      this.font = parseLvglFont(content);
      this.history.clear();
      this.selectedGlyphIndex = 0;
      this.glyphList.render(this.font.glyphs);
      this.glyphList.setSelected(0);
      this.renderCurrentGlyph();
      this.updateStatus();
      this.updateToolbar();
      this.fileName = this.font.name + '.c';
    } catch (err) {
      const msg = err instanceof Error ? err.message : 'Unknown error';
      this.statusBar.textContent = `Error: ${msg}`;
    }
  }

  /**
   * Saves the current font to a file.
   */
  private handleSave(): void {
    if (!this.font) return;
    const content = serializeLvglFont(this.font);
    saveFile(content, this.fileName);
  }

  /**
   * Undoes the last edit.
   */
  private handleUndo(): void {
    if (!this.font) return;
    const currentGlyph = this.font.glyphs[this.selectedGlyphIndex];
    const snapshot = this.history.undo(this.selectedGlyphIndex, currentGlyph);
    if (!snapshot) return;

    this.font.glyphs[snapshot.glyphIndex] = cloneGlyph(snapshot.glyph);
    if (snapshot.glyphIndex !== this.selectedGlyphIndex) {
      this.selectGlyph(snapshot.glyphIndex);
    } else {
      this.renderCurrentGlyph();
    }
    this.updateToolbar();
  }

  /**
   * Redoes the last undone edit.
   */
  private handleRedo(): void {
    if (!this.font) return;
    const currentGlyph = this.font.glyphs[this.selectedGlyphIndex];
    const snapshot = this.history.redo(this.selectedGlyphIndex, currentGlyph);
    if (!snapshot) return;

    this.font.glyphs[snapshot.glyphIndex] = cloneGlyph(snapshot.glyph);
    if (snapshot.glyphIndex !== this.selectedGlyphIndex) {
      this.selectGlyph(snapshot.glyphIndex);
    } else {
      this.renderCurrentGlyph();
    }
    this.updateToolbar();
  }

  /**
   * Copies the current selection to the clipboard.
   */
  private handleCopy(): void {
    if (!this.font || !this.selectionStart || !this.selectionEnd) return;
    const glyph = this.font.glyphs[this.selectedGlyphIndex];
    const pixels = boxSelect(
      glyph,
      this.selectionStart.row, this.selectionStart.col,
      this.selectionEnd.row, this.selectionEnd.col,
    );
    this.clipboard.copy(pixels);
  }

  /**
   * Pastes clipboard content at the selection start.
   */
  private handlePaste(): void {
    if (!this.font || !this.clipboard.hasContent()) return;
    const pixels = this.clipboard.paste();
    if (!pixels) return;

    const glyph = this.font.glyphs[this.selectedGlyphIndex];
    this.history.pushState(this.selectedGlyphIndex, glyph);

    const startRow = this.selectionStart?.row ?? 0;
    const startCol = this.selectionStart?.col ?? 0;
    pastePixels(glyph, pixels, startRow, startCol);

    this.renderCurrentGlyph();
    this.updateToolbar();
  }

  /**
   * Resizes the currently selected glyph by a delta.
   */
  private handleGlyphResize(dw: number, dh: number): void {
    if (!this.font) return;
    const glyph = this.font.glyphs[this.selectedGlyphIndex];
    if (!glyph) return;

    const newW = glyph.boxWidth + dw;
    const newH = glyph.boxHeight + dh;
    if (newW < 1 || newH < 1) return;

    this.history.pushState(this.selectedGlyphIndex, glyph);
    resizeGlyph(glyph, newW, newH);
    this.selectionStart = null;
    this.selectionEnd = null;
    this.renderCurrentGlyph();
    this.updateStatus();
    this.updateToolbar();
  }

  /**
   * Resizes all glyphs in the font by a delta, preserving individual size differences.
   */
  private handleFontResize(dw: number, dh: number): void {
    if (!this.font) return;

    // Push state for every glyph so undo restores all of them
    for (let i = 0; i < this.font.glyphs.length; i++) {
      this.history.pushState(i, this.font.glyphs[i]);
    }

    resizeFontDelta(this.font, dw, dh);
    this.selectionStart = null;
    this.selectionEnd = null;
    this.renderCurrentGlyph();
    this.glyphList.render(this.font.glyphs);
    this.glyphList.setSelected(this.selectedGlyphIndex);
    this.updateStatus();
    this.updateToolbar();
  }

  /**
   * Returns true if the given pixel coordinate is inside the current selection.
   */
  private isInsideSelection(row: number, col: number): boolean {
    if (!this.selectionStart || !this.selectionEnd) return false;
    const minR = Math.min(this.selectionStart.row, this.selectionEnd.row);
    const maxR = Math.max(this.selectionStart.row, this.selectionEnd.row);
    const minC = Math.min(this.selectionStart.col, this.selectionEnd.col);
    const maxC = Math.max(this.selectionStart.col, this.selectionEnd.col);
    return row >= minR && row <= maxR && col >= minC && col <= maxC;
  }

  /**
   * Handles mouse down on the canvas.
   */
  private onCanvasMouseDown(e: MouseEvent): void {
    if (!this.font) return;
    const glyph = this.font.glyphs[this.selectedGlyphIndex];
    const pixel = this.renderer.coordsToPixel(e.clientX, e.clientY, glyph);
    if (!pixel) return;

    this.isDragging = true;

    if (this.currentTool === ToolMode.DRAW) {
      this.history.pushState(this.selectedGlyphIndex, glyph);
      togglePixel(glyph, pixel.row, pixel.col);
      this.renderCurrentGlyph();
      this.updateToolbar();
    } else if (this.currentTool === ToolMode.SELECT) {
      // If clicking inside an existing selection, start drag-move
      if (this.isInsideSelection(pixel.row, pixel.col)) {
        this.isDragMoving = true;
        this.dragMoveAnchor = pixel;
        this.history.pushState(this.selectedGlyphIndex, glyph);
      } else {
        // Start a new selection
        this.isDragMoving = false;
        this.dragMoveAnchor = null;
        this.selectionStart = pixel;
        this.selectionEnd = pixel;
      }
    } else if (this.currentTool === ToolMode.MOVE) {
      if (this.selectionStart && this.selectionEnd) {
        // Start drag-move from MOVE tool as well
        if (this.isInsideSelection(pixel.row, pixel.col)) {
          this.isDragMoving = true;
          this.dragMoveAnchor = pixel;
          this.history.pushState(this.selectedGlyphIndex, glyph);
        } else {
          this.history.pushState(this.selectedGlyphIndex, glyph);
          movePixels(glyph, {
            r1: this.selectionStart.row, c1: this.selectionStart.col,
            r2: this.selectionEnd.row, c2: this.selectionEnd.col,
          }, pixel.row - this.selectionStart.row, pixel.col - this.selectionStart.col);
          this.selectionStart = null;
          this.selectionEnd = null;
          this.renderCurrentGlyph();
          this.updateToolbar();
        }
      }
    }
  }

  /**
   * Handles mouse move on the canvas.
   */
  private onCanvasMouseMove(e: MouseEvent): void {
    if (!this.font || !this.isDragging) return;
    const glyph = this.font.glyphs[this.selectedGlyphIndex];
    const pixel = this.renderer.coordsToPixel(e.clientX, e.clientY, glyph);
    if (!pixel) return;

    if (this.currentTool === ToolMode.DRAW) {
      setPixel(glyph, pixel.row, pixel.col, !glyph.bitmap[pixel.row][pixel.col] || true);
      this.renderCurrentGlyph();
    } else if (this.currentTool === ToolMode.SELECT || this.currentTool === ToolMode.MOVE) {
      if (this.isDragMoving && this.dragMoveAnchor && this.selectionStart && this.selectionEnd) {
        // Preview: render base glyph then render selection highlight at new offset
        this.renderCurrentGlyph();
        const dr = pixel.row - this.dragMoveAnchor.row;
        const dc = pixel.col - this.dragMoveAnchor.col;
        const newR1 = Math.min(this.selectionStart.row, this.selectionEnd.row) + dr;
        const newC1 = Math.min(this.selectionStart.col, this.selectionEnd.col) + dc;
        const newR2 = Math.max(this.selectionStart.row, this.selectionEnd.row) + dr;
        const newC2 = Math.max(this.selectionStart.col, this.selectionEnd.col) + dc;
        this.renderer.renderSelection(newR1, newC1, newR2, newC2);
      } else if (!this.isDragMoving && this.currentTool === ToolMode.SELECT) {
        this.selectionEnd = pixel;
        this.renderCurrentGlyph();
        if (this.selectionStart && this.selectionEnd) {
          this.renderer.renderSelection(
            this.selectionStart.row, this.selectionStart.col,
            this.selectionEnd.row, this.selectionEnd.col,
          );
        }
      }
    }
  }

  /**
   * Handles mouse up on the canvas.
   */
  private onCanvasMouseUp(e: MouseEvent): void {
    if (this.isDragMoving && this.dragMoveAnchor && this.selectionStart && this.selectionEnd && this.font) {
      const glyph = this.font.glyphs[this.selectedGlyphIndex];
      const pixel = this.renderer.coordsToPixel(
        e.clientX, e.clientY, glyph,
      );
      if (pixel) {
        const dr = pixel.row - this.dragMoveAnchor.row;
        const dc = pixel.col - this.dragMoveAnchor.col;
        if (dr !== 0 || dc !== 0) {
          movePixels(glyph, {
            r1: this.selectionStart.row, c1: this.selectionStart.col,
            r2: this.selectionEnd.row, c2: this.selectionEnd.col,
          }, dr, dc);

          // Update selection bounds to new position
          const minR = Math.min(this.selectionStart.row, this.selectionEnd.row);
          const maxR = Math.max(this.selectionStart.row, this.selectionEnd.row);
          const minC = Math.min(this.selectionStart.col, this.selectionEnd.col);
          const maxC = Math.max(this.selectionStart.col, this.selectionEnd.col);
          this.selectionStart = { row: minR + dr, col: minC + dc };
          this.selectionEnd = { row: maxR + dr, col: maxC + dc };
        }
      }
      this.renderCurrentGlyph();
      if (this.selectionStart && this.selectionEnd) {
        this.renderer.renderSelection(
          this.selectionStart.row, this.selectionStart.col,
          this.selectionEnd.row, this.selectionEnd.col,
        );
      }
      this.updateToolbar();
    }
    this.isDragging = false;
    this.isDragMoving = false;
    this.dragMoveAnchor = null;
  }

  /**
   * Selects a glyph by index and renders it.
   */
  private selectGlyph(index: number): void {
    this.selectedGlyphIndex = index;
    this.glyphList.setSelected(index);
    this.selectionStart = null;
    this.selectionEnd = null;
    this.renderCurrentGlyph();
    this.updateStatus();
  }

  /**
   * Re-renders the currently selected glyph on the canvas.
   */
  private renderCurrentGlyph(): void {
    if (!this.font) return;
    const glyph = this.font.glyphs[this.selectedGlyphIndex];
    if (glyph) {
      this.renderer.render(glyph);
    }
  }

  /**
   * Updates the status bar text.
   */
  private updateStatus(): void {
    if (!this.font) {
      this.statusBar.textContent = 'No file loaded';
      return;
    }
    const glyph = this.font.glyphs[this.selectedGlyphIndex];
    if (glyph) {
      this.statusBar.textContent =
        `${this.font.name} | U+${glyph.unicode.toString(16).toUpperCase().padStart(4, '0')} "${glyph.char}" | ${glyph.boxWidth}×${glyph.boxHeight} | offset: (${glyph.offsetX}, ${glyph.offsetY})`;
    }
  }

  /**
   * Updates toolbar button states.
   */
  private updateToolbar(): void {
    this.toolbar.updateState({
      canUndo: this.history.canUndo(),
      canRedo: this.history.canRedo(),
      hasFile: this.font !== null,
    });
  }
}

// Bootstrap the application
new App();
