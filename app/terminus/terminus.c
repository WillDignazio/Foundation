/* Terminus Kernel Shell
** Author: Will Dignazio 
** Description: 
**	Shell program for the SOS kernel. Allows for single user mode in the 
** kernel, providing a simple interface between the kernel program and the 
** user. This  
*/
#include <foundation/stdapp.h>
#include <foundation/stdio.h>
#include <foundation/system.h>
#include <foundation/string.h>

unsigned char input_buffer[150]; 
unsigned char prompt[] ="F:/> "; 
		
/* Main function for the shell, this simply allows 
** a repeated function after setting the shell custom 
** interrupt handler. */
int terminus(unsigned char args[])
{
	t_wipe_console(); 
	t_reset(); 

	t_writeln(":: Terminus ::"); 
	t_write(prompt);

	unsigned int num = 1510; 
	char *str = itos(num); 
	t_write(str);
	t_writeln("");
	t_writeln("Done.");

	while(1){};			// Just hang around until the user does something. 

	return 0; 
} 

