#include <stdio.h>
#include <malloc.h>
#include <string.h>

void func(char* p)
{
	printf("%s\n", p);
	free(p);
}

int main()
{
	char* s = (char*)malloc(5);

	strcpy(s, "Linkerist Heracles");

	func(s);

	/* oops */
	printf("%s\n", s);

	return 0;
}
