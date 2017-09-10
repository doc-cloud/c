
#include <stdio.h>
#include <unistd.h>

int f1()
{
	vfork();
	return 0;	
}

/* cover the stack frame of f1 */
int f2(int a, int b)
{
	return a + b;
}

int main()
{
	int c;
	/* function which calls vfork */
	f1();
	/* child run here, can father? */
	c = f2(1,2);
	printf("%d\n", c);
	return 0;	
}

