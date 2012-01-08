INC=./
CC=gcc
ASM=nasm
OUTDIR = ./build/
OUT=-o $(OUTDIR)
CFLAGS=-m32 -c
AFLAGS=-f elf32
CFILE = ./*.c
AFILE = ./*.asm

# 	Makefile for building the kernel, 
# out put for the files will go in
# the $(OUTDIR) var. For this makefile, the 
# bit architecture is IA32, so all the C files 
# have the -m32 tack, and the -c tack to keep it from 
# completely compiling it.
# 	Assembly files will be compiled with the 
# ASM variable, or assembler. As said before, this 
# makefile is for IA32, and the assembly files are 
# to be compiled for 32 bit architecture. The attributes
# the assembler are to use are stored in the AFLAGS variable, 
# currently the settings are for elf in 32 bit format. 
system: 
	mkdir -p $(OUTDIR)
	$(CC) $(CFLAGS) core.c 	$(OUT)core.o
	$(CC) $(CFLAGS) idt.c	$(OUT)idt.o
	$(CC) $(CFLAGS) gdt.c	$(OUT)gdt.o
	$(CC) $(CFLAGS) isrs.c	$(OUT)isrs.o
	$(CC) $(CFLAGS) irq.c	$(OUT)irq.o
	$(CC) $(CFLAGS) timer.c	$(OUT)timer.o
	$(ASM) $(AFLAGS)	core.asm	$(OUT)coreS.o
	$(ASM) $(AFLAGS)	isrs.asm	$(OUT)isrsS.o
	$(ASM) $(AFLAGS) 	irq.asm 	$(OUT)irqS.o

