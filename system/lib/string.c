/* String Library Definitions
** Author: Will Dignazio 
** Description: 
** 	Library for standard string manipulation and 
** functionality. 
*/

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

	// Number is larger than what we can just append '0' to.
	if(num>10)
	{ 
		int columns = 1;
		int highest = 10; 
		while(highest<num)
		{ 
			columns++; 
			highest *= 10; 
		}
	} else {
		buffer[0] = num + '0'; 
	}
	return &buffer;
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
