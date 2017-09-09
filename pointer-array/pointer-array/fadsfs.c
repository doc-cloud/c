#include <stdio.h>

void multi_arr(int (*ptr)[3])
{
	printf("%d\n",sizeof(ptr));
	printf("%d\n",ptr[1]);
}

int main()
{
	int arr[3][3] = {{0,1,2},{3,4,5},{6,7,8}};
	int barr[2][2];
	multi_arr(arr);
	//multi_arr(barr);
	return 0;
}
