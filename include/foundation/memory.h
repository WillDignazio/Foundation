/* Memory Allocation and Freeing Header
** Author: Will Dignazio
** Date: 01/28/2012
** Description: 
**		Header file for functions 
** 	structs for allocating a freeing memory 
** 	under the control of the kernel. 
*/

#ifndef MEMORY_GAURD_H
#define MEMORY_GAURD_H

#include "membloc.h"
#include "system.h"

extern PRIMARY_MEMORY_BLOCK* SYSTEM_PRIMARY_MEMORY_BLOCK; 

/* Memory Stack Driver */
void meminit(); 
void set_attribute(unsigned char, MEMORY_BLOCK*); 

bool checkEndBlock(MEMORY_BLOCK*); 
bool checkFree(MEMORY_BLOCK*); 


void memcpy(unsigned char*, unsigned char*,unsigned int); 
void memset(unsigned char*,unsigned int,unsigned int); 
MEMORY_BLOCK* malloc(int); 

#endif
