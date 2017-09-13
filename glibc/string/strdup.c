
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main()
{
	char *src = "this is a test";
	char *dst;

	dst = strdup(src);
	printf("%s\n",dst);

	if(NULL != dst)
		free(dst);

	return 0;
}

