#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#pragma warning(disable:4996)

struct A
{
	int a;
	int b;
};

struct B
{
	int c;
	struct A a;
	int b;
};

struct C
{
	struct B b;
	char d;
};


struct str
{
	char s[100];
};
int main()
{
	printf("%d\n", sizeof(struct C));
	struct str s1, s2;
	strcpy(s1.s, "hello");
	//s2 = s1;//结构体赋值，其实就是结构体之间内存的拷贝

	memcpy(&s2, &s1, sizeof(s1));
	printf("s2.s = %s\n", s2.s);

	struct A a;
	struct A *p = &a;
	//(*p).a = 10;
	//(*p).b = 20;
	p->a = 10;
	p->b = 20;


	//struct A array[10] = { 0 };
	//p = array;
	p = malloc(sizeof(struct A) * 10);
	memset(p, 0, sizeof(struct A) * 10);
	struct A *array = p;
	p->a = 1;
	p->b = 2;
	p++;
	p->a = 3;
	p->b = 4;

	int i;
	for (i = 0; i < 10; i++)
	{
		printf("a = %d, b = %d\n", array[i].a, array[i].b);
	}

	free(array);

	return 0;
}