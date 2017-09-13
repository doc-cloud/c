
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
	long val;
	char str[20];

	strcpy(str, "98993489");
	val = atol(str);
	printf("String value = %s, Long value = %ld\n", str, val);

	strcpy(str, "yiibai.com");
	val = atol(str);
	printf("String value = %s, Long value = %ld\n", str, val);

	return(0);
}

