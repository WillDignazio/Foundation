/* Terminus Kernel Shell
** Author: Will Dignazio 
** Description: 
**	Shell program for the SOS kernel. Allows for single user mode in the 
** kernel, providing a simple interface between the kernel program and the 
** user. 
*/
#include <foundation/stdapp.h>
#include <foundation/stdio.h>
#include <foundation/system.h>
#include <foundation/string.h>
#include <terminus/interface.h>
#include <terminus/inputmod.h>

void (*testptr)() = keyboard_handler; 
bool run_super = false; 
unsigned char input_buffer[150]; 
unsigned char prompt[] ="F:/> "; 

/* Removes the old keyboard input 
** handler, and replaces it with a 
** wrapper that adds on new 
** functionality specifically for 
** this application 
*/
void terminus_keyboard_handler()
{ 
	keyboard_handler(); 
	if (run_super){
	t_type(*(STDIO_INPUT_POINTER-1)); 
	run_super = !run_super; 
	} 
	else { run_super = true; }
}

/* Custom keyboard interrupt handler for the shell */
void terminus_handlers_install()
{ 
	irq_install_handler(1, terminus_keyboard_handler); 
}
		
/* Main function for the shell, this simply allows 
** a repeated function after setting the shell custom 
** interrupt handler. */
int terminus(unsigned char args[])
{
	t_wipe_console(); 
	t_reset(); 

	t_writeln(":: Terminus ::"); 
	terminus_handlers_install(); 
	STDIO_INPUT_POINTER = &input_buffer[0]; //NOTE: This is a crucial step, that if multiprocessing becomes a thing, must be replicated. 
	t_write(prompt);
	char *str = itos(100);
	t_write(str);
	while(1){};			// Just hang around until the user does something. 

	return 0; 
} 

