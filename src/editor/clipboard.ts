/**
 * Simple clipboard store for pixel rectangles.
 */
export class ClipboardStore {
  private content: boolean[][] | null = null;

  /**
   * Copies a pixel rectangle to the clipboard.
   */
  copy(pixels: boolean[][]): void {
    this.content = pixels.map(row => [...row]);
  }

  /**
   * Returns the clipboard content, or null if empty.
   */
  paste(): boolean[][] | null {
    if (!this.content) return null;
    return this.content.map(row => [...row]);
  }

  /**
   * Returns true if the clipboard has content.
   */
  hasContent(): boolean {
    return this.content !== null;
  }
}
