#include "vga_tmode.h"

#include <mem.h>
#include <string.h>

#define VGA_BUF      0xB8000
#define VGA_WIDTH    80
#define VGA_WIDTH_X2 (VGA_WIDTH * 2)
#define VGA_HEIGHT   25

struct VgaTmodeInfo info = {
    0, // Col
    0, // Row
};
static unsigned char current_scheme = 0;

void vga_tmode_scheme(unsigned char fg, unsigned char bg)
{
    current_scheme = fg | bg << 4;
}

static inline void scrolling()
{
    char* const addr = (char* const)VGA_BUF;
    for (int i = 1; i < VGA_HEIGHT; i++)
    {
        const char* const src = addr + (i * VGA_WIDTH_X2);
        char* const dest = addr + ((i - 1) * VGA_WIDTH_X2);
        memcpy(src, dest, VGA_WIDTH_X2);
    }

    info.row--;
}

static void write_at(
    char c, 
    unsigned char scheme, 
    unsigned int x, 
    unsigned int y
)
{
    const unsigned int offset = (y * VGA_WIDTH + x) * 2;

    char* const framebuffer = (char* const)VGA_BUF;
    framebuffer[offset] = c;
    framebuffer[offset + 1] = scheme;

    const unsigned int screen_height = VGA_HEIGHT * VGA_WIDTH_X2;
    if (offset > screen_height)
    {
        scrolling();
    }
}

static void write(char c)
{
    switch (c)
    {
        case '\n':
            info.col = 0;
            info.row++;
            break;
        case '\b':
            if (info.col > 0)
            {
                write_at(0x0, current_scheme, --info.col, info.row);
            }
            break;
        case '\t':
            info.col = info.col + 8 - (info.col % 8);
            break;
        case '\r':
            info.col = 0;
            break;
        default:
            write_at(c, current_scheme, info.col, info.row);

            if (++info.col < VGA_WIDTH)
            {
                return;
            }
            info.col = 0;

            if (++info.row < VGA_HEIGHT)
            {
                info.row = 0;
            }
    }
}

void vga_tmode_print(const char* const str)
{
    const unsigned int str_len = strlen(str);
    for (unsigned int i = 0; i < str_len; i++)
    {
        write(str[i]);
    }
}

void vga_tmode_clear()
{
    for (unsigned int y = 0; y < VGA_HEIGHT; y++)
    {
        for (unsigned int x = 0; x < VGA_WIDTH; x++)
        {
            write_at(' ', current_scheme, x, y);
        }
    }
}