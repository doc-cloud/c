#include <stdio.h>

void func0(void)
{
	printf("func0\n");
}

void func1(void)
{
	printf("func1\n");
}

void func2(void)
{
	printf("func2\n");
}

void main()
{
	void (*func[3])(void) = {
		func0, func1, func2
	};
	int i;
	for (i = 0; i < 3; i++)
		func[i]();
}
