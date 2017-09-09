// global.c
// int g_var = 0;

#include <stdio.h>

extern int g_var;

void f(int i, int j);

int main()
{
	//extern int g_var;
	int g(int x);

	g_var = 10;

	f(1, 2);

	printf("%d\n", g(3));

	return 0;
}

void f(int i, int j)
{
	//extern int g_var;
	//g(i);
	printf("i + j = %d\n", i + j);
}

int g(int x)
{
	return 2 * x + g_var;
}
