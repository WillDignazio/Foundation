/* Core Functions 
** Author: Will Dignazio
** Description: 
**	This file contains the core functions for the kernel, these include 
** functions for manipulating values via the kernel, and aspects of the 
** memory. 
*/
/* Ouput byte to an I/O location */
void outb(unsigned short port, unsigned char val)
{
	asm volatile("outb %0, %1"
				: : "a"(val), "Nd"(port) );
};

/* Read byte from an I/O location */
unsigned char inb(unsigned short port)
{ 
	unsigned char ret; 
	asm volatile("inb %1, %0"
				: "=a"(ret) : "Nd"(port) );

	return ret; 
};

/* Forces CPU to wait for an I/O operation to complete. */
void io_wait(void)
{ 
	asm volatile("outb %%al, $0x80"
					: : "a"(0) );
};

