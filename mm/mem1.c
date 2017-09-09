#include <stdio.h>

static int a = 20;

void test1()
{
	int a1 = 0;
	int a = 100;
}

void test2()
{
	auto int a2 = 0;
	a = 15;
}

/* there is a variable, defined in other files, use it directly */
extern int age;
/* declaration or definition */
//int age;

void set_age(int n)
{
	age = n;
}

void get_age()
{
	printf("age = %d\n", age);
}

int main01(void)
{
	//int a = 0;
	/* the scope is in test1, cannot be used from external */
	//a1 = 100;
	//a = 10;

	{
		//int a = 100;
		printf("a = %d\n", a);
	}
	return 0;
}

void mystatic()
{
	/* static variable, initialize once, it existing all the time while program running */
	static int a = 0;
	printf("a = %d\n", a);
	a++;

}

extern void test3();
void test3();

int main()
{
	test3();
	set_age(10);
	get_age();

	//register int i = 0;
	//int *p = &i;

	printf("-----------------------\n");
	int i;
	for (i = 0; i < 20; i++)
		mystatic();

	return 0;
}
