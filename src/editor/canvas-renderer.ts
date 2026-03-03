import { Glyph } from '../model/font-model.js';

/**
 * Renders a glyph's bitmap onto an HTML canvas at a configurable pixel scale.
 */
export class CanvasRenderer {
  private canvas: HTMLCanvasElement;
  private ctx: CanvasRenderingContext2D;
  private pixelSize: number;
  private fgColor = '#e0e0e0';
  private bgColor = '#2a2a2a';
  private gridColor = '#444444';

  /**
   * Creates a new CanvasRenderer.
   * @param canvas - The canvas element to draw on.
   * @param pixelSize - The screen pixel size for each glyph pixel.
   */
  constructor(canvas: HTMLCanvasElement, pixelSize = 24) {
    this.canvas = canvas;
    const ctx = canvas.getContext('2d');
    if (!ctx) throw new Error('Cannot get 2d context from canvas');
    this.ctx = ctx;
    this.pixelSize = pixelSize;
  }

  /**
   * Updates the pixel scale.
   */
  setPixelSize(size: number): void {
    this.pixelSize = size;
  }

  /**
   * Returns the current pixel size.
   */
  getPixelSize(): number {
    return this.pixelSize;
  }

  /**
   * Renders a glyph's bitmap on the canvas.
   */
  render(glyph: Glyph): void {
    const cellSize = this.pixelSize + 1; // +1 for grid line
    const width = glyph.boxWidth * cellSize + 1;
    const height = glyph.boxHeight * cellSize + 1;

    this.canvas.width = width;
    this.canvas.height = height;

    // Fill background
    this.ctx.fillStyle = this.bgColor;
    this.ctx.fillRect(0, 0, width, height);

    // Draw pixels
    for (let row = 0; row < glyph.boxHeight; row++) {
      for (let col = 0; col < glyph.boxWidth; col++) {
        const isOn = row < glyph.bitmap.length &&
          col < glyph.bitmap[row].length &&
          glyph.bitmap[row][col];

        this.ctx.fillStyle = isOn ? this.fgColor : this.bgColor;
        this.ctx.fillRect(
          col * cellSize + 1,
          row * cellSize + 1,
          this.pixelSize,
          this.pixelSize,
        );
      }
    }

    // Draw grid lines
    this.ctx.strokeStyle = this.gridColor;
    this.ctx.lineWidth = 1;

    for (let col = 0; col <= glyph.boxWidth; col++) {
      const x = col * cellSize + 0.5;
      this.ctx.beginPath();
      this.ctx.moveTo(x, 0);
      this.ctx.lineTo(x, height);
      this.ctx.stroke();
    }

    for (let row = 0; row <= glyph.boxHeight; row++) {
      const y = row * cellSize + 0.5;
      this.ctx.beginPath();
      this.ctx.moveTo(0, y);
      this.ctx.lineTo(width, y);
      this.ctx.stroke();
    }
  }

  /**
   * Renders a selection highlight overlay on the canvas.
   */
  renderSelection(r1: number, c1: number, r2: number, c2: number): void {
    const cellSize = this.pixelSize + 1;
    const minR = Math.min(r1, r2);
    const maxR = Math.max(r1, r2);
    const minC = Math.min(c1, c2);
    const maxC = Math.max(c1, c2);

    this.ctx.strokeStyle = '#0078d4';
    this.ctx.lineWidth = 2;
    this.ctx.strokeRect(
      minC * cellSize + 0.5,
      minR * cellSize + 0.5,
      (maxC - minC + 1) * cellSize,
      (maxR - minR + 1) * cellSize,
    );
  }

  /**
   * Converts mouse client coordinates to glyph pixel coordinates.
   * @returns The {row, col} or null if outside bounds.
   */
  coordsToPixel(clientX: number, clientY: number, glyph: Glyph): { row: number; col: number } | null {
    const rect = this.canvas.getBoundingClientRect();
    const x = clientX - rect.left;
    const y = clientY - rect.top;

    const cellSize = this.pixelSize + 1;
    const col = Math.floor(x / cellSize);
    const row = Math.floor(y / cellSize);

    if (col < 0 || col >= glyph.boxWidth || row < 0 || row >= glyph.boxHeight) {
      return null;
    }

    return { row, col };
  }
}
