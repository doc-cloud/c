/*
 * compiler inline keyword, it is not function,
 * calculate the entity size, the value should confirm when compile stage
 */

#include <stdio.h>

int main()
{
	int a;

	printf("%ld\n", sizeof(a));
	printf("%ld\n", sizeof a);
	printf("%ld\n", sizeof(int));
	/* contain the '\0' */
	printf("%ld\n", sizeof("Linkerist Heracles"));

	return 0;
}
