
#include <stdio.h>
#include <string.h>

int main ()
{
	const char str[] = "http://www.linkerist.com";
	const char ch = '.';
	char *ret;

	ret = strchr(str, ch);

	printf("string after '%c' is - '%s'\n", ch, ret);

	return 0;
}

