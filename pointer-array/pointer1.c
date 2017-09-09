#include <stdio.h>

int main01(void)
{
	int array[100] = { 1, 2, 3, 4, 5 };
	/* dereference, and the bare name, the effect is same */
	int *p = array;
//    int *p;
//    p = array;
	*p = 100;
	//p = 100;

	printf("%u\n", p);
	p++;
	printf("%u\n", p);
	int i = 300;
	p = &i;
	*p = 200;
	printf("i = %d\n", i);

	return 0;
}

int main02()
{
	int *p;
	printf("p = %d\n", p);
	/* wild pointer assignment */
	*p = 100;
	return 0;
}

int main03()
{
	int i = 0x12345678;
	unsigned char *p = &i;
	printf("%x, %x, %x, %x\n", p[0], p[1], p[2], p[3]);

	const int *p1 = &i;
	//*p1 = 100;
	printf("i = %x\n", *p1);

	int *const p2 = &i;
	*p2 = 100;

	int i1 = 0;
	/* p2 point to the variable address when initialize, it cannot be modified */
	//p2 = &i1;

	p1 = &i1;
	//*p1 = 300;
	printf("i = %d\n", i);
	return 0;
}

int main04()
{
	int array[100] = { 0 };
	int *p = array;
	p += 5;

	p -= 2;

	p[3] = 20;

	int i;
	for (i = 0; i < 10; i++)
		printf("array[%d] = %d\n", i, array[i]);

	printf("----------------------\n");
	int *p1 = &array[2];
	int *p2 = &array[5];

	p1 += 2;
	p2 -= 1;
	if (p1 == p2) {
		printf("p1 == p2\n");
	} else
		printf("p1 <> p2\n");

	printf("%d\n", p2 - p1);
	return 0;
}

int main()
{
	int *s[10] = { 0 };
	int (*p)[10] = 0;

//    sizeof(s) = 40
//    sizeof(p) = 4

	int array[3][4] = { 0 };
	//int *p1 = array;
	int (*p1)[4] = array;
	/* move 16 bytes */
	//p1++;
	//for array[0]
	//sizeof(array[2]) = 16 bytes
	//p1[0] == array 's first address
	//p1[1] == array[1]
	//p1[2] == array[2]
	p1[2][3] = 40;

	return 0;
}
