# LVGL Font file editor

This project is a user interface to make manual edits and fixes to C-style LVGL font files created by lvgl-font-conv. When converting fonts for small monochrome displays, artifacts become prominent and consume significant screen real estate. Since the font is a C file and not a bitmap/spritesheet, it is difficult to make manual edits.

The app should ideally run in browser JS (locally).

## Features
* Load and save LVGL font .c file.
* Saved files should be compiling C code, no text edits should be required.
* Support 1bpp files only to start.
* Toggle pixels on or off.
* Move glyph offsets.
* Change height/width for entire font while preserving individual glyph offsets.
* Box-select and move pixels.
* Copy and paste pixels.
* Undo/redo.