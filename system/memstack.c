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
	int primary_addr = &endstub;
	int child_addr = &endstub + sizeof(PRIMARY_MEMORY_BLOCK)+1; 
	
	t_writeln("  -> Initializing memory"); 
	memset(primary_addr, 0, sizeof(PRIMARY_MEMORY_BLOCK));
	memset(child_addr, 0, sizeof(MEMORY_BLOCK)); 

	t_writeln("  -> Creating primary block descriptor"); 
	struct PRIMARY_MEMORY_BLOCK primary; 
	primary.REGION.START = child_addr; 
	/* START is really a pointer to a MEMORY block, but we're fooling it. */
	primary.START = child_addr;  

	t_writeln("  -> Creating initial block descriptor"); 
	struct MEMORY_BLOCK child; 
	child.REGION.START = primary.REGION.START; 
	primary.REGION.END = 0xFFFFFFFF;
	
	t_writeln("  -> Installing primary memory block"); 	
	memcpy(primary_addr, &primary, sizeof(PRIMARY_MEMORY_BLOCK)); 

	t_writeln("  -> Installing initial block descriptor"); 
	memcpy(child_addr, &child, sizeof(MEMORY_BLOCK)); 

	t_writeln("  -> Pointing primary block descriptor"); 
	PRIMARY_MEMORY_BLOCK *SYSTEM_PRIMARY_MEMORY_BLOCK = primary_addr; 

}
