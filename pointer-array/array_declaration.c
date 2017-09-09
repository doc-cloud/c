#include <stdio.h>

// another file
// char *ptr = "Hello World!";

extern char ptr[];

int main()
{
	//regard ptr as a char arr name,print the arr as a string
	//eg:print 0xaabbcc00 as 0xaa,0xbb,0xcc,0x00
	printf("%s\n", ptr);
	
	//regard ptr as a ptr for char
	//printf("%s\n",(char *)(*((unsigned int *)ptr)));
	
	return 0;
}
