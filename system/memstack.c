/* Memory Allocation Stack Driver
** Author: 
** Date: 01/29/2012
** Description: 
** 	 Controls the stack style of 
** management for malloc and the allocation
** of memory for variables within processes. 
*/

#include <foundation/memory.h> 
#include <foundation/membloc.h>
#include <foundation/textmode.h>
#include <foundation/system.h>

void memstackinit() { 
	*SYSTEM_PRIMARY_MEMORY_BLOCK = &endstub;   
}
