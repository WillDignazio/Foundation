/* Memory Allocation Stack Driver
** Author: 
** Date: 01/29/2012
** Description: 
** 	 Controls the stack style of 
** management for malloc and the allocation
** of memory for variables within processes. 
*/

#include <foundation/membloc.h>
#include <foundation/textmode.h>
#include <foundation/system.h>
#include <foundation/memory.h> 

void memstackinit() {
	t_writeln(":::: Initializing memory"); 
	memset(&endstub, 0, sizeof(PRIMARY_MEMORY_BLOCK));
	t_writeln(":::: Creating descriptor"); 
	struct PRIMARY_MEMORY_BLOCK primary; 
	primary.REGION.START = &endstub; 
	primary.REGION.END = 0xFFFFFFFF;
	t_writeln(":::: Installing primary memory block"); 	
	memcpy(&endstub, &primary, sizeof(PRIMARY_MEMORY_BLOCK)); 
	t_writeln(":::: Pointing primary block descriptor"); 
	PRIMARY_MEMORY_BLOCK *SYSTEM_PRIMARY_MEMORY_BLOCK = &endstub; 
}
