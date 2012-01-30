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

/* Initializes the memory stack that the kernel uses 
** for processes and variable malloc's.  
** Constructing a primary memory block descriptor at the end 
** of the kernel, the endstub's address, the stack can be setup
** and used accordingly. Once the initial descriptor is in, a beginning
** child descriptor is installed for the first task of the kernel. 
*/
void memstackinit() {
	int primary_addr = &endstub;
	int child_addr = &endstub + sizeof(PRIMARY_MEMORY_BLOCK)+1; 

	/* We need to set the memory, assuring safe values of 0. 
	** After the memory is set to the accoring size, we are 
	** going to have to create descriptors here and memcpy 
	** them in.*/
	t_writeln("  -> Initializing memory"); 
	memset(primary_addr, 0, sizeof(PRIMARY_MEMORY_BLOCK));
	memset(child_addr, 0, sizeof(MEMORY_BLOCK)); 

	/* After wiping the memory intitially, we have to create
	** the actual objects that will go in them here. Since we 
	** can't just tell there to be a struct at a location, we 
	** have to memcpy it in. */
	t_writeln("  -> Creating primary block descriptor"); 
	struct PRIMARY_MEMORY_BLOCK primary; 
	primary.REGION.START = child_addr; 
	primary.START = child_addr;
	//primary.END = NULL; 

	/* Even though the primary memory block is in place, 
	** we need a more efficient way of finding out the 
	** entirety of the allocated memory. Since there is a 
	** primary descriptor, all we need to do is set a child 
	** to the start of the primary block. This initial child
	** block has a scope of the entire memory currently, but 
	** should be marked as volatile and destroyable in the 
	** attribute byte. */
	t_writeln("  -> Creating initial block descriptor"); 
	struct MEMORY_BLOCK child; 
	child.REGION.START = primary.REGION.START; 
	child.REGION.END = 0xFFFFFFFF;

	/* After everything in the blocks has been initialized, 
	** the blocks need to be copied from here, to the end of the 
	** stable kernel code and data (&endstub). Here we are moving 
	** the primary memory block into memory. */
	t_writeln("  -> Installing primary memory block"); 	
	memcpy(primary_addr, &primary, sizeof(PRIMARY_MEMORY_BLOCK)); 

	/* After the install of the primary memory block, the first 
	** removable child block needs to be installed at the tail of 
	** the primary descriptor. */
	t_writeln("  -> Installing initial block descriptor"); 
	memcpy(child_addr, &child, sizeof(MEMORY_BLOCK)); 

	/* There is a system wide pointer to the primary memory block, 
	** which allows vital kernel systems easy access to the block. 
	** while there may be more than one primary block at another time, 
	** the init process simply sets it to the first one installed. */
	t_writeln("  -> Pointing primary block descriptor"); 
	PRIMARY_MEMORY_BLOCK *SYSTEM_PRIMARY_MEMORY_BLOCK = primary_addr; 

}
