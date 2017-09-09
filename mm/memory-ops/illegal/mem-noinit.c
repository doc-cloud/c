#include <stdio.h>
#include <malloc.h>

int main()
{
	char *s = (char *)malloc(10);

	/* oops */
	printf(s);

	free(s);

	return 0;
}
