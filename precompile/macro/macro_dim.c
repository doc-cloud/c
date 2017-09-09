#include <stdio.h>

#define DIM(arr) (sizeof(arr) / sizeof(*arr))

int dim(int arr[])
{
	return sizeof(arr) / sizeof(*arr);
}

int main()
{
	int arr[] = {1,2,3,4};
	printf("%d\n",dim(arr));
	printf("%d\n",DIM(arr));
}
