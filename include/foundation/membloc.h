/* Memory Management Blocks Library 
** Author: Will Dignazio
** Date: 01/28/2012
** Description: 
**		Structure blocks for memory management 
**	and task scheduling. 
*/


#ifndef MEMBLOC_GAURD_H
#define MEMBLOC_GAURD_H
typedef struct REGISTER_BLOCK { 
	unsigned int EAX, EBX, ECX, EDX; 
	unsigned int EFLAGS; 
	unsigned int ESI, EDI, EBP, ESP; 
	unsigned int EIP; 
} REGISTER_BLOCK; 

typedef struct DESCRIPTOR_BLOCK { 
	unsigned int START; 
	unsigned int END; 
} DESCRIPTOR_BLOCK; 
typedef struct PROCESS_BLOCK { 
	DESCRIPTOR_BLOCK CODE; 
	DESCRIPTOR_BLOCK DATA; 
	DESCRIPTOR_BLOCK STATIC; 
	unsigned short ATTRIBUTES;
} PROCESS_BLOCK; 

typedef struct MEMORY_BLOCK {
	DESCRIPTOR_BLOCK REGION; 
	unsigned short ATTRIBUTES; 
} MEMORY_BLOCK; 

typedef struct PRIMARY_MEMORY_BLOCK { 
	DESCRIPTOR_BLOCK REGION; 
	MEMORY_BLOCK* START; 
} PRIMARY_MEMORY_BLOCK; 

#endif
