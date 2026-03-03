import { Glyph, unicodeLabel } from '../model/font-model.js';

/**
 * Manages the glyph list sidebar.
 */
export class GlyphList {
  private container: HTMLElement;
  private onSelect: (index: number) => void;
  private selectedIndex = -1;

  /**
   * Creates a new GlyphList.
   * @param container - The DOM element to render into.
   * @param onSelect - Callback when a glyph is selected.
   */
  constructor(container: HTMLElement, onSelect: (index: number) => void) {
    this.container = container;
    this.onSelect = onSelect;
  }

  /**
   * Renders the glyph list.
   */
  render(glyphs: Glyph[]): void {
    this.container.innerHTML = '';

    glyphs.forEach((glyph, index) => {
      const item = document.createElement('div');
      item.className = 'glyph-item';
      if (index === this.selectedIndex) {
        item.classList.add('selected');
      }

      const charSpan = document.createElement('span');
      charSpan.className = 'glyph-char';
      charSpan.textContent = glyph.char;

      const codeSpan = document.createElement('span');
      codeSpan.className = 'glyph-code';
      codeSpan.textContent = unicodeLabel(glyph.unicode);

      item.appendChild(charSpan);
      item.appendChild(codeSpan);

      item.addEventListener('click', () => {
        this.setSelected(index);
        this.onSelect(index);
      });

      this.container.appendChild(item);
    });
  }

  /**
   * Sets the selected glyph index and updates the UI.
   */
  setSelected(index: number): void {
    const items = this.container.querySelectorAll('.glyph-item');
    if (this.selectedIndex >= 0 && this.selectedIndex < items.length) {
      items[this.selectedIndex].classList.remove('selected');
    }
    this.selectedIndex = index;
    if (index >= 0 && index < items.length) {
      items[index].classList.add('selected');
      items[index].scrollIntoView({ block: 'nearest' });
    }
  }
}
