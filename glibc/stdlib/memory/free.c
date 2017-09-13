
#include <stdio.h>
#include <stdlib.h>

int main()
{
	char *str;

	/* Initial memory allocation */
	str = (char *) malloc(15);
	strcpy(str, "yiibai");
	printf("String = %s,  Address = %u
	", str, str);

	/* Reallocating memory */
	str = (char *) realloc(str, 25);
	strcat(str, ".com");
	printf("String = %s,  Address = %u
	", str, str);

	/* Deallocate allocated memory */
	free(str);

	return(0);
}

