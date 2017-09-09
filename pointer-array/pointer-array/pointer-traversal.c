#include <stdio.h>

void main()
{
	int arr[5] = {
		0, 1, 2, 3, 4
	};
	int i;
	int *ptr = &arr[0];
	for (i = 0; i < 5; i++)
		printf("arr[%d] = %d\n", i, arr[i]);
	for (i = 0; i < 5; i++)
		printf("*(arr + %d) = %d\n", i, *(ptr + i));
	for (i = 0; i < 5; i++)
		printf("ptr[%d] = %d\n", i, ptr[i]);
	for (i = 0; i < 5; ptr++, i++)
		printf("*ptr = %d\n", *ptr);
}
