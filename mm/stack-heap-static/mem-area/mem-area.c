#include <stdio.h>
#include <stdlib.h>

#include "a.h"

/* global */
int c = 0;
/* global in this file, cannot be use from external */
static int d = 0;

void test()
{
	/* all local variable is default set to auto */
	auto int b = 0;
}

void test1()
{
	/* effective while the process running period, it is in static area, and it can only access in test1 */
	static int f = 0;//整个进程运行期间一直有效，是在静态区，但只能是test1函数内部访问
	f++;
	printf("f = %d\n", f);
}

/* call convention, from right to left */
void test2(int n1, int n2)
{
	printf("n1 = %d, n2 = %d\n", &n1, &n2);
}

void recure(int n)
{
	//if (n > 0)
	{
		printf("n = %d\n", &n);
		recure(n - 1);
		printf("n = %d\n", &n);
	}
}

/* wrong mode */
void getheap(int *p)
{
	p = malloc(100);
}

/* right model */
void getheap1(int **p)
{

	*p = malloc(100);
}

/* right model */
int *getheap2()
{
	return malloc(100);
}

/* wrong model */
char *getstring()
{
	auto char array[10] = "hello";
	return array;
}

char getstring1()
{
	char c = 'a';
	return c;
}

/* right model */
const char *getstring2()
{
	/* return a constant variable address */
	return "hello";
}

char *getstring3()
{
	static char array[10] = "hello";
	return array;
}

int main()
{
	const char *ss = getstring2();
	printf("ss = %s\n", ss);
	return 0;

	char c = getstring1();
	printf("c = %c\n", c);
	return 0;

	char *s = getstring3();
	//
	printf("s = %s\n", s);
	return 0;


	int *p = NULL;
	//getheap1(&p);
	/* allocate heap space for a real parameter, it must be secondary pointer form */
	
	p = getheap2();

	free(p);
	return 0;


	recure(500);
	return 0;
	int n3 = 0;
	int n4 = 0;
	printf("n3 = %d, n4 = %d\n", &n3, &n4);
	test2(n3, n4);

	printf("max = %d\n", max1(5, 6));
	printf("mymax = %d\n", mymax);
	return 0;

	test1();
	test1();
	test1();
	int i = 0;
	{
		int a = 0;
	}
	return 0;
}
