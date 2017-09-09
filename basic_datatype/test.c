#include <stdio.h>

int main()
{
	int a = 10;//4个字节大小
	short b = 10;
	printf("%d\n", sizeof(b));
	long c = 10;
	printf("%d\n", sizeof(c));
	long long d = 10;
	printf("%d\n", sizeof(d));
	unsigned int e = 10;
	printf("%d\n", sizeof(e));

	//unsigned short f;
	//unsigned long g;
	//unsigned long long i;

	//int i1;

	unsigned short abc = 0xffff;
	abc = abc + 1 + 99;
	printf("%d\n", abc);

	abc = 2;
	abc = abc - 5;
	printf("%d\n", abc);

	int i1 = 0x12345678;
	abc = i1;
	printf("%x\n", abc);

	short abc1 = -2;
	i1 = abc1;
	printf("%x\n", i1);

	unsigned short abc2 = 0;
	abc2 = abc2 - 1;
	printf("%d\n", abc2);

	int a1 = 0x12345678;
	printf("%p\n", &a1);
}
