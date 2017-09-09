#include <stdio.h>

int ptr0[] = {
	1, 2, 3, 4, 5
};

int ptr1[] = {
	6, 7, 8, 9, 10
};

int main()
{
	ptr0[5] = 10;
	printf("%d\n", **(&ptr0 + 1));

	return 0;
}
