/* String Library Definitions
** Author: Will Dignazio 
** Description: 
** 	Library for standard string manipulation and 
** functionality. 
*/

int strlen(unsigned char string[])
{
	unsigned char i = 0; 
	while(string[i]!='0')
	{ i++; }
	return i; 
}
