/* Memory Allocation and Freeing Header
** Author: Will Dignazio
** Date: 01/28/2012
** Description: 
**		Header file for functions 
** 	structs for allocating a freeing memory 
** 	under the control of the kernel. 
*/

#ifndef MEMORY_GAURD_H
#define MEMORY_GARUD_H

#include "membloc.h"

extern PRIMARY_MEMORY_BLOCK* SYSTEM_PRIMARY_MEMORY_BLOCK; 

int* malloc(int); 
void meminit(); 

#endif
