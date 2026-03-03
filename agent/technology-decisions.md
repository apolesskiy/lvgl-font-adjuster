# Technology Decisions

Decisions made during project setup, recorded for future agents.

## 2026-03-02: TypeScript over plain JavaScript
* **Decision**: Use TypeScript with strict mode.
* **Rationale**: The LVGL font data model is complex (bitmaps, glyph descriptors, character maps). Static types catch offset/size bugs at compile time. Strict mode prevents implicit-any drift.

## 2026-03-02: Vite over no-build
* **Decision**: Use Vite for dev server and production build.
* **Rationale**: project.md says "ideally run in browser JS (locally)". Vite provides instant HMR during development and tree-shaken production builds. It natively supports TypeScript and ES modules.

## 2026-03-02: Vanilla DOM + Canvas over framework
* **Decision**: No UI framework (React, Vue, etc.).
* **Rationale**: The app is a single-screen pixel editor. Canvas handles glyph rendering. A framework would add complexity with no proportional benefit.

## 2026-03-02: Vitest + Playwright over Jest + Cypress
* **Decision**: Use Vitest for unit/integration tests and Playwright for E2E.
* **Rationale**: Vitest shares Vite's config and transform pipeline, avoiding a second build tool. Playwright has first-class support for canvas-based testing and is faster than Cypress.
