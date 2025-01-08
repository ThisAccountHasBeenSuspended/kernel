#ifndef DRIVERS_VGA_TMODE_H
#define DRIVERS_VGA_TMODE_H

enum VgaTmodeColor
{
    VGA_TMODE_BLACK         = 0,
    VGA_TMODE_BLUE          = 1,
    VGA_TMODE_GREEN         = 2,
    VGA_TMODE_CYAN          = 3,
    VGA_TMODE_RED           = 4,
    VGA_TMODE_MAGENTA       = 5,
    VGA_TMODE_BROWN         = 6,
    VGA_TMODE_LIGHT_GREY    = 7,
    VGA_TMODE_DARK_GREY     = 8,
    VGA_TMODE_LIGHT_BLUE    = 9,
    VGA_TMODE_LIGHT_GREEN   = 10,
    VGA_TMODE_LIGHT_CYAN    = 11,
    VGA_TMODE_LIGHT_RED     = 12,
    VGA_TMODE_LIGHT_MAGENTA = 13,
    VGA_TMODE_LIGHT_BROWN   = 14,
    VGA_TMODE_WHITE         = 15
};

struct VgaTmodeInfo
{
    unsigned int col, row;
};

void vga_tmode_scheme(unsigned char, unsigned char);
void vga_tmode_print(const char* const);
void vga_tmode_clear();

#endif