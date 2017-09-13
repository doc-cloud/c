#include <stdio.h>
#include <ctype.h>

int main()
{
	int i = 0;
	char str[] = "Linkerist Heracles";

	while(str[i])
		putchar(toupper(str[i++]));
	printf("\n");

	i = 0;
	while(str[i])
		putchar(tolower(str[i++]));
	printf("\n");

	return(0);
}
