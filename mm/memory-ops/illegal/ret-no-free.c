#include <stdio.h>
#include <malloc.h>

void f(unsigned int size)
{
	int *p = (int *)malloc(size * sizeof(int));
	int i = 0;

	/* oops */
	if(0 != size % 2)
		return ;

	for(i = 0; i < size; i++) {
		p[i] = i;
		printf("%d\n", p[i]);
	}

	free(p);
}

int main()
{
	f(9);
	f(10);

	return 0;
}
