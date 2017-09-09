#include <stdio.h>

struct null_st {
	
};

int main()
{
	struct null_st n1;
	struct null_st n2;

	printf("%d\n", sizeof(struct null_st));
	printf("%d,%0X\n", sizeof(n1), &n1);
	printf("%d,%0X\n", sizeof(n2), &n2);

	return 0;
}
