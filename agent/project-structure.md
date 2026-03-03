# Project Structure

```
lv_font_editor/
├── agent/                    # Agent documentation (not shipped)
│   ├── project.md
│   ├── project-structure.md
│   ├── project-structure-decisions.md
│   ├── technology-stack.md
│   ├── technology-decisions.md
│   └── design/
│       └── *.md              # Design documents
├── example_input/            # Sample LVGL font .c files for testing
├── src/                      # Application source (TypeScript)
│   ├── index.ts              # Entry point — bootstraps app
│   ├── parser/
│   │   └── lvgl-parser.ts    # Parses LVGL .c font file → FontData model
│   ├── serializer/
│   │   └── lvgl-serializer.ts # Serializes FontData model → LVGL .c text
│   ├── model/
│   │   └── font-model.ts     # FontData, GlyphData, CmapEntry types
│   ├── editor/
│   │   ├── editor.ts         # Main Editor class — orchestrates UI
│   │   ├── canvas-renderer.ts # Canvas-based glyph pixel renderer
│   │   ├── tools.ts          # Editing tools (toggle, box-select, move)
│   │   └── clipboard.ts      # Copy/paste pixel data
│   ├── history/
│   │   └── history.ts        # Undo/redo command stack
│   └── ui/
│       ├── toolbar.ts        # Toolbar buttons and controls
│       ├── glyph-list.ts     # Sidebar glyph selector/list
│       └── file-io.ts        # File open/save via browser APIs
├── tests/
│   ├── unit/                 # Vitest unit tests
│   │   ├── parser.test.ts
│   │   ├── serializer.test.ts
│   │   ├── font-model.test.ts
│   │   └── history.test.ts
│   ├── integration/          # Vitest integration tests
│   │   └── parse-serialize-roundtrip.test.ts
│   └── e2e/                  # Playwright E2E tests
│       └── editor.spec.ts
├── public/                   # Static assets served by Vite
│   └── index.html
├── package.json
├── tsconfig.json
├── vite.config.ts
├── eslint.config.js
└── .gitignore
```

## Conventions
* Source code lives in `src/`, organized by concern (parser, serializer, model, editor, history, ui).
* Each directory contains one primary module file. Additional files may be added as complexity grows.
* Tests mirror source structure under `tests/unit/` and `tests/integration/`.
* E2E tests live in `tests/e2e/`.
* `public/index.html` is the app shell; Vite injects the script bundle.
