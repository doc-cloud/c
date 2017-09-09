#include <stdio.h>

#define N 10

void display(int *arr, int num)
{
	int i;
	for (i = 0; i < num; i++)
		printf("arr[%d] = %d\n", i, arr[i]);
}

void swap(int *num0, int *num1)
{
	int tmp;
	tmp = *num0;
	*num0 = *num1;
	*num1 = tmp;
}

void bubble_sort(int *arr, int num, int (*compare_func)(int num0, int num1))
{
	int i, j;
	for (i = 0; i < num; i++)
		for (j = N - 1; j > i; j--)
			if (compare_func(arr[j], arr[i]))
				swap(&arr[i], &arr[j]);
}

int ascending(int num0, int num1)
{
	return num0 > num1 ? 0 : 1;
}

int decending(int num0, int num1)
{
	return num0 > num1 ? 1 : 0;
}

void main()
{
	int arr[N] = {
		12, 34, 21, 46, 89, 54, 26, 8, 6, 17
	};
	printf("before sortition\n");
	display(arr, N);
	bubble_sort(arr, N, ascending);
	printf("after ascending bubble sort\n");
	display(arr, N);
	bubble_sort(arr, N, decending);
	printf("after decending bubble sort\n");
	display(arr, N);
}
