#include <stdio.h>

void main()
{
	int i, j;
	int arr[3][4] = {
		{1, 2, 3, 4},
		{5, 6, 7, 8},
		{9, 10, 11, 12}
	};
	int (*ptr)[4];
	for (i = 0; i < 3; i++)
		for (j = 0; j < 4; j++)
			printf("arr[%d][%d] = %d\n", i, j, arr[i][j]);

	for (ptr = arr, i = 0; ptr < arr + 3; ptr++, i++)
		for (j = 0; j < 4; j++)
			printf("ptr[%d][%d] = %p, %d\n", i, j, *ptr + j, *(*ptr + j));
	//printf("%ld, %ld\n", sizeof(int), sizeof(int *));
	//printf("%ld, %ld\n", sizeof(char), sizeof(char *));
}
