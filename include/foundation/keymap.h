/* Keyboard Maps Header 
** Author: Will Dignazio 
** Description: 
** 	Layouts for different key maps, 
** while an enormous amount of seemingly uneccesary code, 
** it really is unfortunately. 
*/

#ifndef KEYMAP_H_GUARD
#define KEYMAP_H_GAURD

typedef struct KEYMAP { 
	unsigned char lowercase[256]; 
	unsigned char uppercase[256]; 
	unsigned char name[25]; 
} KEYMAP; 


void set_en_us_set1(KEYMAP *keymap);	// US keymap scancode set 1 
void set_en_us_set2(KEYMAP *keymap);	// US keymap scancode set 2
void set_en_us_set3(KEYMAP *keymap); 	// US keymap scancode set 3

#endif


