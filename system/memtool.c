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

void memcpy(unsigned char* addr, unsigned char* value, unsigned int size) { 
	unsigned int i = 0; 
	for (i=0; i<size; i++)
	{
		addr[i] = value[i]; 	
	}
}

void memset(unsigned char* addr, unsigned int val, unsigned int len) { 
	unsigned int i = 0;
	for(i=0; i<len; i++)
	{ 
		addr[i] = val; 
	}
}

int* malloc(int size) 
{
	
	return 0; 
}

