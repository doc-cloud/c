#include <stdlib.h>
#include <stdio.h>

void *mymemset(void *s, int c, int n)
{
	void *ret = s;
	int i = 0;
	for (i = 0; i < n; i++) {
		*((char *)ret + i) = c;
	}
	return realloc(ret, n);
}

int main()
{
	char *p = (char *)malloc(5);
	*(p + 5) = 'c';
	printf("%c\n", *(p + 5));
	mymemset(p, 'a', 10);
	printf("%c\n", *(p + 7));
}
