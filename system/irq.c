/* Interrupt Request Routines
** Author: Will Dignazio
** Description: 
** 	Routines for non-intel exceptions. These are the routines for the PIC 
** interrupt values of 32-47. These irq's can be used by software as well
** as hardware to create handled functions. 
*/

#include <foundation/system.h>
#include <foundation/sysio.h>
#include <foundation/stdio.h>

/* Array of function pointers to handle custom IRQ handlers for a IRQ */
void *irq_routines[16] = 
{
	0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0
};

/* Custom IRQ handler for given IRQs */
void irq_install_handler(int irq, void(*handler)(regs *r))
{ 
	irq_routines[irq] = handler; 
} 

/* Clears the handler for a given IRQ */
void irq_uninstall_handler(int irq)
{ 
	irq_routines[irq] = 0; 
} 

/* Remap the PIC Master so that interrupts 0-7 are not disturbed from IRQ's.
** Without remap, every time a IRQ0 fires, a double fault occurs. We are 
** remapping IRQ0-15 to IDT entries 32-47 */
void irq_remap(void)
{ 
	outb(0x20, 0x11); 
	outb(0xA0, 0x11); 
	outb(0x21, 0x20); 
	outb(0xA1, 0x28); 
	outb(0x21, 0x04); 
	outb(0xA1, 0x02); 
	outb(0x21, 0x01); 
	outb(0xA1, 0x01); 
	outb(0x21, 0x0); 
	outb(0xA1, 0x0); 
} 

/* Remaps PIC, and installs the IRQ handlers */
void irq_install()
{
	irq_remap();
	idt_set_gate(32, (unsigned)irq0, 0x08, 0x8E);
	idt_set_gate(33, (unsigned)irq1, 0x08, 0x8E); 
	idt_set_gate(47, (unsigned)irq15, 0x08, 0x8E); 
}

/* All IRQ ISR's point to this, rather than 'fault_handler' in isrs.asm and 
** isrs.c. The IRQ needs to be told when you are done with them, so we need 
** send them EOI (end of interrupt) command. Note that there are two PIC's, 
** and two access all of the IRQ's we must have seperate EOI commands. */
void irq_handler(struct regs *r)
{ 
	/* Blank function pointer */ 
	void (*handler)(struct regs *r); 

	/* Fund out if we have a custom handler to run for this IRQ. */
	handler = irq_routines[r->int_no - 32]; 
	set_eax((int)handler);
	if (handler)
	{ 
		handler(r); 
	}

	/* If IDT entry was greater than 40, then we need to send the EOI to 
	the slave controller */
	if (r->int_no >= 40)
	{
		outb(0xA0, 0x20); 
	}

	/* Else send EOI to master PIC. */
	outb(0x20, 0x20); 
}
