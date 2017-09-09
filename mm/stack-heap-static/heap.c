#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void print_array(int *p, int n)
{
	int i;
	for (i = 0; i < n; i++)
		printf("p[%d] = %d\n", i, p[i]);
}

int *geta()
{
	int a = 0;
	return &a;
}

int *geta1()
{
	int *p = malloc(sizeof(int));
	return p;
}

int *geta2()
{
	static int a = 0;
	return &a;
}

int main01(void)
{
	int *getp = geta2();

	*getp = 100;
	//free(getp);

	int array[10] = { 0 };
	int *p = (int *)malloc(sizeof(int) * 10000000);

	memset(p, 0, sizeof(int) * 10);
	int i;
	for (i = 0; i < 10; i++) {
		p[i] = i;
	}
	print_array(p, 10);

	char *p1 = malloc(sizeof(char) * 10);

	free(p);

	free(p1);

	printf("Hello World!\n");
	return 0;
}

void getheap(int *p)
{

	printf("p = %p\n", &p);
	p = malloc(sizeof(int) * 10);
//    p[0] = 1;
//    p[1] = 2;

}

void getheap1(int **p)
{
	*p = malloc(sizeof(int) * 10);
}

void getheap3(int *p)
{
	p = malloc(sizeof(int) * 10);
}

int main02()
{
	int *pp = malloc(10);
	//int *pp = malloc(12);
	//4k, 3.9k  0.3  8k

	int i = 0;
	scanf("%d", &i);
	/* it cannot be variable when define an array */
	//int array[i];
	int *array = malloc(sizeof(int) * i);

	free(array);

	int *p = NULL;
	printf("p = %p\n", &p);
	getheap(p);
	//getheap1(&p);
	printf("p = %d\n", p);

	//p = malloc(sizeof(int) * 10);
	p[0] = 1;
	p[1] = 2;
	printf("p[0] = %d, p[1] = %d\n", p[0], p[1]);
	free(p);
	return 0;
}

int main()
{

	while (1) {
		//int *p = malloc(100);
		int *p = malloc(1000000);
		getchar();
	}
	return 0;
}
