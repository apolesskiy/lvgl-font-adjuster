/*******************************************************************************
 * Adapted from Low Gothic by Patrik Arts https://patrik-arts.itch.io/pixel-font-low-gothic
 * Size: 8 px
 * Bpp: 1
 * Opts: --bpp 1 --size 8 --no-compress --stride 1 --align 1 --font LowGothic_8x10_Regular.ttf --range 0-65535 --format lvgl -o low_gothic_8x10.c
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
    0xf4,

    /* U+0022 "\"" */
    0xb4,

    /* U+0023 "#" */
    0x57, 0xd5, 0xf5, 0x0,

    /* U+0024 "$" */
    0x4e, 0x73, 0x90,

    /* U+0025 "%" */
    0x1a, 0x24, 0x58,

    /* U+0026 "&" */
    0x4a, 0x7a, 0xd0,

    /* U+0027 "'" */
    0xc0,

    /* U+0028 "(" */
    0x29, 0x49, 0x22, 0x44,

    /* U+0029 ")" */
    0x89, 0x12, 0x4a, 0x50,

    /* U+002A "*" */
    0x25, 0x5d, 0x52, 0x0,

    /* U+002B "+" */
    0x5d, 0x0,

    /* U+002C "," */
    0x60,

    /* U+002D "-" */
    0xe0,

    /* U+002E "." */
    0x80,

    /* U+002F "/" */
    0x11, 0x22, 0x44, 0x88,

    /* U+0030 "0" */
    0x76, 0xdb, 0x80,

    /* U+0031 "1" */
    0x59, 0x25, 0xc0,

    /* U+0032 "2" */
    0x74, 0xa9, 0xc0,

    /* U+0033 "3" */
    0xc5, 0x13, 0x80,

    /* U+0034 "4" */
    0x8a, 0xaf, 0x22,

    /* U+0035 "5" */
    0xf3, 0x13, 0x80,

    /* U+0036 "6" */
    0x73, 0xdb, 0x80,

    /* U+0037 "7" */
    0xe4, 0xa4, 0x80,

    /* U+0038 "8" */
    0x77, 0xdb, 0x80,

    /* U+0039 "9" */
    0x76, 0xf3, 0x80,

    /* U+003A ":" */
    0x88,

    /* U+003B ";" */
    0x40, 0x60,

    /* U+003C "<" */
    0x2a, 0x22,

    /* U+003D "=" */
    0xf0, 0xf0,

    /* U+003E ">" */
    0x88, 0xa8,

    /* U+003F "?" */
    0x74, 0xa0, 0x80,

    /* U+0040 "@" */
    0x74, 0x6f, 0x78, 0x38,

    /* U+0041 "A" */
    0x69, 0x9f, 0x99,

    /* U+0042 "B" */
    0x79, 0xe9, 0x9e,

    /* U+0043 "C" */
    0x79, 0x88, 0x9e,

    /* U+0044 "D" */
    0xe9, 0x99, 0x9e,

    /* U+0045 "E" */
    0x78, 0x8e, 0x8f,

    /* U+0046 "F" */
    0x78, 0x8e, 0x88,

    /* U+0047 "G" */
    0x69, 0x8b, 0x9e,

    /* U+0048 "H" */
    0x99, 0x9f, 0x99,

    /* U+0049 "I" */
    0xe9, 0x25, 0xc0,

    /* U+004A "J" */
    0xe9, 0x25, 0x0,

    /* U+004B "K" */
    0x99, 0xae, 0x99,

    /* U+004C "L" */
    0x92, 0x48, 0xc0,

    /* U+004D "M" */
    0x8c, 0x77, 0xba, 0xc4,

    /* U+004E "N" */
    0x99, 0xdd, 0xb9,

    /* U+004F "O" */
    0x79, 0x99, 0x9e,

    /* U+0050 "P" */
    0x79, 0x9e, 0x88,

    /* U+0051 "Q" */
    0x79, 0x99, 0xad,

    /* U+0052 "R" */
    0xe9, 0x99, 0xe9,

    /* U+0053 "S" */
    0x78, 0x61, 0x96,

    /* U+0054 "T" */
    0xe9, 0x24, 0x80,

    /* U+0055 "U" */
    0x99, 0x99, 0x96,

    /* U+0056 "V" */
    0x99, 0x99, 0xa4,

    /* U+0057 "W" */
    0x8c, 0x6b, 0x5a, 0xe8,

    /* U+0058 "X" */
    0xb6, 0xab, 0x40,

    /* U+0059 "Y" */
    0xb6, 0xd4, 0x80,

    /* U+005A "Z" */
    0xf1, 0x24, 0x8f,

    /* U+005B "[" */
    0xf2, 0x49, 0x24, 0x9c,

    /* U+005C "\\" */
    0x88, 0x44, 0x22, 0x11,

    /* U+005D "]" */
    0xe4, 0x92, 0x49, 0x3c,

    /* U+005E "^" */
    0x54,

    /* U+005F "_" */
    0xfc,

    /* U+0060 "`" */
    0x90,

    /* U+0061 "a" */
    0xc5, 0xdc,

    /* U+0062 "b" */
    0x9a, 0xdb, 0xc0,

    /* U+0063 "c" */
    0x72, 0x5c,

    /* U+0064 "d" */
    0x2e, 0xdb, 0xc0,

    /* U+0065 "e" */
    0x77, 0x46,

    /* U+0066 "f" */
    0x29, 0x74, 0x80,

    /* U+0067 "g" */
    0x76, 0xde, 0x70,

    /* U+0068 "h" */
    0x9a, 0xdb, 0x40,

    /* U+0069 "i" */
    0xbc,

    /* U+006A "j" */
    0x45, 0x56,

    /* U+006B "k" */
    0x97, 0x5b, 0x40,

    /* U+006C "l" */
    0xaa, 0x90,

    /* U+006D "m" */
    0xd5, 0x6b, 0x5a, 0x80,

    /* U+006E "n" */
    0xd6, 0xda,

    /* U+006F "o" */
    0x76, 0xdc,

    /* U+0070 "p" */
    0x76, 0xdd, 0x20,

    /* U+0071 "q" */
    0x6a, 0xaa, 0xe3, 0x20,

    /* U+0072 "r" */
    0x72, 0x48,

    /* U+0073 "s" */
    0x73, 0x9c,

    /* U+0074 "t" */
    0x4b, 0xa4, 0x40,

    /* U+0075 "u" */
    0xb6, 0xd6,

    /* U+0076 "v" */
    0xb6, 0xd4,

    /* U+0077 "w" */
    0xad, 0x6b, 0x5d, 0x0,

    /* U+0078 "x" */
    0xb5, 0x5a,

    /* U+0079 "y" */
    0xb6, 0xd6, 0x70,

    /* U+007A "z" */
    0xf1, 0x68, 0xf0,

    /* U+007B "{" */
    0x29, 0x28, 0x92, 0x44,

    /* U+007C "|" */
    0xff, 0xc0,

    /* U+007D "}" */
    0x89, 0x22, 0x92, 0x50,

    /* U+007E "~" */
    0x5a,

    /* U+00A1 "¡" */
    0xbc,

    /* U+00A2 "¢" */
    0x4e, 0x5c, 0x80,

    /* U+00A3 "£" */
    0x32, 0x51, 0xc4, 0x32, 0x60,

    /* U+00A4 "¤" */
    0xb5, 0x28, 0x61, 0x4a, 0xd0,

    /* U+00A5 "¥" */
    0x52, 0x95, 0xf2, 0x7c, 0x80,

    /* U+00A7 "§" */
    0x71, 0x56, 0x70,

    /* U+00A9 "©" */
    0x38, 0x8a, 0x6d, 0x1a, 0xb6, 0x51, 0x1c,

    /* U+00AE "®" */
    0x38, 0x8a, 0x6d, 0x5b, 0x35, 0x51, 0x1c,

    /* U+00B5 "µ" */
    0xb6, 0xdf, 0x0,

    /* U+00B6 "¶" */
    0x7f, 0xae, 0xba, 0x28, 0xa0,

    /* U+00BF "¿" */
    0x41, 0x4b, 0x80,

    /* U+00C0 "À" */
    0x42, 0x6, 0x9f, 0x99,

    /* U+00C1 "Á" */
    0x12, 0x6, 0x9f, 0x99,

    /* U+00C2 "Â" */
    0x69, 0x6, 0x9f, 0x99,

    /* U+00C3 "Ã" */
    0x5a, 0x6, 0x9f, 0x99,

    /* U+00C4 "Ä" */
    0x90, 0x69, 0xf9, 0x90,

    /* U+00C5 "Å" */
    0x69, 0x96, 0x9f, 0x99,

    /* U+00C6 "Æ" */
    0x1f, 0x28, 0x48, 0x7e, 0x88, 0x87,

    /* U+00C7 "Ç" */
    0x79, 0x88, 0x9e, 0x24,

    /* U+00C8 "È" */
    0x42, 0x7, 0x8e, 0x8f,

    /* U+00C9 "É" */
    0x12, 0x7, 0x8e, 0x8f,

    /* U+00CA "Ê" */
    0x69, 0x7, 0x8e, 0x8f,

    /* U+00CB "Ë" */
    0x90, 0x78, 0xe8, 0xf0,

    /* U+00CC "Ì" */
    0x44, 0x74, 0x97,

    /* U+00CD "Í" */
    0x12, 0xe, 0x44, 0x4e,

    /* U+00CE "Î" */
    0x69, 0xe, 0x44, 0x4e,

    /* U+00CF "Ï" */
    0x5a, 0xe, 0x44, 0x4e,

    /* U+00D1 "Ñ" */
    0xa3, 0xa4, 0xb8,

    /* U+00D2 "Ò" */
    0x5a, 0x9, 0x9d, 0xb9,

    /* U+00D3 "Ó" */
    0x42, 0x7, 0x99, 0x9e,

    /* U+00D4 "Ô" */
    0x12, 0x7, 0x99, 0x9e,

    /* U+00D5 "Õ" */
    0x69, 0x7, 0x99, 0x9e,

    /* U+00D6 "Ö" */
    0x5a, 0x7, 0x99, 0x9e,

    /* U+00D8 "Ø" */
    0xa0, 0x79, 0x99, 0xe0,

    /* U+00D9 "Ù" */
    0x42, 0x9, 0x99, 0x96,

    /* U+00DA "Ú" */
    0x12, 0x9, 0x99, 0x96,

    /* U+00DB "Û" */
    0x69, 0x9, 0x99, 0x96,

    /* U+00DC "Ü" */
    0x90, 0x99, 0x99, 0x60,

    /* U+00DF "ß" */
    0x64, 0xbd, 0x18, 0xd8,

    /* U+00E0 "à" */
    0x44, 0x62, 0xee,

    /* U+00E1 "á" */
    0x12, 0xc, 0x26, 0xac,

    /* U+00E2 "â" */
    0x69, 0xc, 0x26, 0xac,

    /* U+00E3 "ã" */
    0x5a, 0xc, 0x26, 0xac,

    /* U+00E4 "ä" */
    0xa3, 0x17, 0x70,

    /* U+00E5 "å" */
    0x69, 0x9e, 0x26, 0xac,

    /* U+00E6 "æ" */
    0xd9, 0x5d, 0x4d, 0x80,

    /* U+00E7 "ç" */
    0x72, 0x5c, 0xa0,

    /* U+00E8 "è" */
    0x44, 0x3b, 0xa3,

    /* U+00E9 "é" */
    0x12, 0x6, 0xac, 0x86,

    /* U+00EA "ê" */
    0x69, 0x6, 0xac, 0x86,

    /* U+00EB "ë" */
    0xa1, 0xdd, 0x18,

    /* U+00EC "ì" */
    0x92, 0x2a,

    /* U+00ED "í" */
    0x28, 0x41, 0x24,

    /* U+00EE "î" */
    0x69, 0x4, 0x4, 0x44,

    /* U+00EF "ï" */
    0x5a, 0x4, 0x4, 0x44,

    /* U+00F0 "ð" */
    0x69, 0x6, 0xaa, 0xac,

    /* U+00F1 "ñ" */
    0xa1, 0x4, 0x90,

    /* U+00F2 "ò" */
    0x5a, 0xc, 0xaa, 0xa0,

    /* U+00F3 "ó" */
    0x44, 0x3b, 0x6e,

    /* U+00F4 "ô" */
    0x12, 0x6, 0xaa, 0xac,

    /* U+00F6 "ö" */
    0x5a, 0x6, 0xaa, 0xac,

    /* U+00F7 "÷" */
    0x43, 0x84,

    /* U+00F8 "ø" */
    0xa1, 0xdb, 0x70,

    /* U+00F9 "ù" */
    0x44, 0x5b, 0x6b,

    /* U+00FA "ú" */
    0x12, 0xa, 0xaa, 0xa6,

    /* U+00FB "û" */
    0x69, 0xa, 0xaa, 0xa6,

    /* U+00FC "ü" */
    0xa2, 0xdb, 0x58,

    /* U+0152 "Œ" */
    0x39, 0x37, 0xb2, 0x70,

    /* U+0153 "œ" */
    0x32, 0xdd, 0xa6, 0x0,

    /* U+2022 "•" */
    0xf0,

    /* U+2030 "‰" */
    0x12, 0x82, 0x10, 0x56, 0x0,

    /* U+20AC "€" */
    0x32, 0x78, 0x8e, 0x24, 0xc0,

    /* U+2122 "™" */
    0x7b, 0x7b, 0x79,

    /* U+21E6 "⇦" */
    0x5f, 0x81, 0x5f, 0x5f, 0x38,

    /* U+21E7 "⇧" */
    0x17, 0x7b, 0xd6, 0xb5, 0xaf,

    /* U+21E8 "⇨" */
    0xfe, 0xff, 0xff, 0xfe, 0xe,

    /* U+21E9 "⇩" */
    0x7b, 0xdf, 0xff, 0xc5, 0xe6,

    /* U+220E "∎" */
    0xff, 0xff, 0xff, 0xff, 0xe0,

    /* U+25B6 "▶" */
    0x8e, 0xff, 0xe8,

    /* U+25B7 "▷" */
    0x9b, 0xfd, 0x0,

    /* U+25C6 "◆" */
    0x11, 0xef, 0xde, 0x78, 0x40,

    /* U+25C7 "◇" */
    0x22, 0xa2, 0xa2, 0x0,

    /* U+25CB "○" */
    0xf9, 0x97,

    /* U+25CF "●" */
    0x77, 0xff, 0xf7, 0x0,

    /* U+27A5 "➥" */
    0xbe, 0xbf, 0xff, 0xfe, 0xe,

    /* U+27A6 "➦" */
    0xfe, 0xff, 0xbf, 0xbe, 0x7e
};


/*---------------------
 *  GLYPH DESCRIPTION
 *--------------------*/

static const lv_font_fmt_txt_glyph_dsc_t glyph_dsc[] = {
    {.bitmap_index = 0, .adv_w = 0, .box_w = 0, .box_h = 0, .ofs_x = 0, .ofs_y = 0} /* id = 0 reserved */,
    {.bitmap_index = 0, .adv_w = 16, .box_w = 1, .box_h = 1, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 1, .adv_w = 48, .box_w = 1, .box_h = 1, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 2, .adv_w = 32, .box_w = 1, .box_h = 6, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 3, .adv_w = 64, .box_w = 3, .box_h = 2, .ofs_x = 0, .ofs_y = 5},
    {.bitmap_index = 4, .adv_w = 96, .box_w = 5, .box_h = 5, .ofs_x = 0, .ofs_y = 1},
    {.bitmap_index = 8, .adv_w = 64, .box_w = 3, .box_h = 7, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 11, .adv_w = 80, .box_w = 4, .box_h = 6, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 14, .adv_w = 80, .box_w = 4, .box_h = 5, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 17, .adv_w = 32, .box_w = 1, .box_h = 2, .ofs_x = 0, .ofs_y = 5},
    {.bitmap_index = 18, .adv_w = 64, .box_w = 3, .box_h = 10, .ofs_x = 0, .ofs_y = -2},
    {.bitmap_index = 22, .adv_w = 64, .box_w = 3, .box_h = 10, .ofs_x = 0, .ofs_y = -2},
    {.bitmap_index = 26, .adv_w = 96, .box_w = 5, .box_h = 5, .ofs_x = 0, .ofs_y = 3},
    {.bitmap_index = 30, .adv_w = 64, .box_w = 3, .box_h = 3, .ofs_x = 0, .ofs_y = 2},
    {.bitmap_index = 32, .adv_w = 48, .box_w = 2, .box_h = 2, .ofs_x = 0, .ofs_y = -1},
    {.bitmap_index = 33, .adv_w = 64, .box_w = 3, .box_h = 1, .ofs_x = 0, .ofs_y = 3},
    {.bitmap_index = 34, .adv_w = 32, .box_w = 1, .box_h = 1, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 35, .adv_w = 80, .box_w = 4, .box_h = 8, .ofs_x = 0, .ofs_y = -1},
    {.bitmap_index = 39, .adv_w = 64, .box_w = 3, .box_h = 6, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 42, .adv_w = 64, .box_w = 3, .box_h = 6, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 45, .adv_w = 64, .box_w = 3, .box_h = 6, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 48, .adv_w = 64, .box_w = 3, .box_h = 6, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 51, .adv_w = 80, .box_w = 4, .box_h = 6, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 54, .adv_w = 64, .box_w = 3, .box_h = 6, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 57, .adv_w = 64, .box_w = 3, .box_h = 6, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 60, .adv_w = 64, .box_w = 3, .box_h = 6, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 63, .adv_w = 64, .box_w = 3, .box_h = 6, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 66, .adv_w = 64, .box_w = 3, .box_h = 6, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 69, .adv_w = 48, .box_w = 1, .box_h = 5, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 70, .adv_w = 48, .box_w = 2, .box_h = 6, .ofs_x = 0, .ofs_y = -1},
    {.bitmap_index = 72, .adv_w = 64, .box_w = 3, .box_h = 5, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 74, .adv_w = 80, .box_w = 4, .box_h = 3, .ofs_x = 0, .ofs_y = 2},
    {.bitmap_index = 76, .adv_w = 64, .box_w = 3, .box_h = 5, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 78, .adv_w = 64, .box_w = 3, .box_h = 6, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 81, .adv_w = 96, .box_w = 5, .box_h = 6, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 85, .adv_w = 80, .box_w = 4, .box_h = 6, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 88, .adv_w = 80, .box_w = 4, .box_h = 6, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 91, .adv_w = 80, .box_w = 4, .box_h = 6, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 94, .adv_w = 80, .box_w = 4, .box_h = 6, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 97, .adv_w = 80, .box_w = 4, .box_h = 6, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 100, .adv_w = 80, .box_w = 4, .box_h = 6, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 103, .adv_w = 80, .box_w = 4, .box_h = 6, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 106, .adv_w = 80, .box_w = 4, .box_h = 6, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 109, .adv_w = 64, .box_w = 3, .box_h = 6, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 112, .adv_w = 64, .box_w = 3, .box_h = 6, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 115, .adv_w = 80, .box_w = 4, .box_h = 6, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 118, .adv_w = 64, .box_w = 3, .box_h = 6, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 121, .adv_w = 96, .box_w = 5, .box_h = 6, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 125, .adv_w = 80, .box_w = 4, .box_h = 6, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 128, .adv_w = 80, .box_w = 4, .box_h = 6, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 131, .adv_w = 80, .box_w = 4, .box_h = 6, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 134, .adv_w = 80, .box_w = 4, .box_h = 6, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 137, .adv_w = 80, .box_w = 4, .box_h = 6, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 140, .adv_w = 80, .box_w = 4, .box_h = 6, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 143, .adv_w = 64, .box_w = 3, .box_h = 6, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 146, .adv_w = 80, .box_w = 4, .box_h = 6, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 149, .adv_w = 80, .box_w = 4, .box_h = 6, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 152, .adv_w = 96, .box_w = 5, .box_h = 6, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 156, .adv_w = 64, .box_w = 3, .box_h = 6, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 159, .adv_w = 64, .box_w = 3, .box_h = 6, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 162, .adv_w = 80, .box_w = 4, .box_h = 6, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 165, .adv_w = 64, .box_w = 3, .box_h = 10, .ofs_x = 0, .ofs_y = -2},
    {.bitmap_index = 169, .adv_w = 80, .box_w = 4, .box_h = 8, .ofs_x = 0, .ofs_y = -1},
    {.bitmap_index = 173, .adv_w = 64, .box_w = 3, .box_h = 10, .ofs_x = 0, .ofs_y = -2},
    {.bitmap_index = 177, .adv_w = 64, .box_w = 3, .box_h = 2, .ofs_x = 0, .ofs_y = 6},
    {.bitmap_index = 178, .adv_w = 128, .box_w = 6, .box_h = 1, .ofs_x = 1, .ofs_y = -1},
    {.bitmap_index = 179, .adv_w = 48, .box_w = 2, .box_h = 2, .ofs_x = 0, .ofs_y = 6},
    {.bitmap_index = 180, .adv_w = 64, .box_w = 3, .box_h = 5, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 182, .adv_w = 64, .box_w = 3, .box_h = 6, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 185, .adv_w = 64, .box_w = 3, .box_h = 5, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 187, .adv_w = 64, .box_w = 3, .box_h = 6, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 190, .adv_w = 64, .box_w = 3, .box_h = 5, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 192, .adv_w = 64, .box_w = 3, .box_h = 6, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 195, .adv_w = 64, .box_w = 3, .box_h = 7, .ofs_x = 0, .ofs_y = -2},
    {.bitmap_index = 198, .adv_w = 64, .box_w = 3, .box_h = 6, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 201, .adv_w = 32, .box_w = 1, .box_h = 6, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 202, .adv_w = 48, .box_w = 2, .box_h = 8, .ofs_x = 0, .ofs_y = -2},
    {.bitmap_index = 204, .adv_w = 64, .box_w = 3, .box_h = 6, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 207, .adv_w = 48, .box_w = 2, .box_h = 6, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 209, .adv_w = 96, .box_w = 5, .box_h = 5, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 213, .adv_w = 64, .box_w = 3, .box_h = 5, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 215, .adv_w = 64, .box_w = 3, .box_h = 5, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 217, .adv_w = 64, .box_w = 3, .box_h = 7, .ofs_x = 0, .ofs_y = -2},
    {.bitmap_index = 220, .adv_w = 80, .box_w = 4, .box_h = 7, .ofs_x = 0, .ofs_y = -2},
    {.bitmap_index = 224, .adv_w = 64, .box_w = 3, .box_h = 5, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 226, .adv_w = 64, .box_w = 3, .box_h = 5, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 228, .adv_w = 64, .box_w = 3, .box_h = 6, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 231, .adv_w = 64, .box_w = 3, .box_h = 5, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 233, .adv_w = 64, .box_w = 3, .box_h = 5, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 235, .adv_w = 96, .box_w = 5, .box_h = 5, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 239, .adv_w = 64, .box_w = 3, .box_h = 5, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 241, .adv_w = 64, .box_w = 3, .box_h = 7, .ofs_x = 0, .ofs_y = -2},
    {.bitmap_index = 244, .adv_w = 80, .box_w = 4, .box_h = 5, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 247, .adv_w = 64, .box_w = 3, .box_h = 10, .ofs_x = 0, .ofs_y = -2},
    {.bitmap_index = 251, .adv_w = 32, .box_w = 1, .box_h = 10, .ofs_x = 0, .ofs_y = -2},
    {.bitmap_index = 253, .adv_w = 64, .box_w = 3, .box_h = 10, .ofs_x = 0, .ofs_y = -2},
    {.bitmap_index = 257, .adv_w = 80, .box_w = 4, .box_h = 2, .ofs_x = 0, .ofs_y = 2},
    {.bitmap_index = 258, .adv_w = 32, .box_w = 1, .box_h = 6, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 259, .adv_w = 64, .box_w = 3, .box_h = 6, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 262, .adv_w = 96, .box_w = 5, .box_h = 7, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 267, .adv_w = 112, .box_w = 6, .box_h = 6, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 272, .adv_w = 96, .box_w = 5, .box_h = 7, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 277, .adv_w = 64, .box_w = 3, .box_h = 7, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 280, .adv_w = 128, .box_w = 7, .box_h = 8, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 287, .adv_w = 128, .box_w = 7, .box_h = 8, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 294, .adv_w = 64, .box_w = 3, .box_h = 6, .ofs_x = 0, .ofs_y = -1},
    {.bitmap_index = 297, .adv_w = 112, .box_w = 6, .box_h = 6, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 302, .adv_w = 64, .box_w = 3, .box_h = 6, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 305, .adv_w = 80, .box_w = 4, .box_h = 8, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 309, .adv_w = 80, .box_w = 4, .box_h = 8, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 313, .adv_w = 80, .box_w = 4, .box_h = 8, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 317, .adv_w = 80, .box_w = 4, .box_h = 8, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 321, .adv_w = 80, .box_w = 4, .box_h = 7, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 325, .adv_w = 80, .box_w = 4, .box_h = 8, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 329, .adv_w = 144, .box_w = 8, .box_h = 6, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 335, .adv_w = 80, .box_w = 4, .box_h = 8, .ofs_x = 0, .ofs_y = -2},
    {.bitmap_index = 339, .adv_w = 80, .box_w = 4, .box_h = 8, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 343, .adv_w = 80, .box_w = 4, .box_h = 8, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 347, .adv_w = 80, .box_w = 4, .box_h = 8, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 351, .adv_w = 80, .box_w = 4, .box_h = 7, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 355, .adv_w = 64, .box_w = 3, .box_h = 8, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 358, .adv_w = 80, .box_w = 4, .box_h = 8, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 362, .adv_w = 80, .box_w = 4, .box_h = 8, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 366, .adv_w = 80, .box_w = 4, .box_h = 8, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 370, .adv_w = 64, .box_w = 3, .box_h = 7, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 373, .adv_w = 80, .box_w = 4, .box_h = 8, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 377, .adv_w = 80, .box_w = 4, .box_h = 8, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 381, .adv_w = 80, .box_w = 4, .box_h = 8, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 385, .adv_w = 80, .box_w = 4, .box_h = 8, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 389, .adv_w = 80, .box_w = 4, .box_h = 8, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 393, .adv_w = 80, .box_w = 4, .box_h = 7, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 397, .adv_w = 80, .box_w = 4, .box_h = 8, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 401, .adv_w = 80, .box_w = 4, .box_h = 8, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 405, .adv_w = 80, .box_w = 4, .box_h = 8, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 409, .adv_w = 80, .box_w = 4, .box_h = 7, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 413, .adv_w = 96, .box_w = 5, .box_h = 6, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 417, .adv_w = 64, .box_w = 3, .box_h = 8, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 420, .adv_w = 80, .box_w = 4, .box_h = 8, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 424, .adv_w = 80, .box_w = 4, .box_h = 8, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 428, .adv_w = 80, .box_w = 4, .box_h = 8, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 432, .adv_w = 64, .box_w = 3, .box_h = 7, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 435, .adv_w = 80, .box_w = 4, .box_h = 8, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 439, .adv_w = 96, .box_w = 5, .box_h = 5, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 443, .adv_w = 64, .box_w = 3, .box_h = 7, .ofs_x = 0, .ofs_y = -2},
    {.bitmap_index = 446, .adv_w = 64, .box_w = 3, .box_h = 8, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 449, .adv_w = 80, .box_w = 4, .box_h = 8, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 453, .adv_w = 80, .box_w = 4, .box_h = 8, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 457, .adv_w = 64, .box_w = 3, .box_h = 7, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 460, .adv_w = 64, .box_w = 2, .box_h = 8, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 462, .adv_w = 80, .box_w = 3, .box_h = 8, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 465, .adv_w = 80, .box_w = 4, .box_h = 8, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 469, .adv_w = 80, .box_w = 4, .box_h = 8, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 473, .adv_w = 80, .box_w = 4, .box_h = 8, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 477, .adv_w = 64, .box_w = 3, .box_h = 7, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 480, .adv_w = 80, .box_w = 4, .box_h = 7, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 484, .adv_w = 64, .box_w = 3, .box_h = 8, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 487, .adv_w = 80, .box_w = 4, .box_h = 8, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 491, .adv_w = 80, .box_w = 4, .box_h = 8, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 495, .adv_w = 64, .box_w = 3, .box_h = 5, .ofs_x = 0, .ofs_y = 1},
    {.bitmap_index = 497, .adv_w = 64, .box_w = 3, .box_h = 7, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 500, .adv_w = 64, .box_w = 3, .box_h = 8, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 503, .adv_w = 80, .box_w = 4, .box_h = 8, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 507, .adv_w = 80, .box_w = 4, .box_h = 8, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 511, .adv_w = 64, .box_w = 3, .box_h = 7, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 514, .adv_w = 112, .box_w = 6, .box_h = 5, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 518, .adv_w = 96, .box_w = 5, .box_h = 5, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 522, .adv_w = 48, .box_w = 2, .box_h = 2, .ofs_x = 0, .ofs_y = 2},
    {.bitmap_index = 523, .adv_w = 112, .box_w = 6, .box_h = 6, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 528, .adv_w = 96, .box_w = 5, .box_h = 7, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 533, .adv_w = 144, .box_w = 8, .box_h = 3, .ofs_x = 0, .ofs_y = 5},
    {.bitmap_index = 536, .adv_w = 144, .box_w = 8, .box_h = 5, .ofs_x = 0, .ofs_y = 1},
    {.bitmap_index = 541, .adv_w = 96, .box_w = 5, .box_h = 8, .ofs_x = 0, .ofs_y = -1},
    {.bitmap_index = 546, .adv_w = 144, .box_w = 8, .box_h = 5, .ofs_x = 0, .ofs_y = 1},
    {.bitmap_index = 551, .adv_w = 96, .box_w = 5, .box_h = 8, .ofs_x = 0, .ofs_y = -1},
    {.bitmap_index = 556, .adv_w = 112, .box_w = 5, .box_h = 7, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 561, .adv_w = 64, .box_w = 4, .box_h = 6, .ofs_x = 0, .ofs_y = 1},
    {.bitmap_index = 564, .adv_w = 64, .box_w = 3, .box_h = 6, .ofs_x = 0, .ofs_y = 1},
    {.bitmap_index = 567, .adv_w = 96, .box_w = 6, .box_h = 6, .ofs_x = 0, .ofs_y = 1},
    {.bitmap_index = 572, .adv_w = 96, .box_w = 5, .box_h = 5, .ofs_x = 0, .ofs_y = 1},
    {.bitmap_index = 576, .adv_w = 80, .box_w = 4, .box_h = 4, .ofs_x = 0, .ofs_y = 1},
    {.bitmap_index = 578, .adv_w = 80, .box_w = 5, .box_h = 5, .ofs_x = 0, .ofs_y = 1},
    {.bitmap_index = 582, .adv_w = 144, .box_w = 8, .box_h = 5, .ofs_x = 0, .ofs_y = 1},
    {.bitmap_index = 587, .adv_w = 144, .box_w = 8, .box_h = 5, .ofs_x = 0, .ofs_y = 1}
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
    .line_height = 10,          /*The maximum line height required by the font*/
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
