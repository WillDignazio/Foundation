/* Keyboard Driver
** Author: Will Dignazio 
** Description: 
**	Keyboard driver for SOS, contains functions for handling keyboard input
** in protected mode. 
*/

#include <foundation/stdio.h>
#include <foundation/sysio.h>
#include <foundation/system.h>

KEYMAP KEYBOARD_MAP;
unsigned char shift_state = 0; 

/* Keyboard Handler: Run when keyboard interrupt is fired */
void keyboard_handler()
{	
	unsigned char scancode = inb(0x60); 	// Get input
	switch(scancode) 
	{ 
		case 0x2a: 							// Output scancode for shift-make 
			shift_state = 1;
			break;
		case 0xaa:							// Output scancode for shft-break (release)  
			shift_state = 0; 
			break; 
		default: 
			if(scancode & 0x80) 
			{ 
				//break code, don't really need right now. 
			} else 
			{ 
				// If the shiftstate is true, we're in the uppercase zone, else we're in the lowercase set. 
				unsigned char new_scan = (shift_state ? KEYBOARD_MAP.uppercase:KEYBOARD_MAP.lowercase)[scancode];
				*STDIO_INPUT_POINTER = new_scan;
				STDIO_INPUT_POINTER++; 				
			}
			break; 
	}
	outb(0x20, 0x20);						// EOI 
}



/* Keyboard IRQ Installer */
void keyboard_install()
{ 
	irq_install_handler(1, keyboard_handler); 
} 
