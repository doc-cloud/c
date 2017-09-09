//#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#define STR "hello"
#define ABC 100

#pragma warning(disable:4996)

int main01()
{
	//char c = 't';
	//printf("%s, %d, %c\n", STR, ABC, c);

	//printf("%%");

	//long l = 100;
	//printf("%07ld", l);
	putchar('h');
	putchar('e');
	putchar('l');
	return 0;
}

int main02()
{
	int a = 0;
	int b = 0;

	scanf("%d", &a);
	scanf("%d", &b);


	printf("a + b = %d\n", a + b);
	return 0;
}

int main()
{
	char a = 0;
	a = getchar();

	getchar();

	char b;
	b = a;
	b = getchar();

	printf("a + b = %d", (a - '0') + (b - '0'));
	return 0;
}
