
#include <stdio.h>
#include <stdlib.h>

int main()
{
	int i;
	wchar_t wc = L'a';
	char *pmbnull = NULL;
	char *pmb = (char *)malloc(sizeof( char ));

	printf("Converting wide character:\n");
	i = wctomb( pmb, wc );
	printf("Characters converted: %u\n", i);
	printf("Multibyte character: %.1s\n", pmb);

	printf("Trying to convert when target is NULL:\n");
	i = wctomb( pmbnull, wc );
	printf("Characters converted: %u\n", i);
	/* this will not print any value */
	printf("Multibyte character: %.1s\n", pmbnull);

	return(0);
}

