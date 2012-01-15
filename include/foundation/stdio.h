#ifndef STDIO_H_GAURD
#define STDIO_H_GAURD	

#include "keymap.h"

static unsigned int STDIO_COLUMN = 0; 
static unsigned int STDIO_ROW = 0; 
 
unsigned char *STDIO_INPUT_POINTER; 

/* Keyboard Driver Functions */
void keyboard_handler(); 
void keyboard_install(); 
void set_input_buffer(unsigned char *buffer); 

/* Universal Keyboard Map Settings */
KEYMAP KEYBOARD_MAP; 

#endif 

