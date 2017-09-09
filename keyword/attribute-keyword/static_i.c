#include <stdio.h>

extern int test2_func();

void f1()
{
	int i = 0;
	i++;
	printf("%d\n", i);
}

void f2()
{
	static int i = 0;
	i++;
	printf("%d\n", i);
}

int main()
{
	printf("%d\n", test2_func());
}
