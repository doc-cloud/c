#include <stdio.h>
#include <string.h>

void test(int *p)
{
	*p = 100;
}

void test1(const int *p)
{
	printf("sizeof(p) = %d\n", sizeof(p));
	int i;
	//p[5] = 60;
	for (i = 0; i < 10; i++) {
		printf("%d\n", p[i]);
	}
}

void test2(int (*p)[3])
{

}

//#define a 70

int main01(void)
{
	//const int a = 70;
	//a = 100;
//    test(&70);
//    printf("a = %d\n", a);
//    return 0;

	int i = 0;
	test(&i);
	printf("i = %d\n", i);
	printf("------------------------\n");

	int array[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	printf("sizeof(array) = %d\n", sizeof(array));
	test1(array);

	int array2[5][3] = { 0 };
	test2(array2);

	void (*p2) (int *);
	p2 = test;
	int a = 10;
	p2(&a);

	return 0;
}

int main()
{
	int array1[5] = { 1, 2, 3, 4, 5 };
	int array2[5] = { 0 };
	memcpy(array2, array1, sizeof(array1));
	memset(array1, 0, sizeof(array1));
}
