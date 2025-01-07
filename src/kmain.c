#include "kmain.h"

#include <drivers/vga_tmode.h>

void kmain(void)
{
    vga_tmode_clear();
    vga_tmode_scheme(VGA_TMODE_LIGHT_GREEN, VGA_TMODE_BLACK);
    vga_tmode_print("Kernel loaded successfully!\n");

    vga_tmode_scheme(VGA_TMODE_LIGHT_GREY, VGA_TMODE_BLACK);
    vga_tmode_print("Built on: ");
    vga_tmode_print(KERNEL_DATE);
    vga_tmode_print(" at ");
    vga_tmode_print(KERNEL_TIME);
    vga_tmode_print("\n");

    while (true)
    {
        // It puts the CPU in a sleep mode until the next external interruption is fired.
        // [QEMU] i5-14400f: 0.3% with and 12.2% without.
        // https://en.wikipedia.org/wiki/HLT_(x86_instruction)
        __asm__("hlt");
    }
}