/* 
**	Title: System Header File
**	Author: Will Dignazio
**	Description: 
**		Backbone header for system functions. 
*/
#ifndef SYSTEM_H_GAURD
#define SYSTEM_H_GAURD

#include "sysio.h"

/* IDT Gate Setter, allows to install interrupt handler */
void idt_set_gate(unsigned char num, unsigned long base, 
					unsigned short sel, unsigned char flags); 

/* GDT Gate Setter, allows to install new gdt gates. */
void gdt_set_gate(int num, unsigned long base, unsigned long limit, 
					unsigned char access, unsigned char gran); 

static unsigned char *exception_messages[]; 

/* GDT & IDT Installer */
void gdt_install(); 
void idt_install(); 

/* Debug */
int set_eax(int num); 			// In core.asm
void halt();					// Halt System

/*Programmable Interval Timer */
void timer_phase(int hz); 
void timer_handler(struct regs *r);
void timer_install(); 
void wait(int ticks); 

#endif
