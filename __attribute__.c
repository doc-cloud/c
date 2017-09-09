#include <stdio.h>

struct node {
	char c;
	int i __attribute__((aligned(256)));
	short s;
	double f;
};

void main()
{
	struct node x;
	printf("%ld\n", sizeof x);
}
