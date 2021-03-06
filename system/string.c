/* String Library Definitions
** Author: Will Dignazio 
** Description: 
** 	Library for standard string manipulation and 
** functionality. 
*/

#include <foundation/textmode.h>

/* Returns the string value of the integer, 
** which is up to 25 bytes long in length. 
*/
char* itos(int num)
{
	static buffer[25]; 
	
	// Since the buffer is static, we have to wipe it
	// from the last use. 
	int i = 0;
	for(i=0; i<25; i++)
	{ buffer[i] = '\0'; }

	if (num>9) { 	
		int columns = 0; 
		int highest = 0; 
		while(highest<num)
		{  highest = highest * 10; }
		while(highest != 0)
		{
			columns++; 
			highest /= 10; 
		}
		int i = 0;
		for(i=0; i<columns; i++)
		{ 
			buffer[i] = i+'0';
		}
	} else { 
		buffer[0] = num+'0'; 
	} 

	return (int)&buffer[0];
}


/* Returns the length of a character 
** array provided in the arguments */
int strlen(unsigned char string[])
{
	unsigned char i = 0; 
	while(string[i]!='\0')
	{ i++; }
	return i; 
}
