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
   * Sets the active tool mode and updates button styles.
   */
  setActiveTool(tool: ToolMode): void {
    this.activeTool = tool;
    this.toolButtons.forEach((btn, mode) => {
      btn.classList.toggle('active', mode === tool);
    });
  }

  /**
   * Updates the enabled/disabled state of undo/redo/save buttons.
   */
  updateState(options: { canUndo: boolean; canRedo: boolean; hasFile: boolean }): void {
    this.undoBtn.disabled = !options.canUndo;
    this.redoBtn.disabled = !options.canRedo;
    this.saveBtn.disabled = !options.hasFile;
  }
}
