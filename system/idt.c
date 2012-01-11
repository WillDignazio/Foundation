/* Interrupt Descriptor Table
** Author: Will Dignazio 
** Description: 
**	 Descriptor table for handling the interrupts and exception routines 
** fired during kernel execution. 
*/
#include <foundation/system.h>

/* IDT Entry
** 	- Entry for the IDT table 
*/
struct idt_entry
{
	unsigned short base_lo;
	unsigned short sel; 		/* Kernel segment goes here */
	unsigned char always0;		/* Always be set to 0 */
	unsigned char flags; 		/* Refer to table in ref's */
	unsigned short base_hi;
}__attribute__((packed)); 
typedef struct idt_entry idt_entry;

struct idt_ptr
{ 
	unsigned short limit; 
	struct idt_entry *base; 
}__attribute__((packed));
typedef struct idt_ptr idt_ptr;

/* IDT of 256 entries. Though not all of the entries are going 
** be used, they are open for assignment and use later on. 
** An unhandled interrupt that is called will generate the 
** 'Unhandled Interrupt" exception. The unhandled exception is 
** denoted by the presence bit. 
*/
idt_entry idt[256]; 
idt_ptr idtp;

/* External function in the kernel start assembly file. */
extern void idt_load();

/* Sets an entry in the soon to be idt. */
void idt_set_gate(unsigned char num, unsigned long base, 
					unsigned short sel, unsigned char flags)
{
	/* The interrupt routine's base address */
    idt[num].base_lo = (base & 0xFFFF);
    idt[num].base_hi = (base >> 16) & 0xFFFF;

    /* The segment or 'selector' that this IDT entry will use
    *  is set here, along with any access flags */
    idt[num].sel = sel;
    idt[num].always0 = 0;
    idt[num].flags = flags;

}

/* Installs the IDT */
void idt_install()
{
	idtp.limit = (sizeof(idt_entry) * 256) - 1;
	idtp.base = &idt;
	
	/*Clear out the entire IDT, initializing it to zeros */
	memset(&idt, 0, sizeof(idt_entry) * 256);

	/* Load the idt register */
	idt_load();
};
