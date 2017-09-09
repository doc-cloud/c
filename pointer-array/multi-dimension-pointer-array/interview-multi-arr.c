#include <stdio.h>

int main()
{
	//type for a , int (*)[5];
	int a[5][5];

	//type for p , int (*)[4];
	int(*p)[4];

	//incompatible assignment
	p = a;

	printf("%d\n", &p[4][2] - &a[4][2]);
}
