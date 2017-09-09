/*
 * function pointer, point to a function,
 * funtion name is the entry point of execuate function body
 * function type define function pointer, FuncType *ptr;
 * direct definition: type (*ptr)(parameter list);
 */

#include <stdio.h>

typedef int (FUNC)(int);

int test(int i)
{
	return i * i;
}

void f()
{
	printf("Call f()...\n");
}

int main()
{
	FUNC* pt = test;

	void (*pf)() = &f;

	pf();
	(*pf)();

	printf("Function pointer call: %d\n", pt(2));
}
