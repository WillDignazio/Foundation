/* Keymap Code 
** Author: Will Dignazio 
** Description: 
**	Contains functions for settings keymaps to the keyboard handler. 
** Contains methodology of setting the keyboard map to different settings, 
** such as dvorak and different languages other then US english. 
*/

#include "keymap.h"

void set_en_us_set1(KEYMAP *keymap)
{
	(*keymap).name[25] = "EN-US Set 1";  
	/* Lowercase Set */
	(*keymap).lowercase[0x1E] = 'a';
	(*keymap).lowercase[0x30] = 'b'; 
	(*keymap).lowercase[0x2E] = 'c'; 
	(*keymap).lowercase[0x20] = 'd'; 
	(*keymap).lowercase[0x12] = 'e'; 
	(*keymap).lowercase[0x21] = 'f'; 
	(*keymap).lowercase[0x22] = 'g'; 
	(*keymap).lowercase[0x23] = 'h'; 
	(*keymap).lowercase[0x17] = 'i'; 
	(*keymap).lowercase[0x24] = 'j'; 
	(*keymap).lowercase[0x25] = 'k'; 
	(*keymap).lowercase[0x26] = 'l'; 
	(*keymap).lowercase[0x32] = 'm'; 
	(*keymap).lowercase[0x31] = 'n'; 
	(*keymap).lowercase[0x18] = 'o'; 
	(*keymap).lowercase[0x19] = 'p'; 
	(*keymap).lowercase[0x10] = 'q'; 
	(*keymap).lowercase[0x13] = 'r'; 
	(*keymap).lowercase[0x1F] = 's'; 
	(*keymap).lowercase[0x14] = 't'; 
	(*keymap).lowercase[0x16] = 'u'; 
	(*keymap).lowercase[0x2F] = 'v'; 
	(*keymap).lowercase[0x11] = 'w'; 
	(*keymap).lowercase[0x2D] = 'x'; 
	(*keymap).lowercase[0x15] = 'y'; 
	(*keymap).lowercase[0x2C] = 'z'; 
	(*keymap).lowercase[0x0B] = '0'; 
	(*keymap).lowercase[0x02] = '1'; 
	(*keymap).lowercase[0x03] = '2'; 
	(*keymap).lowercase[0x04] = '3'; 
	(*keymap).lowercase[0x05] = '4'; 
	(*keymap).lowercase[0x06] = '5'; 
	(*keymap).lowercase[0x07] = '6'; 
	(*keymap).lowercase[0x08] = '7'; 
	(*keymap).lowercase[0x09] = '8'; 
	(*keymap).lowercase[0x0A] = '9'; 
	(*keymap).lowercase[0x29] = '`';		// Apostrophe 
	(*keymap).lowercase[0x0C] = '-';		// Dash 
	(*keymap).lowercase[0x0D] = '=';		// Equals Symbol 
	(*keymap).lowercase[0x2B] = '\\';		// Forward Slash 
	(*keymap).lowercase[0x0E] = '*';		// Backspace  
	(*keymap).lowercase[0x39] = ' ';		// Space 
	(*keymap).lowercase[0x0F] = '*';		// Tab 
	(*keymap).lowercase[0x3A] = '*';		// Caps lock 
	(*keymap).lowercase[0x1C] = '*';		// Enter 
	(*keymap).lowercase[0x01] = '*';		// Escape 
	(*keymap).lowercase[0x3B] = '*'; 		// F1
	(*keymap).lowercase[0x3C] = '*'; 		// F2
	(*keymap).lowercase[0x3D] = '*'; 		// F3
	(*keymap).lowercase[0x3E] = '*'; 		// F4
	(*keymap).lowercase[0x3F] = '*'; 		// F5
	(*keymap).lowercase[0x40] = '*'; 		// F6
	(*keymap).lowercase[0x41] = '*'; 		// F7
	(*keymap).lowercase[0x42] = '*'; 		// F8
	(*keymap).lowercase[0x43] = '*'; 		// F9
	(*keymap).lowercase[0x44] = '*'; 		// F10
	(*keymap).lowercase[0x57] = '*';		// F11
	(*keymap).lowercase[0x58] = '*'; 		// F12


	/* Uppercase Set */


}

void set_en_us_set2(KEYMAP *keymap)
{
	(*keymap).lowercase[0x1C] = 'a'; 
	(*keymap).lowercase[0x32] = 'b'; 
	(*keymap).lowercase[0x21] = 'c'; 
	(*keymap).lowercase[0x23] = 'd'; 
	(*keymap).lowercase[0x24] = 'e'; 
	(*keymap).lowercase[0x2B] = 'f'; 
	(*keymap).lowercase[0x34] = 'g'; 
	(*keymap).lowercase[0x33] = 'h';
	(*keymap).lowercase[0x43] = 'i'; 
	(*keymap).lowercase[0x3B] = 'j'; 
	(*keymap).lowercase[0x42] = 'k'; 
	(*keymap).lowercase[0x4B] = 'l'; 
	(*keymap).lowercase[0x3A] = 'm'; 
	(*keymap).lowercase[0x31] = 'n'; 
	(*keymap).lowercase[0x44] = 'o'; 
	(*keymap).lowercase[0x4D] = 'p'; 
	(*keymap).lowercase[0x15] = 'q'; 
	(*keymap).lowercase[0x2D] = 'r'; 
	(*keymap).lowercase[0x1B] = 's'; 
	(*keymap).lowercase[0x2C] = 't'; 
	(*keymap).lowercase[0x3C] = 'u'; 
	(*keymap).lowercase[0x2A] = 'v'; 
	(*keymap).lowercase[0x1D] = 'w'; 
	(*keymap).lowercase[0x22] = 'x'; 
	(*keymap).lowercase[0x35] = 'y'; 
	(*keymap).lowercase[0x1A] = 'z'; 

} 
