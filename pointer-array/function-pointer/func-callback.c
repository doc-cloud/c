/*
 * a calling machanism,
 * caller has no idea about what is the specific function in a time point,
 * procedure be called has no idea what time to execuate as well, it know the procedure only,
 * when a specific event happened, caller call the specific function by function pointer
 */

#include <stdio.h>

typedef int(*FUNCTION)(int);

int g(int n, FUNCTION f)
{
	int i = 0;
	int ret = 0;

	for(i = 1; i <= n; i++)
		ret += i * f(i);

	return ret;
}

int f1(int x)
{
	return x + 1;
}

int f2(int x)
{
	return 2 * x - 1;
}

int f3(int x)
{
	return -x;
}

int main()
{
	printf("x * f1(x): %d\n", g(3, f1));
	printf("x * f2(x): %d\n", g(3, f2));
	printf("x * f3(x): %d\n", g(3, f3));
}
