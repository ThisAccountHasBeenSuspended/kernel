%include "asm/include.asm"

global long_mode_start

; defined in src/kmain.c
extern kmain

section .text
    bits 64
    long_mode_start:
        ; load null into all data segment registers
        mov ax, 0
        mov ss, ax
        mov ds, ax
        mov es, ax
        mov fs, ax
        mov gs, ax

        ; print `OKAY`
        mov rax, 0x2F592F412F4B2F4F
        mov qword [VGABUF], rax
        
        call kmain

        ; should not happen
        hlt