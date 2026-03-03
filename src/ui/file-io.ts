/**
 * Opens a file picker and reads the selected .c file as text.
 * @returns The file content as a string, or null if cancelled.
 */
export function openFile(): Promise<string | null> {
  return new Promise((resolve) => {
    const input = document.createElement('input');
    input.type = 'file';
    input.accept = '.c';

    input.addEventListener('change', () => {
      const file = input.files?.[0];
      if (!file) {
        resolve(null);
        return;
      }

      const reader = new FileReader();
      reader.onload = (): void => {
        resolve(reader.result as string);
      };
      reader.onerror = (): void => {
        resolve(null);
      };
      reader.readAsText(file);
    });

    input.click();
  });
}

/**
 * Downloads a string as a .c file.
 * @param content - The file content.
 * @param filename - The suggested filename.
 */
export function saveFile(content: string, filename: string): void {
  const blob = new Blob([content], { type: 'text/plain' });
  const url = URL.createObjectURL(blob);
  const a = document.createElement('a');
  a.href = url;
  a.download = filename;
  a.click();
  URL.revokeObjectURL(url);
}
