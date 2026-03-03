/*******************************************************************************
 * Size: 10 px
 * Bpp: 1
 * Opts: --bpp 1 --size 10 --no-compress --stride 1 --align 1 --font LowGothic_8x10_Regular.ttf --range 0-65535 --format lvgl -o low_gothic_8x10.c
 ******************************************************************************/

#ifdef __has_include
    #if __has_include("lvgl.h")
        #ifndef LV_LVGL_H_INCLUDE_SIMPLE
            #define LV_LVGL_H_INCLUDE_SIMPLE
        #endif
    #endif
#endif

#ifdef LV_LVGL_H_INCLUDE_SIMPLE
    #include "lvgl.h"
#else
    #include "lvgl/lvgl.h"
#endif



#ifndef LOW_GOTHIC_8X10
#define LOW_GOTHIC_8X10 1
#endif

#if LOW_GOTHIC_8X10

/*-----------------
 *    BITMAPS
 *----------------*/

/*Store the image of the glyphs*/
static LV_ATTRIBUTE_LARGE_CONST const uint8_t glyph_bitmap[] = {
    /* U+000D "\r" */
    0x0,

    /* U+0020 " " */
    0x0,

    /* U+0021 "!" */
    0xf2,

    /* U+0022 "\"" */
    0x99,

    /* U+0023 "#" */
    0x4b, 0x74, 0xb7, 0x48,

    /* U+0024 "$" */
    0x4e, 0x72, 0x32,

    /* U+0025 "%" */
    0xc, 0x84, 0x80, 0x26, 0x0,

    /* U+0026 "&" */
    0x44, 0x96, 0x9, 0x64,

    /* U+0027 "'" */
    0xc0,

    /* U+0028 "(" */
    0x28, 0x29, 0x24, 0x9, 0x10,

    /* U+0029 ")" */
    0x88, 0x22, 0x49, 0x9, 0x40,

    /* U+002A "*" */
    0x12, 0x50, 0x16, 0x94, 0x40,

    /* U+002B "+" */
    0x5d, 0x0,

    /* U+002C "," */
    0x60,

    /* U+002D "-" */
    0xe0,

    /* U+002E "." */
    0x80,

    /* U+002F "/" */
    0x8, 0x44, 0x24, 0x1, 0x10, 0x80,

    /* U+0030 "0" */
    0x76, 0xd1, 0x70,

    /* U+0031 "1" */
    0x59, 0x20, 0xb8,

    /* U+0032 "2" */
    0x74, 0xa1, 0x38,

    /* U+0033 "3" */
    0xc5, 0x10, 0x70,

    /* U+0034 "4" */
    0x84, 0xa5, 0xb0, 0x8, 0x40,

    /* U+0035 "5" */
    0xf3, 0x10, 0x70,

    /* U+0036 "6" */
    0x73, 0xd1, 0x70,

    /* U+0037 "7" */
    0xe4, 0xa0, 0x90,

    /* U+0038 "8" */
    0x77, 0xd1, 0x70,

    /* U+0039 "9" */
    0x76, 0xf0, 0x70,

    /* U+003A ":" */
    0x84,

    /* U+003B ";" */
    0x40, 0x18,

    /* U+003C "<" */
    0x2a, 0x4, 0x40,

    /* U+003D "=" */
    0xd8, 0x36,

    /* U+003E ">" */
    0x88, 0x85, 0x0,

    /* U+003F "?" */
    0x74, 0xa0, 0x10,

    /* U+0040 "@" */
    0x5a, 0x19, 0xe7, 0x2, 0x5, 0x80,

    /* U+0041 "A" */
    0x54, 0x63, 0xb0, 0x46, 0x20,

    /* U+0042 "B" */
    0x5c, 0x75, 0x10, 0x47, 0x40,

    /* U+0043 "C" */
    0x5c, 0x61, 0x0, 0x47, 0x40,

    /* U+0044 "D" */
    0xd4, 0x63, 0x10, 0x47, 0x40,

    /* U+0045 "E" */
    0x5c, 0x21, 0xa0, 0x43, 0x60,

    /* U+0046 "F" */
    0x5c, 0x21, 0xa0, 0x42, 0x0,

    /* U+0047 "G" */
    0x54, 0x61, 0x30, 0x47, 0x40,

    /* U+0048 "H" */
    0x8c, 0x63, 0xb0, 0x46, 0x20,

    /* U+0049 "I" */
    0xe9, 0x20, 0xb8,

    /* U+004A "J" */
    0xe9, 0x20, 0xa0,

    /* U+004B "K" */
    0x8c, 0x65, 0xa0, 0x46, 0x20,

    /* U+004C "L" */
    0x92, 0x41, 0x18,

    /* U+004D "M" */
    0x86, 0x1c, 0xf3, 0x2, 0x58, 0x40,

    /* U+004E "N" */
    0x8c, 0x73, 0x90, 0x4e, 0x20,

    /* U+004F "O" */
    0x5c, 0x63, 0x10, 0x47, 0x40,

    /* U+0050 "P" */
    0x5c, 0x63, 0xa0, 0x42, 0x0,

    /* U+0051 "Q" */
    0x5c, 0x63, 0x10, 0x4b, 0x20,

    /* U+0052 "R" */
    0xd4, 0x63, 0x10, 0x6a, 0x20,

    /* U+0053 "S" */
    0x5c, 0x14, 0x10, 0x45, 0x40,

    /* U+0054 "T" */
    0xe9, 0x20, 0x90,

    /* U+0055 "U" */
    0x8c, 0x63, 0x10, 0x45, 0x40,

    /* U+0056 "V" */
    0x8c, 0x63, 0x10, 0x49, 0x0,

    /* U+0057 "W" */
    0x86, 0x19, 0x65, 0x2, 0x5c, 0x80,

    /* U+0058 "X" */
    0xb6, 0xa1, 0x68,

    /* U+0059 "Y" */
    0xb6, 0xd0, 0x90,

    /* U+005A "Z" */
    0xd8, 0x44, 0x80, 0x43, 0x60,

    /* U+005B "[" */
    0xf0, 0x49, 0x24, 0x12, 0x70,

    /* U+005C "\\" */
    0x84, 0x10, 0x81, 0x0, 0x41, 0x8,

    /* U+005D "]" */
    0xe4, 0x12, 0x49, 0x4, 0xf0,

    /* U+005E "^" */
    0x54,

    /* U+005F "_" */
    0xdb,

    /* U+0060 "`" */
    0x90,

    /* U+0061 "a" */
    0xc5, 0x8b, 0x80,

    /* U+0062 "b" */
    0x9a, 0xd1, 0x78,

    /* U+0063 "c" */
    0x72, 0xb, 0x80,

    /* U+0064 "d" */
    0x2e, 0xd1, 0x78,

    /* U+0065 "e" */
    0x77, 0x8, 0xc0,

    /* U+0066 "f" */
    0x29, 0x70, 0x90,

    /* U+0067 "g" */
    0x76, 0xd1, 0xce,

    /* U+0068 "h" */
    0x9a, 0xd1, 0x68,

    /* U+0069 "i" */
    0xb6,

    /* U+006A "j" */
    0x45, 0x45, 0x80,

    /* U+006B "k" */
    0x97, 0x51, 0x68,

    /* U+006C "l" */
    0xaa, 0x24,

    /* U+006D "m" */
    0xca, 0x59, 0x40, 0x96, 0x50,

    /* U+006E "n" */
    0xd6, 0x8b, 0x40,

    /* U+006F "o" */
    0x76, 0x8b, 0x80,

    /* U+0070 "p" */
    0x76, 0xd1, 0xa4,

    /* U+0071 "q" */
    0x54, 0xa5, 0x20, 0x68, 0x62,

    /* U+0072 "r" */
    0x72, 0x9, 0x0,

    /* U+0073 "s" */
    0x73, 0x83, 0x80,

    /* U+0074 "t" */
    0x4b, 0xa0, 0x88,

    /* U+0075 "u" */
    0xb6, 0x8a, 0xc0,

    /* U+0076 "v" */
    0xb6, 0x8a, 0x80,

    /* U+0077 "w" */
    0x96, 0x59, 0x40, 0x97, 0x20,

    /* U+0078 "x" */
    0xb5, 0xb, 0x40,

    /* U+0079 "y" */
    0xb6, 0xd0, 0xce,

    /* U+007A "z" */
    0xd8, 0x54, 0x8, 0x6c,

    /* U+007B "{" */
    0x28, 0x25, 0x12, 0x9, 0x10,

    /* U+007C "|" */
    0xdf, 0x70,

    /* U+007D "}" */
    0x88, 0x24, 0x52, 0x9, 0x40,

    /* U+007E "~" */
    0x4c, 0x80,

    /* U+00A1 "¡" */
    0xb6,

    /* U+00A2 "¢" */
    0x4e, 0x51, 0x90,

    /* U+00A3 "£" */
    0x19, 0x14, 0x34, 0x40, 0x5, 0x23,

    /* U+00A4 "¤" */
    0x9b, 0x40, 0x83, 0x83, 0x0, 0x40, 0x9b,

    /* U+00A5 "¥" */
    0x49, 0x24, 0xb7, 0x10, 0xd, 0xc4,

    /* U+00A7 "§" */
    0x71, 0x56, 0xe,

    /* U+00A9 "©" */
    0x1c, 0x0, 0x10, 0x91, 0x99, 0xc, 0xa6, 0x62,
    0x0, 0x42, 0xe, 0x0,

    /* U+00AE "®" */
    0x1c, 0x0, 0x10, 0x91, 0x99, 0x4c, 0xc6, 0x52,
    0x0, 0x42, 0xe, 0x0,

    /* U+00B5 "µ" */
    0xb6, 0x8b, 0xe0,

    /* U+00B6 "¶" */
    0x5b, 0xd0, 0xd0, 0xd0, 0x0, 0x10, 0x10,

    /* U+00BF "¿" */
    0x41, 0x41, 0x70,

    /* U+00C0 "À" */
    0x40, 0x4, 0x5, 0x47, 0x60, 0x8c, 0x40,

    /* U+00C1 "Á" */
    0x8, 0x4, 0x5, 0x47, 0x60, 0x8c, 0x40,

    /* U+00C2 "Â" */
    0x50, 0x22, 0x5, 0x47, 0x60, 0x8c, 0x40,

    /* U+00C3 "Ã" */
    0x48, 0x24, 0x5, 0x47, 0x60, 0x8c, 0x40,

    /* U+00C4 "Ä" */
    0x88, 0x15, 0x1d, 0x82, 0x31,

    /* U+00C5 "Å" */
    0x50, 0x23, 0x15, 0x47, 0x60, 0x8c, 0x40,

    /* U+00C6 "Æ" */
    0xe, 0xc5, 0x4, 0x41, 0x7a, 0x0, 0x21, 0x8,
    0x2c,

    /* U+00C7 "Ç" */
    0x5c, 0x61, 0x8, 0x83, 0x42, 0x40,

    /* U+00C8 "È" */
    0x40, 0x4, 0x5, 0xc3, 0x40, 0x86, 0xc0,

    /* U+00C9 "É" */
    0x8, 0x4, 0x5, 0xc3, 0x40, 0x86, 0xc0,

    /* U+00CA "Ê" */
    0x50, 0x22, 0x5, 0xc3, 0x40, 0x86, 0xc0,

    /* U+00CB "Ë" */
    0x88, 0x17, 0xd, 0x2, 0x1b,

    /* U+00CC "Ì" */
    0x40, 0x8e, 0x90, 0x5c,

    /* U+00CD "Í" */
    0x8, 0x4, 0xd, 0x21, 0x0, 0x46, 0x80,

    /* U+00CE "Î" */
    0x50, 0x22, 0xd, 0x21, 0x0, 0x46, 0x80,

    /* U+00CF "Ï" */
    0x48, 0x24, 0xd, 0x21, 0x0, 0x46, 0x80,

    /* U+00D1 "Ñ" */
    0xa3, 0xa4, 0x17,

    /* U+00D2 "Ò" */
    0x48, 0x24, 0x8, 0xc7, 0x20, 0x9c, 0x40,

    /* U+00D3 "Ó" */
    0x40, 0x4, 0x5, 0xc6, 0x20, 0x8e, 0x80,

    /* U+00D4 "Ô" */
    0x8, 0x4, 0x5, 0xc6, 0x20, 0x8e, 0x80,

    /* U+00D5 "Õ" */
    0x50, 0x22, 0x5, 0xc6, 0x20, 0x8e, 0x80,

    /* U+00D6 "Ö" */
    0x48, 0x24, 0x5, 0xc6, 0x20, 0x8e, 0x80,

    /* U+00D8 "Ø" */
    0x90, 0x17, 0x18, 0x82, 0x3a,

    /* U+00D9 "Ù" */
    0x40, 0x4, 0x8, 0xc6, 0x20, 0x8a, 0x80,

    /* U+00DA "Ú" */
    0x8, 0x4, 0x8, 0xc6, 0x20, 0x8a, 0x80,

    /* U+00DB "Û" */
    0x50, 0x22, 0x8, 0xc6, 0x20, 0x8a, 0x80,

    /* U+00DC "Ü" */
    0x88, 0x23, 0x18, 0x82, 0x2a,

    /* U+00DF "ß" */
    0x52, 0x2d, 0xa1, 0x2, 0x19, 0x80,

    /* U+00E0 "à" */
    0x40, 0x8c, 0x58, 0xb8,

    /* U+00E1 "á" */
    0x8, 0x4, 0xc, 0x9, 0x40, 0x96, 0x0,

    /* U+00E2 "â" */
    0x50, 0x22, 0xc, 0x9, 0x40, 0x96, 0x0,

    /* U+00E3 "ã" */
    0x48, 0x24, 0xc, 0x9, 0x40, 0x96, 0x0,

    /* U+00E4 "ä" */
    0xa3, 0x16, 0x2e,

    /* U+00E5 "å" */
    0x50, 0x23, 0x1d, 0x9, 0x40, 0x96, 0x0,

    /* U+00E6 "æ" */
    0xcc, 0x55, 0x80, 0x93, 0x30,

    /* U+00E7 "ç" */
    0x72, 0x51, 0x94,

    /* U+00E8 "è" */
    0x40, 0x87, 0x70, 0x8c,

    /* U+00E9 "é" */
    0x8, 0x4, 0x5, 0x4b, 0x0, 0x82, 0x80,

    /* U+00EA "ê" */
    0x50, 0x22, 0x5, 0x4b, 0x0, 0x82, 0x80,

    /* U+00EB "ë" */
    0xa1, 0xdc, 0x23,

    /* U+00EC "ì" */
    0x84, 0x88, 0xa0,

    /* U+00ED "í" */
    0x21, 0x8, 0x20, 0x90,

    /* U+00EE "î" */
    0x50, 0x22, 0x4, 0x1, 0x0, 0x42, 0x0,

    /* U+00EF "ï" */
    0x48, 0x24, 0x4, 0x1, 0x0, 0x42, 0x0,

    /* U+00F0 "ð" */
    0x50, 0x22, 0x5, 0x4a, 0x40, 0x96, 0x0,

    /* U+00F1 "ñ" */
    0xa1, 0x4, 0x12,

    /* U+00F2 "ò" */
    0x4c, 0x81, 0x89, 0x2, 0x52,

    /* U+00F3 "ó" */
    0x40, 0x87, 0x68, 0xb8,

    /* U+00F4 "ô" */
    0x8, 0x4, 0x5, 0x4a, 0x40, 0x96, 0x0,

    /* U+00F6 "ö" */
    0x48, 0x24, 0x5, 0x4a, 0x40, 0x96, 0x0,

    /* U+00F7 "÷" */
    0x43, 0x80, 0x80,

    /* U+00F8 "ø" */
    0xa1, 0xda, 0x2e,

    /* U+00F9 "ù" */
    0x40, 0x8b, 0x68, 0xac,

    /* U+00FA "ú" */
    0x8, 0x4, 0x9, 0x4a, 0x40, 0x92, 0x80,

    /* U+00FB "û" */
    0x50, 0x22, 0x9, 0x4a, 0x40, 0x92, 0x80,

    /* U+00FC "ü" */
    0xa2, 0xda, 0x2b,

    /* U+0152 "Œ" */
    0x18, 0x43, 0x58, 0x0, 0xc0, 0x58,

    /* U+0153 "œ" */
    0x19, 0x35, 0x80, 0xc9, 0x40,

    /* U+2022 "•" */
    0xf0,

    /* U+2030 "‰" */
    0x9, 0x20, 0x42, 0x0, 0x9, 0x60, 0x0,

    /* U+20AC "€" */
    0x19, 0x1d, 0x10, 0xd0, 0x4, 0x46,

    /* U+2122 "™" */
    0x7d, 0x5b, 0x56, 0xc4,

    /* U+21E6 "⇦" */
    0x5f, 0xc0, 0x60, 0x2b, 0xf5, 0xf9, 0xc0,

    /* U+21E7 "⇧" */
    0x13, 0xbe, 0xfb, 0xed, 0xa6, 0x9a, 0x78,

    /* U+21E8 "⇨" */
    0xff, 0xbf, 0xb8, 0x7, 0xfb, 0xfe, 0x83, 0xc0,

    /* U+21E9 "⇩" */
    0x79, 0xe7, 0x9e, 0xff, 0xf8, 0x5e, 0x30,

    /* U+220E "∎" */
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff,

    /* U+25B6 "▶" */
    0x8e, 0xff, 0xfe, 0x80,

    /* U+25B7 "▷" */
    0x8e, 0xf9, 0xfe, 0x80,

    /* U+25C6 "◆" */
    0x18, 0xfb, 0xff, 0xf7, 0xcf, 0x86, 0x0,

    /* U+25C7 "◇" */
    0x11, 0xa8, 0x5a, 0x68, 0x40,

    /* U+25CB "○" */
    0x74, 0x63, 0x17, 0x0,

    /* U+25CF "●" */
    0x7b, 0xff, 0xff, 0xfd, 0xe0,

    /* U+27A5 "➥" */
    0xbe, 0xaf, 0xb8, 0x7, 0xfb, 0xfe, 0x83, 0xc0,

    /* U+27A6 "➦" */
    0xff, 0xbf, 0xb8, 0x6, 0xfb, 0xbe, 0x9f, 0xc0
};


/*---------------------
 *  GLYPH DESCRIPTION
 *--------------------*/

static const lv_font_fmt_txt_glyph_dsc_t glyph_dsc[] = {
    {.bitmap_index = 0, .adv_w = 0, .box_w = 0, .box_h = 0, .ofs_x = 0, .ofs_y = 0} /* id = 0 reserved */,
    {.bitmap_index = 0, .adv_w = 20, .box_w = 1, .box_h = 1, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 1, .adv_w = 60, .box_w = 1, .box_h = 1, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 2, .adv_w = 40, .box_w = 1, .box_h = 7, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 3, .adv_w = 80, .box_w = 4, .box_h = 2, .ofs_x = 0, .ofs_y = 6},
    {.bitmap_index = 4, .adv_w = 120, .box_w = 6, .box_h = 5, .ofs_x = 0, .ofs_y = 2},
    {.bitmap_index = 8, .adv_w = 80, .box_w = 3, .box_h = 8, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 11, .adv_w = 100, .box_w = 5, .box_h = 7, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 16, .adv_w = 100, .box_w = 5, .box_h = 6, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 20, .adv_w = 40, .box_w = 1, .box_h = 2, .ofs_x = 0, .ofs_y = 6},
    {.bitmap_index = 21, .adv_w = 80, .box_w = 3, .box_h = 12, .ofs_x = 0, .ofs_y = -2},
    {.bitmap_index = 26, .adv_w = 80, .box_w = 3, .box_h = 12, .ofs_x = 0, .ofs_y = -2},
    {.bitmap_index = 31, .adv_w = 120, .box_w = 6, .box_h = 6, .ofs_x = 0, .ofs_y = 4},
    {.bitmap_index = 36, .adv_w = 80, .box_w = 3, .box_h = 3, .ofs_x = 0, .ofs_y = 3},
    {.bitmap_index = 38, .adv_w = 60, .box_w = 2, .box_h = 2, .ofs_x = 0, .ofs_y = -1},
    {.bitmap_index = 39, .adv_w = 80, .box_w = 3, .box_h = 1, .ofs_x = 0, .ofs_y = 4},
    {.bitmap_index = 40, .adv_w = 40, .box_w = 1, .box_h = 1, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 41, .adv_w = 100, .box_w = 5, .box_h = 9, .ofs_x = 0, .ofs_y = -1},
    {.bitmap_index = 47, .adv_w = 80, .box_w = 3, .box_h = 7, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 50, .adv_w = 80, .box_w = 3, .box_h = 7, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 53, .adv_w = 80, .box_w = 3, .box_h = 7, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 56, .adv_w = 80, .box_w = 3, .box_h = 7, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 59, .adv_w = 100, .box_w = 5, .box_h = 7, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 64, .adv_w = 80, .box_w = 3, .box_h = 7, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 67, .adv_w = 80, .box_w = 3, .box_h = 7, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 70, .adv_w = 80, .box_w = 3, .box_h = 7, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 73, .adv_w = 80, .box_w = 3, .box_h = 7, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 76, .adv_w = 80, .box_w = 3, .box_h = 7, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 79, .adv_w = 60, .box_w = 1, .box_h = 6, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 80, .adv_w = 60, .box_w = 2, .box_h = 7, .ofs_x = 0, .ofs_y = -1},
    {.bitmap_index = 82, .adv_w = 80, .box_w = 3, .box_h = 6, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 85, .adv_w = 100, .box_w = 5, .box_h = 3, .ofs_x = 0, .ofs_y = 3},
    {.bitmap_index = 87, .adv_w = 80, .box_w = 3, .box_h = 6, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 90, .adv_w = 80, .box_w = 3, .box_h = 7, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 93, .adv_w = 120, .box_w = 6, .box_h = 7, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 99, .adv_w = 100, .box_w = 5, .box_h = 7, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 104, .adv_w = 100, .box_w = 5, .box_h = 7, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 109, .adv_w = 100, .box_w = 5, .box_h = 7, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 114, .adv_w = 100, .box_w = 5, .box_h = 7, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 119, .adv_w = 100, .box_w = 5, .box_h = 7, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 124, .adv_w = 100, .box_w = 5, .box_h = 7, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 129, .adv_w = 100, .box_w = 5, .box_h = 7, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 134, .adv_w = 100, .box_w = 5, .box_h = 7, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 139, .adv_w = 80, .box_w = 3, .box_h = 7, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 142, .adv_w = 80, .box_w = 3, .box_h = 7, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 145, .adv_w = 100, .box_w = 5, .box_h = 7, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 150, .adv_w = 80, .box_w = 3, .box_h = 7, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 153, .adv_w = 120, .box_w = 6, .box_h = 7, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 159, .adv_w = 100, .box_w = 5, .box_h = 7, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 164, .adv_w = 100, .box_w = 5, .box_h = 7, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 169, .adv_w = 100, .box_w = 5, .box_h = 7, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 174, .adv_w = 100, .box_w = 5, .box_h = 7, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 179, .adv_w = 100, .box_w = 5, .box_h = 7, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 184, .adv_w = 100, .box_w = 5, .box_h = 7, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 189, .adv_w = 80, .box_w = 3, .box_h = 7, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 192, .adv_w = 100, .box_w = 5, .box_h = 7, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 197, .adv_w = 100, .box_w = 5, .box_h = 7, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 202, .adv_w = 120, .box_w = 6, .box_h = 7, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 208, .adv_w = 80, .box_w = 3, .box_h = 7, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 211, .adv_w = 80, .box_w = 3, .box_h = 7, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 214, .adv_w = 100, .box_w = 5, .box_h = 7, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 219, .adv_w = 80, .box_w = 3, .box_h = 12, .ofs_x = 0, .ofs_y = -2},
    {.bitmap_index = 224, .adv_w = 100, .box_w = 5, .box_h = 9, .ofs_x = 0, .ofs_y = -1},
    {.bitmap_index = 230, .adv_w = 80, .box_w = 3, .box_h = 12, .ofs_x = 0, .ofs_y = -2},
    {.bitmap_index = 235, .adv_w = 80, .box_w = 3, .box_h = 2, .ofs_x = 0, .ofs_y = 7},
    {.bitmap_index = 236, .adv_w = 160, .box_w = 8, .box_h = 1, .ofs_x = 1, .ofs_y = -1},
    {.bitmap_index = 237, .adv_w = 60, .box_w = 2, .box_h = 2, .ofs_x = 0, .ofs_y = 7},
    {.bitmap_index = 238, .adv_w = 80, .box_w = 3, .box_h = 6, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 241, .adv_w = 80, .box_w = 3, .box_h = 7, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 244, .adv_w = 80, .box_w = 3, .box_h = 6, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 247, .adv_w = 80, .box_w = 3, .box_h = 7, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 250, .adv_w = 80, .box_w = 3, .box_h = 6, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 253, .adv_w = 80, .box_w = 3, .box_h = 7, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 256, .adv_w = 80, .box_w = 3, .box_h = 8, .ofs_x = 0, .ofs_y = -2},
    {.bitmap_index = 259, .adv_w = 80, .box_w = 3, .box_h = 7, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 262, .adv_w = 40, .box_w = 1, .box_h = 7, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 263, .adv_w = 60, .box_w = 2, .box_h = 9, .ofs_x = 0, .ofs_y = -2},
    {.bitmap_index = 266, .adv_w = 80, .box_w = 3, .box_h = 7, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 269, .adv_w = 60, .box_w = 2, .box_h = 7, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 271, .adv_w = 120, .box_w = 6, .box_h = 6, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 276, .adv_w = 80, .box_w = 3, .box_h = 6, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 279, .adv_w = 80, .box_w = 3, .box_h = 6, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 282, .adv_w = 80, .box_w = 3, .box_h = 8, .ofs_x = 0, .ofs_y = -2},
    {.bitmap_index = 285, .adv_w = 100, .box_w = 5, .box_h = 8, .ofs_x = 0, .ofs_y = -2},
    {.bitmap_index = 290, .adv_w = 80, .box_w = 3, .box_h = 6, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 293, .adv_w = 80, .box_w = 3, .box_h = 6, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 296, .adv_w = 80, .box_w = 3, .box_h = 7, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 299, .adv_w = 80, .box_w = 3, .box_h = 6, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 302, .adv_w = 80, .box_w = 3, .box_h = 6, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 305, .adv_w = 120, .box_w = 6, .box_h = 6, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 310, .adv_w = 80, .box_w = 3, .box_h = 6, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 313, .adv_w = 80, .box_w = 3, .box_h = 8, .ofs_x = 0, .ofs_y = -2},
    {.bitmap_index = 316, .adv_w = 100, .box_w = 5, .box_h = 6, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 320, .adv_w = 80, .box_w = 3, .box_h = 12, .ofs_x = 0, .ofs_y = -2},
    {.bitmap_index = 325, .adv_w = 40, .box_w = 1, .box_h = 12, .ofs_x = 0, .ofs_y = -2},
    {.bitmap_index = 327, .adv_w = 80, .box_w = 3, .box_h = 12, .ofs_x = 0, .ofs_y = -2},
    {.bitmap_index = 332, .adv_w = 100, .box_w = 5, .box_h = 2, .ofs_x = 0, .ofs_y = 3},
    {.bitmap_index = 334, .adv_w = 40, .box_w = 1, .box_h = 7, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 335, .adv_w = 80, .box_w = 3, .box_h = 7, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 338, .adv_w = 120, .box_w = 6, .box_h = 8, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 344, .adv_w = 140, .box_w = 8, .box_h = 7, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 351, .adv_w = 120, .box_w = 6, .box_h = 8, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 357, .adv_w = 80, .box_w = 3, .box_h = 8, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 360, .adv_w = 160, .box_w = 9, .box_h = 10, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 372, .adv_w = 160, .box_w = 9, .box_h = 10, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 384, .adv_w = 80, .box_w = 3, .box_h = 7, .ofs_x = 0, .ofs_y = -1},
    {.bitmap_index = 387, .adv_w = 140, .box_w = 8, .box_h = 7, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 394, .adv_w = 80, .box_w = 3, .box_h = 7, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 397, .adv_w = 100, .box_w = 5, .box_h = 10, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 404, .adv_w = 100, .box_w = 5, .box_h = 10, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 411, .adv_w = 100, .box_w = 5, .box_h = 10, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 418, .adv_w = 100, .box_w = 5, .box_h = 10, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 425, .adv_w = 100, .box_w = 5, .box_h = 8, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 430, .adv_w = 100, .box_w = 5, .box_h = 10, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 437, .adv_w = 180, .box_w = 10, .box_h = 7, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 446, .adv_w = 100, .box_w = 5, .box_h = 9, .ofs_x = 0, .ofs_y = -2},
    {.bitmap_index = 452, .adv_w = 100, .box_w = 5, .box_h = 10, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 459, .adv_w = 100, .box_w = 5, .box_h = 10, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 466, .adv_w = 100, .box_w = 5, .box_h = 10, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 473, .adv_w = 100, .box_w = 5, .box_h = 8, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 478, .adv_w = 80, .box_w = 3, .box_h = 10, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 482, .adv_w = 100, .box_w = 5, .box_h = 10, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 489, .adv_w = 100, .box_w = 5, .box_h = 10, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 496, .adv_w = 100, .box_w = 5, .box_h = 10, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 503, .adv_w = 80, .box_w = 3, .box_h = 8, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 506, .adv_w = 100, .box_w = 5, .box_h = 10, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 513, .adv_w = 100, .box_w = 5, .box_h = 10, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 520, .adv_w = 100, .box_w = 5, .box_h = 10, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 527, .adv_w = 100, .box_w = 5, .box_h = 10, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 534, .adv_w = 100, .box_w = 5, .box_h = 10, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 541, .adv_w = 100, .box_w = 5, .box_h = 8, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 546, .adv_w = 100, .box_w = 5, .box_h = 10, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 553, .adv_w = 100, .box_w = 5, .box_h = 10, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 560, .adv_w = 100, .box_w = 5, .box_h = 10, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 567, .adv_w = 100, .box_w = 5, .box_h = 8, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 572, .adv_w = 120, .box_w = 6, .box_h = 7, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 578, .adv_w = 80, .box_w = 3, .box_h = 10, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 582, .adv_w = 100, .box_w = 5, .box_h = 10, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 589, .adv_w = 100, .box_w = 5, .box_h = 10, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 596, .adv_w = 100, .box_w = 5, .box_h = 10, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 603, .adv_w = 80, .box_w = 3, .box_h = 8, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 606, .adv_w = 100, .box_w = 5, .box_h = 10, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 613, .adv_w = 120, .box_w = 6, .box_h = 6, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 618, .adv_w = 80, .box_w = 3, .box_h = 8, .ofs_x = 0, .ofs_y = -2},
    {.bitmap_index = 621, .adv_w = 80, .box_w = 3, .box_h = 10, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 625, .adv_w = 100, .box_w = 5, .box_h = 10, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 632, .adv_w = 100, .box_w = 5, .box_h = 10, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 639, .adv_w = 80, .box_w = 3, .box_h = 8, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 642, .adv_w = 80, .box_w = 2, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 645, .adv_w = 100, .box_w = 3, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 649, .adv_w = 100, .box_w = 5, .box_h = 10, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 656, .adv_w = 100, .box_w = 5, .box_h = 10, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 663, .adv_w = 100, .box_w = 5, .box_h = 10, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 670, .adv_w = 80, .box_w = 3, .box_h = 8, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 673, .adv_w = 100, .box_w = 5, .box_h = 8, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 678, .adv_w = 80, .box_w = 3, .box_h = 10, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 682, .adv_w = 100, .box_w = 5, .box_h = 10, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 689, .adv_w = 100, .box_w = 5, .box_h = 10, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 696, .adv_w = 80, .box_w = 3, .box_h = 6, .ofs_x = 0, .ofs_y = 1},
    {.bitmap_index = 699, .adv_w = 80, .box_w = 3, .box_h = 8, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 702, .adv_w = 80, .box_w = 3, .box_h = 10, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 706, .adv_w = 100, .box_w = 5, .box_h = 10, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 713, .adv_w = 100, .box_w = 5, .box_h = 10, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 720, .adv_w = 80, .box_w = 3, .box_h = 8, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 723, .adv_w = 140, .box_w = 8, .box_h = 6, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 729, .adv_w = 120, .box_w = 6, .box_h = 6, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 734, .adv_w = 60, .box_w = 2, .box_h = 2, .ofs_x = 0, .ofs_y = 3},
    {.bitmap_index = 735, .adv_w = 140, .box_w = 7, .box_h = 7, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 742, .adv_w = 120, .box_w = 6, .box_h = 8, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 748, .adv_w = 180, .box_w = 10, .box_h = 3, .ofs_x = 0, .ofs_y = 6},
    {.bitmap_index = 752, .adv_w = 180, .box_w = 9, .box_h = 6, .ofs_x = 0, .ofs_y = 1},
    {.bitmap_index = 759, .adv_w = 120, .box_w = 6, .box_h = 9, .ofs_x = 0, .ofs_y = -1},
    {.bitmap_index = 766, .adv_w = 180, .box_w = 10, .box_h = 6, .ofs_x = 0, .ofs_y = 1},
    {.bitmap_index = 774, .adv_w = 120, .box_w = 6, .box_h = 9, .ofs_x = 0, .ofs_y = -1},
    {.bitmap_index = 781, .adv_w = 140, .box_w = 6, .box_h = 8, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 787, .adv_w = 80, .box_w = 4, .box_h = 7, .ofs_x = 0, .ofs_y = 1},
    {.bitmap_index = 791, .adv_w = 80, .box_w = 4, .box_h = 7, .ofs_x = 0, .ofs_y = 1},
    {.bitmap_index = 795, .adv_w = 120, .box_w = 7, .box_h = 7, .ofs_x = 0, .ofs_y = 1},
    {.bitmap_index = 802, .adv_w = 120, .box_w = 6, .box_h = 6, .ofs_x = 0, .ofs_y = 1},
    {.bitmap_index = 807, .adv_w = 100, .box_w = 5, .box_h = 5, .ofs_x = 0, .ofs_y = 1},
    {.bitmap_index = 811, .adv_w = 100, .box_w = 6, .box_h = 6, .ofs_x = 0, .ofs_y = 1},
    {.bitmap_index = 816, .adv_w = 180, .box_w = 10, .box_h = 6, .ofs_x = 0, .ofs_y = 1},
    {.bitmap_index = 824, .adv_w = 180, .box_w = 10, .box_h = 6, .ofs_x = 0, .ofs_y = 1}
};

/*---------------------
 *  CHARACTER MAPPING
 *--------------------*/

static const uint8_t glyph_id_ofs_list_2[] = {
    0, 1, 2, 3, 4, 0, 5, 0,
    6, 0, 0, 0, 0, 7, 0, 0,
    0, 0, 0, 0, 8, 9, 0, 0,
    0, 0, 0, 0, 0, 0, 10, 11,
    12, 13, 14, 15, 16, 17, 18, 19,
    20, 21, 22, 23, 24, 25, 26, 0,
    27, 28, 29, 30, 31, 32, 0, 33,
    34, 35, 36, 37
};

static const uint16_t unicode_list_4[] = {
    0x0, 0x1, 0x2, 0x3, 0x4, 0x5, 0x6, 0x5c,
    0x5d, 0x1f2c, 0x1f3a, 0x1fb6, 0x202c, 0x20f0, 0x20f1, 0x20f2,
    0x20f3, 0x2118, 0x24c0, 0x24c1, 0x24d0, 0x24d1, 0x24d5, 0x24d9,
    0x26af, 0x26b0
};

/*Collect the unicode lists and glyph_id offsets*/
static const lv_font_fmt_txt_cmap_t cmaps[] =
{
    {
        .range_start = 13, .range_length = 1, .glyph_id_start = 1,
        .unicode_list = NULL, .glyph_id_ofs_list = NULL, .list_length = 0, .type = LV_FONT_FMT_TXT_CMAP_FORMAT0_TINY
    },
    {
        .range_start = 32, .range_length = 95, .glyph_id_start = 2,
        .unicode_list = NULL, .glyph_id_ofs_list = NULL, .list_length = 0, .type = LV_FONT_FMT_TXT_CMAP_FORMAT0_TINY
    },
    {
        .range_start = 161, .range_length = 60, .glyph_id_start = 97,
        .unicode_list = NULL, .glyph_id_ofs_list = glyph_id_ofs_list_2, .list_length = 60, .type = LV_FONT_FMT_TXT_CMAP_FORMAT0_FULL
    },
    {
        .range_start = 223, .range_length = 22, .glyph_id_start = 135,
        .unicode_list = NULL, .glyph_id_ofs_list = NULL, .list_length = 0, .type = LV_FONT_FMT_TXT_CMAP_FORMAT0_TINY
    },
    {
        .range_start = 246, .range_length = 9905, .glyph_id_start = 157,
        .unicode_list = unicode_list_4, .glyph_id_ofs_list = NULL, .list_length = 26, .type = LV_FONT_FMT_TXT_CMAP_SPARSE_TINY
    }
};



/*--------------------
 *  ALL CUSTOM DATA
 *--------------------*/

#if LVGL_VERSION_MAJOR == 8
/*Store all the custom data of the font*/
static  lv_font_fmt_txt_glyph_cache_t cache;
#endif

#if LVGL_VERSION_MAJOR >= 8
static const lv_font_fmt_txt_dsc_t font_dsc = {
#else
static lv_font_fmt_txt_dsc_t font_dsc = {
#endif
    .glyph_bitmap = glyph_bitmap,
    .glyph_dsc = glyph_dsc,
    .cmaps = cmaps,
    .kern_dsc = NULL,
    .kern_scale = 0,
    .cmap_num = 5,
    .bpp = 1,
    .kern_classes = 0,
    .bitmap_format = 0,
#if LVGL_VERSION_MAJOR == 8
    .cache = &cache
#endif

};


/*-----------------
 *  PUBLIC FONT
 *----------------*/

/*Initialize a public general font descriptor*/
#if LVGL_VERSION_MAJOR >= 8
const lv_font_t low_gothic_8x10 = {
#else
lv_font_t low_gothic_8x10 = {
#endif
    .get_glyph_dsc = lv_font_get_glyph_dsc_fmt_txt,    /*Function pointer to get glyph's data*/
    .get_glyph_bitmap = lv_font_get_bitmap_fmt_txt,    /*Function pointer to get glyph's bitmap*/
    .line_height = 12,          /*The maximum line height required by the font*/
    .base_line = 2,             /*Baseline measured from the bottom of the line*/
#if !(LVGL_VERSION_MAJOR == 6 && LVGL_VERSION_MINOR == 0)
    .subpx = LV_FONT_SUBPX_NONE,
#endif
#if LV_VERSION_CHECK(7, 4, 0) || LVGL_VERSION_MAJOR >= 8
    .underline_position = 1,
    .underline_thickness = 0,
#endif
    .static_bitmap = 0,
    .dsc = &font_dsc,          /*The custom font data. Will be accessed by `get_glyph_bitmap/dsc` */
#if LV_VERSION_CHECK(8, 2, 0) || LVGL_VERSION_MAJOR >= 9
    .fallback = NULL,
#endif
    .user_data = NULL,
};



#endif /*#if LOW_GOTHIC_8X10*/
