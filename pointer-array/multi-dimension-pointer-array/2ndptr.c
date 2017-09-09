#include <stdlib.h>

int **malloc2a(int row,int col)
{
	int i;
	int **ret = (int **)malloc(sizeof(int *) * row);
	int *p = (int *)malloc(sizeof(int) * row * col);

	if(ret && p)
		for(i = 0;i < row;i++)
			*(ret + i) = (p + i * col);
	else {
		free(ret);
		free(p);

		ret = NULL;
	}

	return ret;
}

void free2a(int **arr)
{
	free(arr[0]);
	free(arr);
}

int main()
{
	int **ret = malloc2a(3,4);
	free2a(ret);
	return 0;
}
