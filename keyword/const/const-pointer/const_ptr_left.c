#include <stdio.h>

int main()
{
	int a = 1;
	int b = 2;

	const int *const_int_ptr = &a;
	int const *int_const_ptr = &a;

	const_int_ptr = &b;
	int_const_ptr = &b;

	printf("%d\n",*const_int_ptr);
	printf("%d\n",*int_const_ptr);

	return 0;
}
