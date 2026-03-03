import { defineConfig } from 'vite';
import { resolve } from 'path';

export default defineConfig({
  base: '/lvgl-font-adjuster/',
  root: '.',
  build: {
    outDir: 'dist',
    emptyOutDir: true,
  },
  resolve: {
    alias: {
      '@': resolve(__dirname, 'src'),
    },
  },
});
