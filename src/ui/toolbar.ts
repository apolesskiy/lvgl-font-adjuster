/**
 * Editing tool modes.
 */
export enum ToolMode {
  DRAW = 'draw',
  SELECT = 'select',
  MOVE = 'move',
}

/**
 * Callbacks for toolbar actions.
 */
export interface ToolbarHandlers {
  onOpen: () => void;
  onSave: () => void;
  onUndo: () => void;
  onRedo: () => void;
  onToolChange: (tool: ToolMode) => void;
  onGlyphResize: (dw: number, dh: number) => void;
  onFontResize: (dw: number, dh: number) => void;
}

/**
 * Manages the toolbar UI.
 */
export class Toolbar {
  private container: HTMLElement;
  private handlers: ToolbarHandlers;
  private undoBtn!: HTMLButtonElement;
  private redoBtn!: HTMLButtonElement;
  private saveBtn!: HTMLButtonElement;
  private toolButtons: Map<ToolMode, HTMLButtonElement> = new Map();
  private glyphResizeButtons: HTMLButtonElement[] = [];
  private fontResizeButtons: HTMLButtonElement[] = [];
  private activeTool: ToolMode = ToolMode.DRAW;

  /**
   * Creates a new Toolbar.
   * @param container - The DOM element to render into.
   * @param handlers - Callbacks for toolbar actions.
   */
  constructor(container: HTMLElement, handlers: ToolbarHandlers) {
    this.container = container;
    this.handlers = handlers;
    this.render();
  }

  /**
   * Renders the toolbar buttons.
   */
  private render(): void {
    this.container.innerHTML = '';

    const openBtn = this.createButton('Open', () => this.handlers.onOpen());
    this.saveBtn = this.createButton('Save', () => this.handlers.onSave());
    this.saveBtn.disabled = true;

    this.container.appendChild(openBtn);
    this.container.appendChild(this.saveBtn);
    this.container.appendChild(this.createSeparator());

    this.undoBtn = this.createButton('Undo', () => this.handlers.onUndo());
    this.redoBtn = this.createButton('Redo', () => this.handlers.onRedo());
    this.undoBtn.disabled = true;
    this.redoBtn.disabled = true;

    this.container.appendChild(this.undoBtn);
    this.container.appendChild(this.redoBtn);
    this.container.appendChild(this.createSeparator());

    // Tool mode buttons
    const tools: { mode: ToolMode; label: string }[] = [
      { mode: ToolMode.DRAW, label: 'Draw' },
      { mode: ToolMode.SELECT, label: 'Select' },
      { mode: ToolMode.MOVE, label: 'Move' },
    ];

    for (const tool of tools) {
      const btn = this.createButton(tool.label, () => {
        this.setActiveTool(tool.mode);
        this.handlers.onToolChange(tool.mode);
      });
      if (tool.mode === this.activeTool) {
        btn.classList.add('active');
      }
      this.toolButtons.set(tool.mode, btn);
      this.container.appendChild(btn);
    }

    this.container.appendChild(this.createSeparator());

    // Glyph resize buttons
    const glyphLabel = this.createLabel('Glyph:');
    this.container.appendChild(glyphLabel);

    const glyphWPlus = this.createButton('W+', () => this.handlers.onGlyphResize(1, 0));
    const glyphWMinus = this.createButton('W\u2212', () => this.handlers.onGlyphResize(-1, 0));
    const glyphHPlus = this.createButton('H+', () => this.handlers.onGlyphResize(0, 1));
    const glyphHMinus = this.createButton('H\u2212', () => this.handlers.onGlyphResize(0, -1));
    this.glyphResizeButtons = [glyphWPlus, glyphWMinus, glyphHPlus, glyphHMinus];
    for (const btn of this.glyphResizeButtons) {
      btn.disabled = true;
      this.container.appendChild(btn);
    }

    this.container.appendChild(this.createSeparator());

    // Font-wide resize buttons
    const fontLabel = this.createLabel('Font:');
    this.container.appendChild(fontLabel);

    const fontWPlus = this.createButton('All W+', () => this.handlers.onFontResize(1, 0));
    const fontWMinus = this.createButton('All W\u2212', () => this.handlers.onFontResize(-1, 0));
    const fontHPlus = this.createButton('All H+', () => this.handlers.onFontResize(0, 1));
    const fontHMinus = this.createButton('All H\u2212', () => this.handlers.onFontResize(0, -1));
    this.fontResizeButtons = [fontWPlus, fontWMinus, fontHPlus, fontHMinus];
    for (const btn of this.fontResizeButtons) {
      btn.disabled = true;
      this.container.appendChild(btn);
    }
  }

  /**
   * Creates a toolbar button.
   */
  private createButton(label: string, onClick: () => void): HTMLButtonElement {
    const btn = document.createElement('button');
    btn.textContent = label;
    btn.addEventListener('click', onClick);
    return btn;
  }

  /**
   * Creates a visual separator element.
   */
  private createSeparator(): HTMLElement {
    const sep = document.createElement('div');
    sep.className = 'separator';
    return sep;
  }

  /**
   * Creates a text label element for the toolbar.
   */
  private createLabel(text: string): HTMLElement {
    const label = document.createElement('span');
    label.textContent = text;
    label.style.fontSize = '12px';
    label.style.color = '#aaa';
    label.style.userSelect = 'none';
    return label;
  }

  /**
   * Sets the active tool mode and updates button styles.
   */
  setActiveTool(tool: ToolMode): void {
    this.activeTool = tool;
    this.toolButtons.forEach((btn, mode) => {
      btn.classList.toggle('active', mode === tool);
    });
  }

  /**
   * Updates the enabled/disabled state of undo/redo/save/resize buttons.
   */
  updateState(options: { canUndo: boolean; canRedo: boolean; hasFile: boolean }): void {
    this.undoBtn.disabled = !options.canUndo;
    this.redoBtn.disabled = !options.canRedo;
    this.saveBtn.disabled = !options.hasFile;
    for (const btn of this.glyphResizeButtons) {
      btn.disabled = !options.hasFile;
    }
    for (const btn of this.fontResizeButtons) {
      btn.disabled = !options.hasFile;
    }
  }
}
