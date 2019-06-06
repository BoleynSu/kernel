all:
	as --32 bootloader.s -o bootloader.o
	gcc -m32 -c kernel.c -o kernel.o -ffreestanding -O2
	ld -m elf_i386 kernel.o bootloader.o -T linker.ld -o os.bin
clean:
	rm *.o os.bin os.iso root/boot/os.bin
test: all
	cp os.bin root/boot
	grub2-mkrescue -o os.iso root
	qemu-system-x86_64 -cdrom os.iso
