/*******************************************************************************
 * Size: 5 px
 * Bpp: 1
 * Opts: --bpp 1 --size 5 --no-compress --stride 1 --align 1 --font my 3x5 tiny mono pixel font.ttf --range 0-65535 --format lvgl -o tiny_mono_3x5.c
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



#ifndef TINY_MONO_3X5
#define TINY_MONO_3X5 1
#endif

#if TINY_MONO_3X5

/*-----------------
 *    BITMAPS
 *----------------*/

/*Store the image of the glyphs*/
static LV_ATTRIBUTE_LARGE_CONST const uint8_t glyph_bitmap[] = {
    /* U+0020 " " */
    0x0,

    /* U+0021 "!" */
    0x90,

    /* U+0022 "\"" */
    0xa0,

    /* U+0023 "#" */
    0xbf, 0xd0,

    /* U+0024 "$" */
    0x7b, 0xa0,

    /* U+0025 "%" */
    0xa1, 0x50,

    /* U+0026 "&" */
    0x7a, 0xb0,

    /* U+0027 "'" */
    0x80,

    /* U+0028 "(" */
    0x61,

    /* U+0029 ")" */
    0x92,

    /* U+002A "*" */
    0xaa, 0x80,

    /* U+002B "+" */
    0xa8,

    /* U+002C "," */
    0x60,

    /* U+002D "-" */
    0xc0,

    /* U+002E "." */
    0x80,

    /* U+002F "/" */
    0x21, 0x40,

    /* U+0030 "0" */
    0xf6, 0xf0,

    /* U+0031 "1" */
    0xc9, 0x70,

    /* U+0032 "2" */
    0xe7, 0xf0,

    /* U+0033 "3" */
    0xe5, 0xf0,

    /* U+0034 "4" */
    0xb7, 0x90,

    /* U+0035 "5" */
    0xf3, 0xf0,

    /* U+0036 "6" */
    0xf3, 0xf0,

    /* U+0037 "7" */
    0xe4, 0x90,

    /* U+0038 "8" */
    0xf7, 0xf0,

    /* U+0039 "9" */
    0xf7, 0xf0,

    /* U+003A ":" */
    0xa0,

    /* U+003B ";" */
    0x58,

    /* U+003C "<" */
    0x2b, 0x10,

    /* U+003D "=" */
    0xe3, 0x80,

    /* U+003E ">" */
    0x89, 0xc0,

    /* U+003F "?" */
    0xe5, 0xa0,

    /* U+0040 "@" */
    0x54, 0x30,

    /* U+0041 "A" */
    0x57, 0xd0,

    /* U+0042 "B" */
    0xd7, 0xe0,

    /* U+0043 "C" */
    0x70, 0x30,

    /* U+0044 "D" */
    0xd6, 0x60,

    /* U+0045 "E" */
    0xf3, 0x70,

    /* U+0046 "F" */
    0xf3, 0x40,

    /* U+0047 "G" */
    0x74, 0xb0,

    /* U+0048 "H" */
    0xb7, 0xd0,

    /* U+0049 "I" */
    0xe9, 0x70,

    /* U+004A "J" */
    0x26, 0xa0,

    /* U+004B "K" */
    0xb3, 0x50,

    /* U+004C "L" */
    0x92, 0x70,

    /* U+004D "M" */
    0xbe, 0xd0,

    /* U+004E "N" */
    0xf6, 0xd0,

    /* U+004F "O" */
    0x54, 0x20,

    /* U+0050 "P" */
    0xf7, 0xc0,

    /* U+0051 "Q" */
    0x75, 0x30,

    /* U+0052 "R" */
    0xf7, 0x50,

    /* U+0053 "S" */
    0x73, 0xf0,

    /* U+0054 "T" */
    0xe9, 0x20,

    /* U+0055 "U" */
    0xb6, 0xf0,

    /* U+0056 "V" */
    0xa0, 0x20,

    /* U+0057 "W" */
    0xb7, 0xd0,

    /* U+0058 "X" */
    0xa1, 0x50,

    /* U+0059 "Y" */
    0xa0, 0x20,

    /* U+005A "Z" */
    0xe7, 0x70,

    /* U+005B "[" */
    0xeb,

    /* U+005C "\\" */
    0x81, 0x10,

    /* U+005D "]" */
    0xd7,

    /* U+005E "^" */
    0x54,

    /* U+005F "_" */
    0xe0,

    /* U+0060 "`" */
    0x90,

    /* U+0061 "a" */
    0x75, 0x80,

    /* U+0062 "b" */
    0x9a, 0xe0,

    /* U+0063 "c" */
    0x71, 0x80,

    /* U+0064 "d" */
    0x2e, 0xb0,

    /* U+0065 "e" */
    0x5d, 0x80,

    /* U+0066 "f" */
    0x2b, 0xa0,

    /* U+0067 "g" */
    0x43, 0xa0,

    /* U+0068 "h" */
    0x93, 0x50,

    /* U+0069 "i" */
    0xa0,

    /* U+006A "j" */
    0x46,

    /* U+006B "k" */
    0x97, 0x50,

    /* U+006C "l" */
    0xa9,

    /* U+006D "m" */
    0xbe, 0x80,

    /* U+006E "n" */
    0xd2, 0x80,

    /* U+006F "o" */
    0x55, 0x0,

    /* U+0070 "p" */
    0xd7, 0x40,

    /* U+0071 "q" */
    0x75, 0x90,

    /* U+0072 "r" */
    0x42, 0x80,

    /* U+0073 "s" */
    0x77, 0x0,

    /* U+0074 "t" */
    0x5d, 0x20,

    /* U+0075 "u" */
    0xa5, 0x80,

    /* U+0076 "v" */
    0xa1, 0x0,

    /* U+0077 "w" */
    0xbe, 0x80,

    /* U+0078 "x" */
    0xaa, 0x80,

    /* U+0079 "y" */
    0xa5, 0xa0,

    /* U+007A "z" */
    0xf7, 0x80,

    /* U+007B "{" */
    0x6b, 0x30,

    /* U+007C "|" */
    0xf0,

    /* U+007D "}" */
    0xc9, 0xe0,

    /* U+007E "~" */
    0x78,

    /* U+00A0 " " */
    0x0,

    /* U+00A1 "¡" */
    0x90,

    /* U+00A2 "¢" */
    0x5f, 0xa0,

    /* U+00A3 "£" */
    0x2b, 0xf0,

    /* U+00A5 "¥" */
    0xa2, 0xa0,

    /* U+00A6 "¦" */
    0x90,

    /* U+00A7 "§" */
    0x79, 0xe0,

    /* U+00A8 "¨" */
    0xa0,

    /* U+00B0 "°" */
    0xe8,

    /* U+00B1 "±" */
    0x5f, 0x80,

    /* U+00B7 "·" */
    0x80,

    /* U+00BF "¿" */
    0x43, 0x70,

    /* U+2014 "—" */
    0xe0,

    /* U+2018 "‘" */
    0x80,

    /* U+2019 "’" */
    0x80,

    /* U+201A "‚" */
    0x80,

    /* U+201C "“" */
    0xa0,

    /* U+201D "”" */
    0xa0,

    /* U+201E "„" */
    0xa0
};


/*---------------------
 *  GLYPH DESCRIPTION
 *--------------------*/

static const lv_font_fmt_txt_glyph_dsc_t glyph_dsc[] = {
    {.bitmap_index = 0, .adv_w = 0, .box_w = 0, .box_h = 0, .ofs_x = 0, .ofs_y = 0} /* id = 0 reserved */,
    {.bitmap_index = 0, .adv_w = 53, .box_w = 1, .box_h = 1, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 1, .adv_w = 53, .box_w = 1, .box_h = 4, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 2, .adv_w = 53, .box_w = 3, .box_h = 1, .ofs_x = 0, .ofs_y = 3},
    {.bitmap_index = 3, .adv_w = 53, .box_w = 3, .box_h = 4, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 5, .adv_w = 53, .box_w = 3, .box_h = 4, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 7, .adv_w = 53, .box_w = 3, .box_h = 4, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 9, .adv_w = 53, .box_w = 3, .box_h = 4, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 11, .adv_w = 53, .box_w = 1, .box_h = 1, .ofs_x = 1, .ofs_y = 3},
    {.bitmap_index = 12, .adv_w = 53, .box_w = 2, .box_h = 4, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 13, .adv_w = 53, .box_w = 2, .box_h = 4, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 14, .adv_w = 53, .box_w = 3, .box_h = 3, .ofs_x = 0, .ofs_y = 1},
    {.bitmap_index = 16, .adv_w = 53, .box_w = 3, .box_h = 2, .ofs_x = 0, .ofs_y = 2},
    {.bitmap_index = 17, .adv_w = 53, .box_w = 2, .box_h = 2, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 18, .adv_w = 53, .box_w = 2, .box_h = 1, .ofs_x = 1, .ofs_y = 1},
    {.bitmap_index = 19, .adv_w = 53, .box_w = 1, .box_h = 1, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 20, .adv_w = 53, .box_w = 3, .box_h = 4, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 22, .adv_w = 53, .box_w = 3, .box_h = 4, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 24, .adv_w = 53, .box_w = 3, .box_h = 4, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 26, .adv_w = 53, .box_w = 3, .box_h = 4, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 28, .adv_w = 53, .box_w = 3, .box_h = 4, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 30, .adv_w = 53, .box_w = 3, .box_h = 4, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 32, .adv_w = 53, .box_w = 3, .box_h = 4, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 34, .adv_w = 53, .box_w = 3, .box_h = 4, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 36, .adv_w = 53, .box_w = 3, .box_h = 4, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 38, .adv_w = 53, .box_w = 3, .box_h = 4, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 40, .adv_w = 53, .box_w = 3, .box_h = 4, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 42, .adv_w = 53, .box_w = 1, .box_h = 3, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 43, .adv_w = 53, .box_w = 2, .box_h = 3, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 44, .adv_w = 53, .box_w = 3, .box_h = 4, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 46, .adv_w = 53, .box_w = 3, .box_h = 3, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 48, .adv_w = 53, .box_w = 3, .box_h = 4, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 50, .adv_w = 53, .box_w = 3, .box_h = 4, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 52, .adv_w = 53, .box_w = 3, .box_h = 4, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 54, .adv_w = 53, .box_w = 3, .box_h = 4, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 56, .adv_w = 53, .box_w = 3, .box_h = 4, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 58, .adv_w = 53, .box_w = 3, .box_h = 4, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 60, .adv_w = 53, .box_w = 3, .box_h = 4, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 62, .adv_w = 53, .box_w = 3, .box_h = 4, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 64, .adv_w = 53, .box_w = 3, .box_h = 4, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 66, .adv_w = 53, .box_w = 3, .box_h = 4, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 68, .adv_w = 53, .box_w = 3, .box_h = 4, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 70, .adv_w = 53, .box_w = 3, .box_h = 4, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 72, .adv_w = 53, .box_w = 3, .box_h = 4, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 74, .adv_w = 53, .box_w = 3, .box_h = 4, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 76, .adv_w = 53, .box_w = 3, .box_h = 4, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 78, .adv_w = 53, .box_w = 3, .box_h = 4, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 80, .adv_w = 53, .box_w = 3, .box_h = 4, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 82, .adv_w = 53, .box_w = 3, .box_h = 4, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 84, .adv_w = 53, .box_w = 3, .box_h = 4, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 86, .adv_w = 53, .box_w = 3, .box_h = 4, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 88, .adv_w = 53, .box_w = 3, .box_h = 4, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 90, .adv_w = 53, .box_w = 3, .box_h = 4, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 92, .adv_w = 53, .box_w = 3, .box_h = 4, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 94, .adv_w = 53, .box_w = 3, .box_h = 4, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 96, .adv_w = 53, .box_w = 3, .box_h = 4, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 98, .adv_w = 53, .box_w = 3, .box_h = 4, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 100, .adv_w = 53, .box_w = 3, .box_h = 4, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 102, .adv_w = 53, .box_w = 3, .box_h = 4, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 104, .adv_w = 53, .box_w = 3, .box_h = 4, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 106, .adv_w = 53, .box_w = 2, .box_h = 4, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 107, .adv_w = 53, .box_w = 3, .box_h = 4, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 109, .adv_w = 53, .box_w = 2, .box_h = 4, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 110, .adv_w = 53, .box_w = 3, .box_h = 2, .ofs_x = 0, .ofs_y = 2},
    {.bitmap_index = 111, .adv_w = 53, .box_w = 3, .box_h = 1, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 112, .adv_w = 53, .box_w = 2, .box_h = 2, .ofs_x = 0, .ofs_y = 1},
    {.bitmap_index = 113, .adv_w = 53, .box_w = 3, .box_h = 3, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 115, .adv_w = 53, .box_w = 3, .box_h = 4, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 117, .adv_w = 53, .box_w = 3, .box_h = 3, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 119, .adv_w = 53, .box_w = 3, .box_h = 4, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 121, .adv_w = 53, .box_w = 3, .box_h = 3, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 123, .adv_w = 53, .box_w = 3, .box_h = 4, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 125, .adv_w = 53, .box_w = 3, .box_h = 4, .ofs_x = 0, .ofs_y = -1},
    {.bitmap_index = 127, .adv_w = 53, .box_w = 3, .box_h = 4, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 129, .adv_w = 53, .box_w = 1, .box_h = 3, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 130, .adv_w = 53, .box_w = 2, .box_h = 4, .ofs_x = 0, .ofs_y = -1},
    {.bitmap_index = 131, .adv_w = 53, .box_w = 3, .box_h = 4, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 133, .adv_w = 53, .box_w = 2, .box_h = 4, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 134, .adv_w = 53, .box_w = 3, .box_h = 3, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 136, .adv_w = 53, .box_w = 3, .box_h = 3, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 138, .adv_w = 53, .box_w = 3, .box_h = 3, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 140, .adv_w = 53, .box_w = 3, .box_h = 4, .ofs_x = 0, .ofs_y = -1},
    {.bitmap_index = 142, .adv_w = 53, .box_w = 3, .box_h = 4, .ofs_x = 0, .ofs_y = -1},
    {.bitmap_index = 144, .adv_w = 53, .box_w = 3, .box_h = 3, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 146, .adv_w = 53, .box_w = 3, .box_h = 3, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 148, .adv_w = 53, .box_w = 3, .box_h = 4, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 150, .adv_w = 53, .box_w = 3, .box_h = 3, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 152, .adv_w = 53, .box_w = 3, .box_h = 3, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 154, .adv_w = 53, .box_w = 3, .box_h = 3, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 156, .adv_w = 53, .box_w = 3, .box_h = 3, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 158, .adv_w = 53, .box_w = 3, .box_h = 4, .ofs_x = 0, .ofs_y = -1},
    {.bitmap_index = 160, .adv_w = 53, .box_w = 3, .box_h = 3, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 162, .adv_w = 53, .box_w = 3, .box_h = 4, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 164, .adv_w = 53, .box_w = 1, .box_h = 4, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 165, .adv_w = 53, .box_w = 3, .box_h = 4, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 167, .adv_w = 53, .box_w = 3, .box_h = 2, .ofs_x = 0, .ofs_y = 1},
    {.bitmap_index = 168, .adv_w = 53, .box_w = 1, .box_h = 1, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 169, .adv_w = 53, .box_w = 1, .box_h = 4, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 170, .adv_w = 53, .box_w = 3, .box_h = 4, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 172, .adv_w = 53, .box_w = 3, .box_h = 4, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 174, .adv_w = 53, .box_w = 3, .box_h = 4, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 176, .adv_w = 53, .box_w = 1, .box_h = 4, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 177, .adv_w = 53, .box_w = 3, .box_h = 4, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 179, .adv_w = 53, .box_w = 3, .box_h = 1, .ofs_x = 0, .ofs_y = 3},
    {.bitmap_index = 180, .adv_w = 53, .box_w = 3, .box_h = 2, .ofs_x = 0, .ofs_y = 1},
    {.bitmap_index = 181, .adv_w = 53, .box_w = 3, .box_h = 3, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 183, .adv_w = 53, .box_w = 1, .box_h = 1, .ofs_x = 1, .ofs_y = 1},
    {.bitmap_index = 184, .adv_w = 53, .box_w = 3, .box_h = 4, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 186, .adv_w = 53, .box_w = 3, .box_h = 1, .ofs_x = 0, .ofs_y = 1},
    {.bitmap_index = 187, .adv_w = 53, .box_w = 1, .box_h = 1, .ofs_x = 0, .ofs_y = 3},
    {.bitmap_index = 188, .adv_w = 53, .box_w = 1, .box_h = 1, .ofs_x = 2, .ofs_y = 3},
    {.bitmap_index = 189, .adv_w = 53, .box_w = 1, .box_h = 1, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 190, .adv_w = 53, .box_w = 3, .box_h = 1, .ofs_x = 0, .ofs_y = 3},
    {.bitmap_index = 191, .adv_w = 53, .box_w = 3, .box_h = 1, .ofs_x = 0, .ofs_y = 3},
    {.bitmap_index = 192, .adv_w = 53, .box_w = 3, .box_h = 1, .ofs_x = 0, .ofs_y = 0}
};

/*---------------------
 *  CHARACTER MAPPING
 *--------------------*/

static const uint16_t unicode_list_1[] = {
    0x0, 0x1, 0x2, 0x3, 0x5, 0x6, 0x7, 0x8,
    0x10, 0x11, 0x17, 0x1f, 0x1f74, 0x1f78, 0x1f79, 0x1f7a,
    0x1f7c, 0x1f7d, 0x1f7e
};

/*Collect the unicode lists and glyph_id offsets*/
static const lv_font_fmt_txt_cmap_t cmaps[] =
{
    {
        .range_start = 32, .range_length = 95, .glyph_id_start = 1,
        .unicode_list = NULL, .glyph_id_ofs_list = NULL, .list_length = 0, .type = LV_FONT_FMT_TXT_CMAP_FORMAT0_TINY
    },
    {
        .range_start = 160, .range_length = 8063, .glyph_id_start = 96,
        .unicode_list = unicode_list_1, .glyph_id_ofs_list = NULL, .list_length = 19, .type = LV_FONT_FMT_TXT_CMAP_SPARSE_TINY
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
    .cmap_num = 2,
    .bpp = 1,
    .kern_classes = 0,
    .bitmap_format = 0,
#if LVGL_VERSION_MAJOR == 8
    .cache = &cache
#endif

};

extern const lv_font_t LV_FONT_UNSCII_8;


/*-----------------
 *  PUBLIC FONT
 *----------------*/

/*Initialize a public general font descriptor*/
#if LVGL_VERSION_MAJOR >= 8
const lv_font_t tiny_mono_3x5 = {
#else
lv_font_t tiny_mono_3x5 = {
#endif
    .get_glyph_dsc = lv_font_get_glyph_dsc_fmt_txt,    /*Function pointer to get glyph's data*/
    .get_glyph_bitmap = lv_font_get_bitmap_fmt_txt,    /*Function pointer to get glyph's bitmap*/
    .line_height = 5,          /*The maximum line height required by the font*/
    .base_line = 1,             /*Baseline measured from the bottom of the line*/
#if !(LVGL_VERSION_MAJOR == 6 && LVGL_VERSION_MINOR == 0)
    .subpx = LV_FONT_SUBPX_NONE,
#endif
#if LV_VERSION_CHECK(7, 4, 0) || LVGL_VERSION_MAJOR >= 8
    .underline_position = 0,
    .underline_thickness = 0,
#endif
    .static_bitmap = 0,
    .dsc = &font_dsc,          /*The custom font data. Will be accessed by `get_glyph_bitmap/dsc` */
#if LV_VERSION_CHECK(8, 2, 0) || LVGL_VERSION_MAJOR >= 9
    .fallback = &LV_FONT_UNSCII_8,
#endif
    .user_data = NULL,
};



#endif /*#if TINY_MONO_3X5*/
