
#include<stdio.h>

int main()
{
	char c;

	printf("Enter character: \n");
	c = getc(stdin);
	printf("Character entered: \n");
	putc(c, stdout);

	return(0);
}

