import { test, expect, Page } from '@playwright/test';
import { readFileSync } from 'fs';
import { dirname, resolve } from 'path';
import { fileURLToPath } from 'url';

const __dirname = dirname(fileURLToPath(import.meta.url));
const exampleDir = resolve(__dirname, '../../example_input');
const tinyMonoPath = resolve(exampleDir, 'tiny_mono_3x5.c');
const lowGothicPath = resolve(exampleDir, 'low_gothic_8x10.c');

/**
 * Helper to load a font file into the app via the file chooser.
 */
async function loadFontFile(page: Page, filePath: string): Promise<void> {
  const [fileChooser] = await Promise.all([
    page.waitForEvent('filechooser'),
    page.getByRole('button', { name: 'Open' }).click(),
  ]);
  await fileChooser.setFiles(filePath);
}

test.describe('LVGL Font Editor E2E', () => {
  test.beforeEach(async ({ page }) => {
    await page.goto('/');
  });

  test('app loads with initial UI state', async ({ page }) => {
    // Status bar shows no file loaded
    await expect(page.locator('#status-bar')).toHaveText('No file loaded');

    // Toolbar buttons present
    await expect(page.getByRole('button', { name: 'Open' })).toBeVisible();
    await expect(page.getByRole('button', { name: 'Save' })).toBeVisible();
    await expect(page.getByRole('button', { name: 'Save' })).toBeDisabled();
    await expect(page.getByRole('button', { name: 'Undo' })).toBeDisabled();
    await expect(page.getByRole('button', { name: 'Redo' })).toBeDisabled();

    // Tool buttons present with Draw active
    await expect(page.getByRole('button', { name: 'Draw' })).toHaveClass(/active/);
    await expect(page.getByRole('button', { name: 'Select' })).toBeVisible();
    await expect(page.getByRole('button', { name: 'Move' })).toBeVisible();

    // Canvas present
    await expect(page.locator('#glyph-canvas')).toBeVisible();

    // Glyph list empty
    await expect(page.locator('#glyph-list .glyph-item')).toHaveCount(0);
  });

  test('loads a font file and populates glyph list', async ({ page }) => {
    await loadFontFile(page, tinyMonoPath);

    // Glyph list should be populated
    const items = page.locator('#glyph-list .glyph-item');
    await expect(items.first()).toBeVisible();
    const count = await items.count();
    expect(count).toBeGreaterThan(0);

    // First glyph should be selected
    await expect(items.first()).toHaveClass(/selected/);

    // Status bar should show font info
    await expect(page.locator('#status-bar')).not.toHaveText('No file loaded');
    await expect(page.locator('#status-bar')).toContainText('tiny_mono_3x5');

    // Save button should be enabled
    await expect(page.getByRole('button', { name: 'Save' })).toBeEnabled();
  });

  test('loads low_gothic font file', async ({ page }) => {
    await loadFontFile(page, lowGothicPath);

    const items = page.locator('#glyph-list .glyph-item');
    await expect(items.first()).toBeVisible();
    const count = await items.count();
    expect(count).toBeGreaterThan(0);

    await expect(page.locator('#status-bar')).toContainText('low_gothic_8x10');
  });

  test('selects a glyph from the list and updates status', async ({ page }) => {
    await loadFontFile(page, tinyMonoPath);

    const items = page.locator('#glyph-list .glyph-item');
    await expect(items.first()).toBeVisible();

    // Click third glyph (index 2)
    const thirdItem = items.nth(2);
    await thirdItem.click();

    // Third item should now be selected
    await expect(thirdItem).toHaveClass(/selected/);

    // First item should no longer be selected
    await expect(items.first()).not.toHaveClass(/selected/);

    // Status bar should update
    const statusText = await page.locator('#status-bar').textContent();
    expect(statusText).toBeTruthy();
  });

  test('toggles a pixel by clicking on the canvas', async ({ page }) => {
    await loadFontFile(page, tinyMonoPath);

    // Wait for canvas to render
    await page.waitForTimeout(200);

    // Get canvas center position for clicking
    const canvas = page.locator('#glyph-canvas');
    const box = await canvas.boundingBox();
    expect(box).toBeTruthy();

    // Click on the canvas to toggle a pixel
    await canvas.click({ position: { x: box!.width / 2, y: box!.height / 2 } });

    // Undo should become enabled after a pixel toggle
    await expect(page.getByRole('button', { name: 'Undo' })).toBeEnabled();
  });

  test('undo reverts pixel toggle', async ({ page }) => {
    await loadFontFile(page, tinyMonoPath);
    await page.waitForTimeout(200);

    const canvas = page.locator('#glyph-canvas');
    const box = await canvas.boundingBox();
    expect(box).toBeTruthy();

    // Toggle a pixel
    await canvas.click({ position: { x: box!.width / 2, y: box!.height / 2 } });
    await expect(page.getByRole('button', { name: 'Undo' })).toBeEnabled();

    // Undo via toolbar button
    await page.getByRole('button', { name: 'Undo' }).click();

    // Undo should be disabled again (only one action was done)
    await expect(page.getByRole('button', { name: 'Undo' })).toBeDisabled();

    // Redo should be enabled
    await expect(page.getByRole('button', { name: 'Redo' })).toBeEnabled();
  });

  test('redo restores undone action', async ({ page }) => {
    await loadFontFile(page, tinyMonoPath);
    await page.waitForTimeout(200);

    const canvas = page.locator('#glyph-canvas');
    const box = await canvas.boundingBox();
    expect(box).toBeTruthy();

    // Toggle a pixel
    await canvas.click({ position: { x: box!.width / 2, y: box!.height / 2 } });

    // Undo
    await page.getByRole('button', { name: 'Undo' }).click();
    await expect(page.getByRole('button', { name: 'Redo' })).toBeEnabled();

    // Redo
    await page.getByRole('button', { name: 'Redo' }).click();

    // Undo should be enabled again, redo disabled
    await expect(page.getByRole('button', { name: 'Undo' })).toBeEnabled();
    await expect(page.getByRole('button', { name: 'Redo' })).toBeDisabled();
  });

  test('keyboard shortcut Ctrl+Z triggers undo', async ({ page }) => {
    await loadFontFile(page, tinyMonoPath);
    await page.waitForTimeout(200);

    const canvas = page.locator('#glyph-canvas');
    const box = await canvas.boundingBox();
    expect(box).toBeTruthy();

    // Toggle a pixel
    await canvas.click({ position: { x: box!.width / 2, y: box!.height / 2 } });
    await expect(page.getByRole('button', { name: 'Undo' })).toBeEnabled();

    // Ctrl+Z
    await page.keyboard.press('Control+z');
    await expect(page.getByRole('button', { name: 'Undo' })).toBeDisabled();
  });

  test('keyboard shortcut Ctrl+Y triggers redo', async ({ page }) => {
    await loadFontFile(page, tinyMonoPath);
    await page.waitForTimeout(200);

    const canvas = page.locator('#glyph-canvas');
    const box = await canvas.boundingBox();
    expect(box).toBeTruthy();

    // Toggle, undo, then redo
    await canvas.click({ position: { x: box!.width / 2, y: box!.height / 2 } });
    await page.keyboard.press('Control+z');
    await expect(page.getByRole('button', { name: 'Redo' })).toBeEnabled();

    await page.keyboard.press('Control+y');
    await expect(page.getByRole('button', { name: 'Redo' })).toBeDisabled();
    await expect(page.getByRole('button', { name: 'Undo' })).toBeEnabled();
  });

  test('save triggers file download with valid content', async ({ page }) => {
    await loadFontFile(page, tinyMonoPath);

    // Wait for the font to load
    await expect(page.locator('#status-bar')).toContainText('tiny_mono_3x5');

    // Trigger save and capture download
    const [download] = await Promise.all([
      page.waitForEvent('download'),
      page.getByRole('button', { name: 'Save' }).click(),
    ]);

    expect(download.suggestedFilename()).toMatch(/\.c$/);

    // Read the downloaded file
    const downloadPath = await download.path();
    expect(downloadPath).toBeTruthy();
    const content = readFileSync(downloadPath!, 'utf-8');

    // Verify it contains valid LVGL font structure
    expect(content).toContain('glyph_bitmap');
    expect(content).toContain('glyph_dsc');
    expect(content).toContain('lv_font_t');
    expect(content).toContain('tiny_mono_3x5');
  });

  test('roundtrip: saved file matches original structure', async ({ page }) => {
    const originalContent = readFileSync(tinyMonoPath, 'utf-8');

    await loadFontFile(page, tinyMonoPath);
    await expect(page.locator('#status-bar')).toContainText('tiny_mono_3x5');

    // Save without making edits - should produce equivalent output
    const [download] = await Promise.all([
      page.waitForEvent('download'),
      page.getByRole('button', { name: 'Save' }).click(),
    ]);

    const downloadPath = await download.path();
    expect(downloadPath).toBeTruthy();
    const savedContent = readFileSync(downloadPath!, 'utf-8');

    // Both should contain the same structural elements
    expect(savedContent).toContain('glyph_bitmap');
    expect(savedContent).toContain('glyph_dsc');

    // Both should be parseable—verify by checking key sections exist
    // The bitmap data should match since no edits were made
    const originalBitmapMatch = originalContent.match(/glyph_bitmap\[\]\s*=\s*\{([^}]+)\}/s);
    const savedBitmapMatch = savedContent.match(/glyph_bitmap\[\]\s*=\s*\{([^}]+)\}/s);
    expect(originalBitmapMatch).toBeTruthy();
    expect(savedBitmapMatch).toBeTruthy();

    // Extract hex values and compare
    const extractHex = (s: string): string[] =>
      [...s.matchAll(/0x[0-9a-fA-F]+/g)].map(m => m[0].toLowerCase());

    const originalHex = extractHex(originalBitmapMatch![1]);
    const savedHex = extractHex(savedBitmapMatch![1]);
    expect(savedHex).toEqual(originalHex);
  });

  test('tool mode switching', async ({ page }) => {
    await loadFontFile(page, tinyMonoPath);

    // Switch to Select tool
    const selectBtn = page.getByRole('button', { name: 'Select' });
    await selectBtn.click();
    await expect(selectBtn).toHaveClass(/active/);
    await expect(page.getByRole('button', { name: 'Draw' })).not.toHaveClass(/active/);

    // Switch to Move tool
    const moveBtn = page.getByRole('button', { name: 'Move' });
    await moveBtn.click();
    await expect(moveBtn).toHaveClass(/active/);
    await expect(selectBtn).not.toHaveClass(/active/);

    // Switch back to Draw
    const drawBtn = page.getByRole('button', { name: 'Draw' });
    await drawBtn.click();
    await expect(drawBtn).toHaveClass(/active/);
    await expect(moveBtn).not.toHaveClass(/active/);
  });

  test('multiple pixel toggles create multiple undo steps', async ({ page }) => {
    await loadFontFile(page, tinyMonoPath);
    await page.waitForTimeout(200);

    const canvas = page.locator('#glyph-canvas');
    const box = await canvas.boundingBox();
    expect(box).toBeTruthy();

    // Toggle pixel at different positions
    await canvas.click({ position: { x: box!.width * 0.3, y: box!.height * 0.3 } });
    await canvas.click({ position: { x: box!.width * 0.7, y: box!.height * 0.7 } });

    // Undo first
    await page.keyboard.press('Control+z');
    await expect(page.getByRole('button', { name: 'Undo' })).toBeEnabled();

    // Undo second
    await page.keyboard.press('Control+z');
    await expect(page.getByRole('button', { name: 'Undo' })).toBeDisabled();
  });

  test('glyph list shows character and unicode code', async ({ page }) => {
    await loadFontFile(page, tinyMonoPath);

    const firstItem = page.locator('#glyph-list .glyph-item').first();
    await expect(firstItem).toBeVisible();

    // Should contain a character element and a code element
    await expect(firstItem.locator('.glyph-char')).toHaveCount(1);
    await expect(firstItem.locator('.glyph-code')).toHaveCount(1);

    // The code should look like U+XXXX
    const codeText = await firstItem.locator('.glyph-code').textContent();
    expect(codeText).toMatch(/U\+[0-9A-F]{4}/);
  });

  test('error handling: invalid file shows error in status bar', async ({ page }) => {
    // Create a temporary invalid file via the filechooser
    const [fileChooser] = await Promise.all([
      page.waitForEvent('filechooser'),
      page.getByRole('button', { name: 'Open' }).click(),
    ]);

    // Create an invalid .c file (not an LVGL font)
    const invalidContent = 'int main() { return 0; }';

    // Use a temporary file approach
    const { writeFileSync, mkdtempSync } = await import('fs');
    const { join } = await import('path');
    const { tmpdir } = await import('os');
    const tmpDir = mkdtempSync(join(tmpdir(), 'lv-font-test-'));
    const tmpFile = join(tmpDir, 'invalid.c');
    writeFileSync(tmpFile, invalidContent);

    await fileChooser.setFiles(tmpFile);

    // Status bar should show an error
    await expect(page.locator('#status-bar')).toContainText('Error');

    // Clean up
    const { rmSync } = await import('fs');
    rmSync(tmpDir, { recursive: true });
  });

  test('glyph resize buttons are visible and functional', async ({ page }) => {
    await loadFontFile(page, tinyMonoPath);
    await page.waitForTimeout(200);

    // Resize buttons should be enabled after loading a file
    const wPlusBtn = page.getByRole('button', { name: 'W+', exact: true });
    const wMinusBtn = page.getByRole('button', { name: 'W\u2212', exact: true });
    const hPlusBtn = page.getByRole('button', { name: 'H+', exact: true });
    const hMinusBtn = page.getByRole('button', { name: 'H\u2212', exact: true });

    await expect(wPlusBtn).toBeEnabled();
    await expect(wMinusBtn).toBeEnabled();
    await expect(hPlusBtn).toBeEnabled();
    await expect(hMinusBtn).toBeEnabled();

    // Get initial status to read glyph dimensions
    const statusBefore = await page.locator('#status-bar').textContent();
    expect(statusBefore).toBeTruthy();

    // Click W+ to increase width
    await wPlusBtn.click();

    // Undo should be enabled (resize is an undoable action)
    await expect(page.getByRole('button', { name: 'Undo' })).toBeEnabled();

    // Status bar should reflect new dimensions
    const statusAfter = await page.locator('#status-bar').textContent();
    expect(statusAfter).not.toEqual(statusBefore);
  });

  test('font-wide resize buttons affect all glyphs', async ({ page }) => {
    await loadFontFile(page, tinyMonoPath);
    await page.waitForTimeout(200);

    const allWPlus = page.getByRole('button', { name: 'All W+' });
    const allHPlus = page.getByRole('button', { name: 'All H+' });

    await expect(allWPlus).toBeEnabled();
    await expect(allHPlus).toBeEnabled();

    // Get initial dimensions from status
    const statusBefore = await page.locator('#status-bar').textContent();

    // Resize all glyphs width +1
    await allWPlus.click();

    await expect(page.getByRole('button', { name: 'Undo' })).toBeEnabled();

    const statusAfter = await page.locator('#status-bar').textContent();
    expect(statusAfter).not.toEqual(statusBefore);
  });

  test('resize buttons disabled when no file loaded', async ({ page }) => {
    const wPlusBtn = page.getByRole('button', { name: 'W+', exact: true });
    const allWPlus = page.getByRole('button', { name: 'All W+' });

    await expect(wPlusBtn).toBeDisabled();
    await expect(allWPlus).toBeDisabled();
  });

  test('select tool allows drag-to-move pixels', async ({ page }) => {
    await loadFontFile(page, tinyMonoPath);
    await page.waitForTimeout(200);

    const canvas = page.locator('#glyph-canvas');
    const box = await canvas.boundingBox();
    expect(box).toBeTruthy();

    // First draw a pixel
    await canvas.click({ position: { x: box!.width * 0.3, y: box!.height * 0.3 } });
    await expect(page.getByRole('button', { name: 'Undo' })).toBeEnabled();

    // Switch to select tool
    await page.getByRole('button', { name: 'Select' }).click();

    // Create a selection by dragging
    const startX = box!.width * 0.2;
    const startY = box!.height * 0.2;
    const endX = box!.width * 0.5;
    const endY = box!.height * 0.5;

    await page.mouse.move(box!.x + startX, box!.y + startY);
    await page.mouse.down();
    await page.mouse.move(box!.x + endX, box!.y + endY);
    await page.mouse.up();

    // Now drag inside the selection to move pixels
    const dragStartX = box!.width * 0.3;
    const dragStartY = box!.height * 0.3;
    const dragEndX = box!.width * 0.7;
    const dragEndY = box!.height * 0.7;

    await page.mouse.move(box!.x + dragStartX, box!.y + dragStartY);
    await page.mouse.down();
    await page.mouse.move(box!.x + dragEndX, box!.y + dragEndY);
    await page.mouse.up();

    // The move should have created an undo-able action
    await expect(page.getByRole('button', { name: 'Undo' })).toBeEnabled();
  });
});
