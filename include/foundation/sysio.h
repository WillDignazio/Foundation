/* System Port Input/Output Header
** Author: Will Dignazio 
** Description: 
**	Definitions for reading and writing to input and output ports on the 
** system. The header contains all functions and values related to the PIC
** for keybaord input, and other hardware intterupt interaction. 
*/

#ifndef SYSIO_H_GAURD
#define SYSIO_H_GAURD

/* Defines what the stack looks like after an ISR was running */
typedef struct regs
{ 
	unsigned int gs, fs, es, ds; 
	unsigned int edi, esi, ebp, esp, ebx, edx, ecx, eax; 
	unsigned int int_no, err_code; 
	unsigned int eip, cs, eflags, useresp, ss; 
} regs;

/* Hardware Port IO */
unsigned char inb(unsigned short port); 
void outb(unsigned short port, unsigned char val); 

/* ISR Prototypes */
struct regs* isr_common_stub();
void isrs_install();
void fault_handler(struct regs *r);
void isr0(); 
void isr1(); 
void isr8(); 
void isr13(); 

/* IRQ Prototypes */
struct regs* irq_common_stub();
void irq_install_handler(int irq, void(*handler)(struct regs *r));
void irq_uninstall_handler(int irq);
void irq_remap(void);
void irq_install();
void irq_handler(struct regs *r);
void irq0(); 
void irq1(); 
void irq15();

#endif
