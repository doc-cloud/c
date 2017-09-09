#include <stdio.h>

/*
 * for one level array, c is the address of the first element, c + 1 signify 4 steps
 * &c is the whole array address, &c + 1 signify 200 * 4 steps
 */
void main0()
{
	int (*parr)[5];
	int arr[5];
	int i;
	parr = &arr;

	for (i = 0; i < 5; i++)
		(*parr)[i] = i;

	for (i = 0; i < 5; i++)
		printf("%d ", (*parr)[i]);

	printf("\n");
}

void main1()
{
	typedef int (*parr_ty)[5];
	parr_ty parr;
	int arr[5];
	int i;
	parr = &arr;

	for (i = 0; i < 5; i++)
		(*parr)[i] = i;

	for (i = 0; i < 5; i++)
		printf("%d ", (*parr)[i]);

	printf("\n");
}

void main2()
{
	typedef int (arr_ty)[5];
	arr_ty *arr_var;
	int i;
	int arr[5];
	arr_var = &arr;
	for (i = 0; i < 5; i++)
		(*arr_var)[i] = i;
	for (i = 0; i < 5; i++)
		printf("%d ", (*arr_var)[i]);

	printf("\n");
}

void main()
{
	int i;
	typedef int (arr_ty)[5];
	arr_ty arr_var;

	for (i = 0; i < 5; i++)
		arr_var[i] = i;

	for (i = 0; i < 5; i++)
		printf("%d ", arr_var[i]);

	printf("\n");
}
