#include <stdio.h>

void f(int a[10])
{
	int i = 0;

	for(i = 0; i < 10; i++) {
		/* oops */
		a[i] = i;
		printf("%d\n", a[i]);
	}
}

int main()
{
	int a[5];
	f(a);
	return 0;
}
