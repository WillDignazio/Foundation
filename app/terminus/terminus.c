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

unsigned char input_buffer[150]; 
unsigned char prompt[] ="F:/> "; 

void terminus_keyboard_handler()
{ 
	keyboard_handler(); 
	t_type('w'); 
}

void terminus_handlers_install()
{ 
	irq_install_handler(1, terminus_keyboard_handler); 
}
		

int terminus(unsigned char args[])
{
	t_wipe_console(); 
	t_reset(); 

	t_writeln(":: Terminus ::"); 
	t_writeln("Installing New Handler"); 
	terminus_handlers_install(); 
	t_writeln("Setting STDIO_INPUT_POINTER");
	STDIO_INPUT_POINTER = &input_buffer[0]; 
	t_write(prompt);
	while(1){};

	return 0; 
} 

