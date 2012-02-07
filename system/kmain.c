/* SOS Kernel Main 
**	Author: Will Dignazio 
**	Version: 0.03
**	Description: 
**		Main kernel source for the kernel, it is started by the 
**	kernel_starter jumped to from the bootloader. The kernelmain initializes
** 	the system, and call all and any necessary functions. 
*/

#include <foundation/system.h>
#include <foundation/sysio.h>
#include <foundation/stdio.h>
#include <foundation/stdapp.h>
#include <foundation/string.h>
#include <foundation/membloc.h>
#include <foundation/memory.h>
#include <foundation/binary.h>

/* Kernel Initializer
** 	- Readies the kernel
**	- Wipes the screen 
*/
void kernal_init()
{
	gdt_install();
	idt_install();				
	isrs_install();
	irq_install(); 
	asm volatile ("sti"); 
	t_wipe_console();								// Clear boot stuff
	t_writeln("- FOK Version 0.04.1");
	t_writeln("########################"); 
	t_writeln(":: Installed GDT");
	t_writeln(":: Installed IDT");
	t_writeln(":: Pointed Exception Vectors"); 
	t_writeln(":: Pointed Interrupt Vectors"); 
	
	t_writeln(":: Installed Timer Driver");
	timer_install(); 
	
	t_writeln(":: Installed Keyboard Driver"); 
	keyboard_install(); 
	
	t_writeln(""); 
	t_writeln("- Setting Up Environment"); 
	
	t_writeln(":: Creating Keymap (EN-US Set 1)");
	set_en_us_set1(&KEYBOARD_MAP); 
	
	t_writeln(":: Creating Primary Memory Block"); 
	memstackinit(); 
};

/* Main Function 
** 	- Main function for the kernel 
** 	- Starts all kernel operations 
*/
void kernel_main()
{
	kernal_init();
	
	/* ###########################################################
	** ################## TEST ZONE ############################# */ 
	t_wipe_console(); 
	t_reset(); 

		

	t_writeln("Done."); 

	/* ################ END ZONE ###############################
	** ########################################################*/
};

