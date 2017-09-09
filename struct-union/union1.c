#include <stdio.h>
#include <stdlib.h>

#include <string.h>

union A {
	char a;
	char *b;
};

int main(void)
{
	union A a;
	a.b = malloc(100);
	free(b);
	/* if there are pointers member in union, we must free this pointer after use it, then you can use other member */
	/* b is 10 as well */
	a.a = 10;
	//a.b = 20;

	printf("%d\n", sizeof(union A));
	printf("%p, %p\n", &a.a, &a.b);
	printf("a = %x\n", a.a);
	printf("b = %x\n", a.b);
	return 0;
}
