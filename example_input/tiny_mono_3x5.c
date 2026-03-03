/*******************************************************************************
 * Adapted from Another Tiny Pixel Font Mono 3x5 by Alassë Eärfalas https://alasseearfalas.itch.io/another-tiny-pixel-font-mono-3x5
 * Size: 6 px
 * Bpp: 1
 * Opts: --bpp 1 --size 6 --no-compress --stride 1 --align 1 --font my 3x5 tiny mono pixel font.ttf --range 0-65535 --format lvgl -o tiny_mono_3x5.c
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
    0xe8,

    /* U+0022 "\"" */
    0xb4,

    /* U+0023 "#" */
    0xbe, 0xfa,

    /* U+0024 "$" */
    0x79, 0xf4,

    /* U+0025 "%" */
    0xa5, 0x4a,

    /* U+0026 "&" */
    0x79, 0xd6,

    /* U+0027 "'" */
    0xc0,

    /* U+0028 "(" */
    0x6a, 0x40,

    /* U+0029 ")" */
    0x95, 0x80,

    /* U+002A "*" */
    0xaa, 0x80,

    /* U+002B "+" */
    0x5d, 0x0,

    /* U+002C "," */
    0x60,

    /* U+002D "-" */
    0xc0,

    /* U+002E "." */
    0x80,

    /* U+002F "/" */
    0x25, 0x48,

    /* U+0030 "0" */
    0xf6, 0xde,

    /* U+0031 "1" */
    0xc9, 0x2e,

    /* U+0032 "2" */
    0xe7, 0xce,

    /* U+0033 "3" */
    0xe5, 0x9e,

    /* U+0034 "4" */
    0xb7, 0x92,

    /* U+0035 "5" */
    0xf3, 0x9e,

    /* U+0036 "6" */
    0xf3, 0xde,

    /* U+0037 "7" */
    0xe4, 0x92,

    /* U+0038 "8" */
    0xf7, 0xde,

    /* U+0039 "9" */
    0xf7, 0x9e,

    /* U+003A ":" */
    0xa0,

    /* U+003B ";" */
    0x46,

    /* U+003C "<" */
    0x2a, 0x22,

    /* U+003D "=" */
    0xe3, 0x80,

    /* U+003E ">" */
    0x88, 0xa8,

    /* U+003F "?" */
    0xe5, 0x84,

    /* U+0040 "@" */
    0x56, 0xc6,

    /* U+0041 "A" */
    0x57, 0xda,

    /* U+0042 "B" */
    0xd7, 0x5c,

    /* U+0043 "C" */
    0x72, 0x46,

    /* U+0044 "D" */
    0xd6, 0xdc,

    /* U+0045 "E" */
    0xf3, 0x4e,

    /* U+0046 "F" */
    0xf3, 0x48,

    /* U+0047 "G" */
    0x72, 0xd6,

    /* U+0048 "H" */
    0xb7, 0xda,

    /* U+0049 "I" */
    0xe9, 0x2e,

    /* U+004A "J" */
    0x24, 0xd4,

    /* U+004B "K" */
    0xb7, 0x5a,

    /* U+004C "L" */
    0x92, 0x4e,

    /* U+004D "M" */
    0xbf, 0xda,

    /* U+004E "N" */
    0xd6, 0xda,

    /* U+004F "O" */
    0x56, 0xd4,

    /* U+0050 "P" */
    0xf7, 0xc8,

    /* U+0051 "Q" */
    0x76, 0xe6,

    /* U+0052 "R" */
    0xf7, 0x5a,

    /* U+0053 "S" */
    0x73, 0x9c,

    /* U+0054 "T" */
    0xe9, 0x24,

    /* U+0055 "U" */
    0xb6, 0xd6,

    /* U+0056 "V" */
    0xb6, 0xd4,

    /* U+0057 "W" */
    0xb7, 0xfa,

    /* U+0058 "X" */
    0xb5, 0x5a,

    /* U+0059 "Y" */
    0xb5, 0x24,

    /* U+005A "Z" */
    0xe5, 0x4e,

    /* U+005B "[" */
    0xea, 0xc0,

    /* U+005C "\\" */
    0x91, 0x12,

    /* U+005D "]" */
    0xd5, 0xc0,

    /* U+005E "^" */
    0x54,

    /* U+005F "_" */
    0xe0,

    /* U+0060 "`" */
    0x90,

    /* U+0061 "a" */
    0x76, 0xb0,

    /* U+0062 "b" */
    0x9a, 0xdc,

    /* U+0063 "c" */
    0x72, 0x30,

    /* U+0064 "d" */
    0x2e, 0xd6,

    /* U+0065 "e" */
    0x57, 0x30,

    /* U+0066 "f" */
    0x2b, 0xa4,

    /* U+0067 "g" */
    0x55, 0x94,

    /* U+0068 "h" */
    0x93, 0x5a,

    /* U+0069 "i" */
    0xb0,

    /* U+006A "j" */
    0x45, 0x80,

    /* U+006B "k" */
    0x97, 0x5a,

    /* U+006C "l" */
    0xaa, 0x40,

    /* U+006D "m" */
    0xbe, 0xd0,

    /* U+006E "n" */
    0xd6, 0xd0,

    /* U+006F "o" */
    0x56, 0xa0,

    /* U+0070 "p" */
    0xd6, 0xe8,

    /* U+0071 "q" */
    0x76, 0xb2,

    /* U+0072 "r" */
    0x56, 0x40,

    /* U+0073 "s" */
    0x70, 0xe0,

    /* U+0074 "t" */
    0x5d, 0x24,

    /* U+0075 "u" */
    0xb6, 0xb0,

    /* U+0076 "v" */
    0xb6, 0xa0,

    /* U+0077 "w" */
    0xb7, 0xd0,

    /* U+0078 "x" */
    0xa9, 0x50,

    /* U+0079 "y" */
    0xb5, 0x94,

    /* U+007A "z" */
    0xe6, 0x70,

    /* U+007B "{" */
    0x6a, 0x26,

    /* U+007C "|" */
    0xf8,

    /* U+007D "}" */
    0xc8, 0xac,

    /* U+007E "~" */
    0x78,

    /* U+00A0 " " */
    0x0,

    /* U+00A1 "¡" */
    0xb8,

    /* U+00A2 "¢" */
    0x5e, 0x74,

    /* U+00A3 "£" */
    0x2b, 0xae,

    /* U+00A5 "¥" */
    0xb5, 0x74,

    /* U+00A6 "¦" */
    0xd8,

    /* U+00A7 "§" */
    0x7a, 0xbc,

    /* U+00A8 "¨" */
    0xa0,

    /* U+00B0 "°" */
    0x55, 0x0,

    /* U+00B1 "±" */
    0x5d, 0x70,

    /* U+00B7 "·" */
    0x80,

    /* U+00BF "¿" */
    0x43, 0x4e,

    /* U+2014 "—" */
    0xe0,

    /* U+2018 "‘" */
    0xc0,

    /* U+2019 "’" */
    0xc0,

    /* U+201A "‚" */
    0xc0,

    /* U+201C "“" */
    0xb4,

    /* U+201D "”" */
    0xb4,

    /* U+201E "„" */
    0xb4
};


/*---------------------
 *  GLYPH DESCRIPTION
 *--------------------*/

static const lv_font_fmt_txt_glyph_dsc_t glyph_dsc[] = {
    {.bitmap_index = 0, .adv_w = 0, .box_w = 0, .box_h = 0, .ofs_x = 0, .ofs_y = 0} /* id = 0 reserved */,
    {.bitmap_index = 0, .adv_w = 64, .box_w = 1, .box_h = 1, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 1, .adv_w = 64, .box_w = 1, .box_h = 5, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 2, .adv_w = 64, .box_w = 3, .box_h = 2, .ofs_x = 0, .ofs_y = 3},
    {.bitmap_index = 3, .adv_w = 64, .box_w = 3, .box_h = 5, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 5, .adv_w = 64, .box_w = 3, .box_h = 5, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 7, .adv_w = 64, .box_w = 3, .box_h = 5, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 9, .adv_w = 64, .box_w = 3, .box_h = 5, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 11, .adv_w = 64, .box_w = 1, .box_h = 2, .ofs_x = 1, .ofs_y = 3},
    {.bitmap_index = 12, .adv_w = 64, .box_w = 2, .box_h = 5, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 14, .adv_w = 64, .box_w = 2, .box_h = 5, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 16, .adv_w = 64, .box_w = 3, .box_h = 3, .ofs_x = 0, .ofs_y = 2},
    {.bitmap_index = 18, .adv_w = 64, .box_w = 3, .box_h = 3, .ofs_x = 0, .ofs_y = 1},
    {.bitmap_index = 20, .adv_w = 64, .box_w = 2, .box_h = 2, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 21, .adv_w = 64, .box_w = 2, .box_h = 1, .ofs_x = 1, .ofs_y = 2},
    {.bitmap_index = 22, .adv_w = 64, .box_w = 1, .box_h = 1, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 23, .adv_w = 64, .box_w = 3, .box_h = 5, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 25, .adv_w = 64, .box_w = 3, .box_h = 5, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 27, .adv_w = 64, .box_w = 3, .box_h = 5, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 29, .adv_w = 64, .box_w = 3, .box_h = 5, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 31, .adv_w = 64, .box_w = 3, .box_h = 5, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 33, .adv_w = 64, .box_w = 3, .box_h = 5, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 35, .adv_w = 64, .box_w = 3, .box_h = 5, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 37, .adv_w = 64, .box_w = 3, .box_h = 5, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 39, .adv_w = 64, .box_w = 3, .box_h = 5, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 41, .adv_w = 64, .box_w = 3, .box_h = 5, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 43, .adv_w = 64, .box_w = 3, .box_h = 5, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 45, .adv_w = 64, .box_w = 1, .box_h = 3, .ofs_x = 1, .ofs_y = 1},
    {.bitmap_index = 46, .adv_w = 64, .box_w = 2, .box_h = 4, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 47, .adv_w = 64, .box_w = 3, .box_h = 5, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 49, .adv_w = 64, .box_w = 3, .box_h = 3, .ofs_x = 0, .ofs_y = 1},
    {.bitmap_index = 51, .adv_w = 64, .box_w = 3, .box_h = 5, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 53, .adv_w = 64, .box_w = 3, .box_h = 5, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 55, .adv_w = 64, .box_w = 3, .box_h = 5, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 57, .adv_w = 64, .box_w = 3, .box_h = 5, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 59, .adv_w = 64, .box_w = 3, .box_h = 5, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 61, .adv_w = 64, .box_w = 3, .box_h = 5, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 63, .adv_w = 64, .box_w = 3, .box_h = 5, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 65, .adv_w = 64, .box_w = 3, .box_h = 5, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 67, .adv_w = 64, .box_w = 3, .box_h = 5, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 69, .adv_w = 64, .box_w = 3, .box_h = 5, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 71, .adv_w = 64, .box_w = 3, .box_h = 5, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 73, .adv_w = 64, .box_w = 3, .box_h = 5, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 75, .adv_w = 64, .box_w = 3, .box_h = 5, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 77, .adv_w = 64, .box_w = 3, .box_h = 5, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 79, .adv_w = 64, .box_w = 3, .box_h = 5, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 81, .adv_w = 64, .box_w = 3, .box_h = 5, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 83, .adv_w = 64, .box_w = 3, .box_h = 5, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 85, .adv_w = 64, .box_w = 3, .box_h = 5, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 87, .adv_w = 64, .box_w = 3, .box_h = 5, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 89, .adv_w = 64, .box_w = 3, .box_h = 5, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 91, .adv_w = 64, .box_w = 3, .box_h = 5, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 93, .adv_w = 64, .box_w = 3, .box_h = 5, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 95, .adv_w = 64, .box_w = 3, .box_h = 5, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 97, .adv_w = 64, .box_w = 3, .box_h = 5, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 99, .adv_w = 64, .box_w = 3, .box_h = 5, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 101, .adv_w = 64, .box_w = 3, .box_h = 5, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 103, .adv_w = 64, .box_w = 3, .box_h = 5, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 105, .adv_w = 64, .box_w = 3, .box_h = 5, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 107, .adv_w = 64, .box_w = 3, .box_h = 5, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 109, .adv_w = 64, .box_w = 2, .box_h = 5, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 111, .adv_w = 64, .box_w = 3, .box_h = 5, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 113, .adv_w = 64, .box_w = 2, .box_h = 5, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 115, .adv_w = 64, .box_w = 3, .box_h = 2, .ofs_x = 0, .ofs_y = 3},
    {.bitmap_index = 116, .adv_w = 64, .box_w = 3, .box_h = 1, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 117, .adv_w = 64, .box_w = 2, .box_h = 2, .ofs_x = 0, .ofs_y = 2},
    {.bitmap_index = 118, .adv_w = 64, .box_w = 3, .box_h = 4, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 120, .adv_w = 64, .box_w = 3, .box_h = 5, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 122, .adv_w = 64, .box_w = 3, .box_h = 4, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 124, .adv_w = 64, .box_w = 3, .box_h = 5, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 126, .adv_w = 64, .box_w = 3, .box_h = 4, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 128, .adv_w = 64, .box_w = 3, .box_h = 5, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 130, .adv_w = 64, .box_w = 3, .box_h = 5, .ofs_x = 0, .ofs_y = -1},
    {.bitmap_index = 132, .adv_w = 64, .box_w = 3, .box_h = 5, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 134, .adv_w = 64, .box_w = 1, .box_h = 4, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 135, .adv_w = 64, .box_w = 2, .box_h = 5, .ofs_x = 0, .ofs_y = -1},
    {.bitmap_index = 137, .adv_w = 64, .box_w = 3, .box_h = 5, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 139, .adv_w = 64, .box_w = 2, .box_h = 5, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 141, .adv_w = 64, .box_w = 3, .box_h = 4, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 143, .adv_w = 64, .box_w = 3, .box_h = 4, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 145, .adv_w = 64, .box_w = 3, .box_h = 4, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 147, .adv_w = 64, .box_w = 3, .box_h = 5, .ofs_x = 0, .ofs_y = -1},
    {.bitmap_index = 149, .adv_w = 64, .box_w = 3, .box_h = 5, .ofs_x = 0, .ofs_y = -1},
    {.bitmap_index = 151, .adv_w = 64, .box_w = 3, .box_h = 4, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 153, .adv_w = 64, .box_w = 3, .box_h = 4, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 155, .adv_w = 64, .box_w = 3, .box_h = 5, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 157, .adv_w = 64, .box_w = 3, .box_h = 4, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 159, .adv_w = 64, .box_w = 3, .box_h = 4, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 161, .adv_w = 64, .box_w = 3, .box_h = 4, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 163, .adv_w = 64, .box_w = 3, .box_h = 4, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 165, .adv_w = 64, .box_w = 3, .box_h = 5, .ofs_x = 0, .ofs_y = -1},
    {.bitmap_index = 167, .adv_w = 64, .box_w = 3, .box_h = 4, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 169, .adv_w = 64, .box_w = 3, .box_h = 5, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 171, .adv_w = 64, .box_w = 1, .box_h = 5, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 172, .adv_w = 64, .box_w = 3, .box_h = 5, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 174, .adv_w = 64, .box_w = 3, .box_h = 2, .ofs_x = 0, .ofs_y = 1},
    {.bitmap_index = 175, .adv_w = 64, .box_w = 1, .box_h = 1, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 176, .adv_w = 64, .box_w = 1, .box_h = 5, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 177, .adv_w = 64, .box_w = 3, .box_h = 5, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 179, .adv_w = 64, .box_w = 3, .box_h = 5, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 181, .adv_w = 64, .box_w = 3, .box_h = 5, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 183, .adv_w = 64, .box_w = 1, .box_h = 5, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 184, .adv_w = 64, .box_w = 3, .box_h = 5, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 186, .adv_w = 64, .box_w = 3, .box_h = 1, .ofs_x = 0, .ofs_y = 4},
    {.bitmap_index = 187, .adv_w = 64, .box_w = 3, .box_h = 3, .ofs_x = 0, .ofs_y = 2},
    {.bitmap_index = 189, .adv_w = 64, .box_w = 3, .box_h = 4, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 191, .adv_w = 64, .box_w = 1, .box_h = 1, .ofs_x = 1, .ofs_y = 2},
    {.bitmap_index = 192, .adv_w = 64, .box_w = 3, .box_h = 5, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 194, .adv_w = 64, .box_w = 3, .box_h = 1, .ofs_x = 0, .ofs_y = 2},
    {.bitmap_index = 195, .adv_w = 64, .box_w = 1, .box_h = 2, .ofs_x = 0, .ofs_y = 3},
    {.bitmap_index = 196, .adv_w = 64, .box_w = 1, .box_h = 2, .ofs_x = 2, .ofs_y = 3},
    {.bitmap_index = 197, .adv_w = 64, .box_w = 1, .box_h = 2, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 198, .adv_w = 64, .box_w = 3, .box_h = 2, .ofs_x = 0, .ofs_y = 3},
    {.bitmap_index = 199, .adv_w = 64, .box_w = 3, .box_h = 2, .ofs_x = 0, .ofs_y = 3},
    {.bitmap_index = 200, .adv_w = 64, .box_w = 3, .box_h = 2, .ofs_x = 0, .ofs_y = 0}
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
    .line_height = 6,          /*The maximum line height required by the font*/
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
    .fallback = NULL,
#endif
    .user_data = NULL,
};



#endif /*#if TINY_MONO_3X5*/
