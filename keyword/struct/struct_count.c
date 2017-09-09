#include <stdio.h>

struct Test {
	char c1;
	short s;
	char c2;
	int i;
};

int main()
{
	printf("%d\n",sizeof(struct Test));
	return 0;
}
