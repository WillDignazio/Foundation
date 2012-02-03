/* Memory Allocation Tools 
** Author: Will Dignazio
** Date: 01/29/2012
** Description: 
** 	Function for setting a given memory 
** address to the given data structure or 
** array of data. 
*/

#include <foundation/system.h>
#include <foundation/memory.h>
#include <foundation/membloc.h>
#include <foundation/textmode.h>

/* Memory copy utility for copying bytes from one area of memory 
** to another part of memory. The two addresses are the start addresses
** that will be iterated through to copy, first arg is destination pointer, 
** the second is the object to be copied. The third arg is a int of how
** many bytes you want to copy. */
void memcpy(unsigned char* addr, unsigned char* value, unsigned int size) { 
	unsigned int i = 0; 
	for (i=0; i<size; i++)
	{
		addr[i] = value[i]; 	
	}
}

/*  Memory setting tool for copying to an address of a specified size
**  a specified value. Primarily for wiping or presetting memory
** 	before being used. */
void memset(unsigned char* addr, unsigned int val, unsigned int len) { 
	unsigned int i = 0;
	for(i=0; i<len; i++)
	{ 
		addr[i] = val; 
	}
}

/* Dynamic memory allocation tool for allocating memory 
** using the memory stack driver in the system. The malloc 
** utility allocates a memory block of space and return a 
** memory block pointer to it. The block will have the 
** attribute byte set to free and editable, so that the program receiving 
** it will be able to use it and custom set other attributes. 
*/
MEMORY_BLOCK* malloc(int size) 
{
	
	return 0; 
}

