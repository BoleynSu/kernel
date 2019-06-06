all:
	gcc -c kernel.c -o kernel.o
	as bootloader.s -o bootloader.o
	ld kernel.o bootloader.o -T linker.ld -o BSOS
clean:
	rm *.o BSOS

