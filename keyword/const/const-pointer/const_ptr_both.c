#include <stdio.h>

int main()
{
	int a = 1;
	int b = 2;

	const int * const const_int_ptr_const = &a;

	const_int_ptr_const = &b;
	//const_int_ptr_const = 3;

	printf("%d\n",*const_int_ptr_const);

	return 0;
}
