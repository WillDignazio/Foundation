OUTPUT_FORMAT(elf32-i386)
ENTRY(start)
SECTIONS
{ 
	. = 0x50000;
	.text : AT(0x600) { *(.text) }
	/*. = 0x51000;*/
	.data : /*AT(0x1000)*/ { *(.data) }
	/*. = 0x54A00;*/ 
	.rodata : /*AT(0x5000)*/ { *(.rodata) }
	.bss : /*AT(0x8000)*/ { *(.bss) }
}
