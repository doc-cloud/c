
#include <stdio.h>
#include <string.h>

int main ()
{
	const char src[50] = "Linkerist Heracles";
	char dest[50] = {0};

	printf("Before memcpy dest = %s\n", dest);
	memcpy(dest, src, strlen(src) + 1);
	printf("After memcpy dest = %s\n", dest);

	return 0;
}

