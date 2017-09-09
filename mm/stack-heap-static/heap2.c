#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
	// char *p = malloc(10);
	/* clean up automatically */
	char *p1 = calloc(10, sizeof(char));
	//memset(p, 0, 10);

	/* add continuous memory in the original base heap */
	//char *p2 = realloc(p1, 20);
	/* if there is no continuous memory to expand, then allocate a new space, copy the old to new, release the old memory block */
	//realloc, malloc, just allocate

	//char *p2 = calloc(10, sizeof(char));

	//char *p2 = realloc(p1, 5);

	char *p2 = realloc(NULL, 5);

	int i;
	for (i = 0; i < 20; i++)
		printf("%d\n", p2[i]);

	free(p2);

	return 0;
}
