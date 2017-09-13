
#include <stdio.h>

/* a living example, one sentence, store in text section after compile */
int f(int a, int b)
{
	return a + b;
}

int main()
{
	/* function pointer, locate to code section */
	int (*p)(int, int);

	/* pointer for any type, avoid compiler warning */
	void *q;
	p = f;
	/* get the content of text section */
	q = (void *)p;
	/* convert to integer type, mean that look forward 4 bytes from address q */
	printf("the code is : 0x%x\n", *((int *)q));

	/* illegal write operation, segment fault */
	/* change pre-four bytes content */
	//*((int *)q) = 0x12345678;
	return 0;
}

