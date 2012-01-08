/* Terminus Kernel Shell
** Author: Will Dignazio 
** Description: 
**	Shell program for the SOS kernel. Allows for single user mode in the 
** kernel, providing a simple interface between the kernel program and the 
** user. 
*/
#include "../stdapp.h"
#include "../../stdio/stdio.h"
#include "../../system/system.h"

unsigned char input_buffer[150]; 

int terminus(unsigned char args[])
{
	//TODO: If there are to be arguments, handle them here. 
	t_wipe_console(); 
	t_reset(); 
	
	t_writeln(":: Terminus ::"); 
	while(1==1){ }; 

	return 0; 
} 
