/* Global Descriptor Table
** Author: Will Dignazio 
** Date: 12/20/2011
** Descriptor: 
**	Even though there is technically a GDT in place from whatever boot 
** loader is used, we need our own so that we don't overwrite it. This code 
** will set up a new GDT so that we can control the descriptors, and add and
** remove descriptions of where our OS is. 
*/
#include <foundation/system.h>
#include <foundation/sysio.h>

/* Definition of a GDT entry. Packed to prevent destructive optimizations */
struct gdt_entry
{ 
	unsigned short limit_low; 
	unsigned short base_low; 
	unsigned char base_middle; 
	unsigned char access; 
	unsigned char granularity; 
	unsigned char base_high; 
} __attribute__((packed)); 

/* Pointer to GDT, includes limit, max bytes taken up - 1 */
struct gdt_ptr
{ 
	unsigned short limit; 
	unsigned int base; 
} __attribute__((packed)); 

/* GDT, and pointer*/
struct gdt_entry gdt[3]; 
struct gdt_ptr gp; 

/* ASM function in kernel_start.asm to load new GDT */
extern void gdt_flush(); 

/* Function to install a new descriptor */
void gdt_set_gate(int num, unsigned long base, unsigned long limit,	
						unsigned char access, unsigned char gran)
{ 
	/* Setup descriptor base address */
	gdt[num].base_low = (base & 0xFFFF); 
	gdt[num].base_middle = (base >> 16) & 0xFF; 
	gdt[num].base_high = (base >> 24) & 0xFF; 

	/* Setup the descriptor limits */
	gdt[num].limit_low = (limit & 0xFFFF); 
	gdt[num].granularity = ((limit >> 16) & 0x0F); 

	/* Set up granularity and access flags */
	gdt[num].granularity |= (gran & 0xF0); 
	gdt[num].access = access; 
} 

/* Call this in main, install the gdt as a flat setup */
void gdt_install()
{ 
	/* Setup the GDT pointer */
	gp.limit = (sizeof(struct gdt_entry) * 3) - 1; 
	gp.base = (int)&gdt; 

	/* Null descriptor */
	gdt_set_gate(0, 0, 0, 0, 0); 

	/* Code Segment */
	gdt_set_gate(1, 0, 0xFFFFFFFF, 0x9A, 0xCF); 

	/* Data Segment */
	gdt_set_gate(2, 0, 0xFFFFFFFF, 0x92, 0xCF); 

	/* Install it to the processor */
	gdt_flush(); 
}
