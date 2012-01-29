/* Memory Allocation Tool
** Author: Will Dignazio 
** Date: 01/28/2012
** Description: 
**		Code for tool to allocate
**	memory based on the free space available
**	within the physical memory. 
*/

#include <foundation/system.h>
#include <foundation/memory.h>
#include <foundation/membloc.h>
#include <foundation/textmode.h>

/* actual malloc function, 
** just takes a size and return 
** the address to the memory allocated. 
*/
int* malloc(int size) 
{
	t_writeln("mallocing away"); 	
	
	return 0; 
}
