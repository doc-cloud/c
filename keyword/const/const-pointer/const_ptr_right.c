#include <stdio.h>

int main()
{
	int a = 1;
	int b = 2;

	int * const int_ptr_const = &a;

	//int_ptr_const = &b;
	*int_ptr_const = 3;

	printf("%d\n",*int_ptr_const);

	return 0;
}
