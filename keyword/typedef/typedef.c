#include <stdio.h>

typedef int INT32;

int main()
{
	int i = 0;
	int *p = &i;
	INT32 *p32 = &i;
	int *ptr = p32;
	return 0;
}
