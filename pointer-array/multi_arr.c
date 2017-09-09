#include <stdio.h>

void multi_arr(int (*ptr)[3],int row)
{
	int j,i;
	int col = sizeof(*ptr) / sizeof(int);
	printf("%d\n",sizeof(ptr));
	printf("%d\n",*ptr[1]);
	for(i = 0;i < row;i++) {
		for(j = 0; j < col; j++)
			printf("%d\n",ptr[i][j]);
	}
}

int main()
{
	int arr[3][3] = {
		{0,1,2},
		{3,4,5},
		{6,7,8}
	};
	int barr[2][2];
	multi_arr(arr,3);
	//multi_arr(barr);
	return 0;
}
