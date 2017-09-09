#include <stdio.h>

union C {
	int i;
	char c;
};

void main()
{
	union C c;
	c.i = 1;
	printf("%d\n",c.c);
}
