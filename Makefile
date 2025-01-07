# $@ = target file
# $< = first dependency
# $^ = all dependencies

OBJECTS := $(patsubst %.asm,%.o,$(shell find asm -name '*.asm'))
SOURCES := $(patsubst %.c,%.o,$(shell find external src -name '*.c'))

CINCLUDES = -I src/ -I src/include
CFLAGS = -W -Wall -ansi -pedantic -std=c2x -O2 -ffreestanding -nostdlib \
		 -fno-builtin -fno-stack-protector -nostartfiles -nodefaultlibs \
		 $(CINCLUDES)

default: build/kernel.iso

build/isofiles/boot/kernel.bin: $(OBJECTS) build/libkernel.a
	ld --nmagic --output=$@ --script=build/linker.ld $(OBJECTS) build/libkernel.a

$(OBJECTS): %.o: %.asm
	nasm -f elf64 $<

$(SOURCES): %.o: %.c
	gcc $(CFLAGS) -c $< -o $@

build/libkernel.a: $(SOURCES)
	ar rcs $@ $^

build/kernel.iso: build/isofiles/boot/kernel.bin
	grub-mkrescue --compress=xz -o $@ build/isofiles

clean:
	rm -r $(OBJECTS) $(SOURCES) build/isofiles/boot/kernel.bin build/kernel.iso build/libkernel.a