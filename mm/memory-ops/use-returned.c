#include <stdio.h>

char *func()
{
	char p[] = "Linkerist Heracles";

	return p;
}

int main()
{
	char *s = func();

	/* oops */
	printf("%s\n", s);

	return 0;
}
