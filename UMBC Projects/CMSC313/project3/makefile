nasm:
	nasm -g -f elf64 -F dwarf hexConverter.asm

hexConverter:
	gcc -g hexConverter.o cfunc.c -o hexConverter

clean:
	rm hexConverter hexConverter.o

scp:
	scp * beadenk11@gl.umbc.edu:cs313/proj3

ssh:
	ssh beadenk1@linux1.gl.umbc.edu

submit:
	submit	CMSC313_Deepak proj3 cfunc.c hexConverter.asm Readme.txt makefile
