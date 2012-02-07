/* Memory Attribute Checking Tools
** Author: Will Dignazio 
** Description:
**	Helper file for the stack memory manager 
** driver. Contains tools for checking the attribute
** byte of a memory block, and other various attribute 
** properties. 
*/

#include <foundation/system.h>
#include <foundation/binary.h>
#include <foundation/textmode.h>

/* Checks the first bit of the memory 
** blocks attribute byte to see if the 
** block is in use by a program. */
bool checkFree(MEMORY_BLOCK* block) { 
	char attr_byte = (*block).ATTRIBUTES; 
	attr_byte = attr_byte << 7; 
	if (attr_byte > b01111111) { 
		return false; } 
	return true;  
} 

/* Checks the end bit of the memory block attribute byte
** to see if the block is designated as the 
** end block in the memory. */
bool checkEndBlock(MEMORY_BLOCK* block) { 
	if ((*block).ATTRIBUTES > b01111111) { 
		return true; }
	return false; 
} 

