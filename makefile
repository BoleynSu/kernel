all:
	gcc -c kernel.c -o kernel.o
	as bootloader.s -o bootloader.o
	ld kernel.o bootloader.o -T linker.ld -o os.bin
clean:
	rm *.o os.bin

