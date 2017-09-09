/*
 * read-only for array decorated by const
 * const array space cannot be modified
 */

#include <stdio.h>

void main()
{
#ifdef OFF
	const int a = 1;
	int *p = (int *)&a;
	*p = 2;
	printf("%d\n", a);
#endif
	const int A[5] = {1, 2, 3, 4, 5};
	int *p = (int *)A;
	*(p + 2) = 3;
	p[2] = 4;
	printf("%d\n", *(p + 2));
	printf("%d\n", p[2]);
}
