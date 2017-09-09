#include <stdio.h>

#define __max(a, b) ({ \
	typeof(a) _a = a; \
	typeof(b) _b = b; \
	(void *)(&_a == &_b); \
	_a > _b ? _a : _b; })

void main()
{
	int a = 2, b = 3;
	printf("%d\n", __max(a, b));
}
