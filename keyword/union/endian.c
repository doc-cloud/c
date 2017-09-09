#include <stdio.h>

/*
大端模式：字数据的高字节存储在低地址中，而字数据的低字节则存储在高地址中
小端模式：字数据的高字节存储在高地址中，而字数据的低字节则存储在低地址中
union型数据所占空间等于其最大的成员所占的空间，对于union型的成员的存取都是相对于该联合体基地址的偏移量为0处开始，也就是联合体的访问不论对那个变量的存取，都是从union的首地址位置开始
*/

int check_endian()
{
	int a = 1;
	char *b = (char *)&a;
	return 1 == *b;
}

union C {
 int i;
 char c;
};

void main()
{
 union C c;
 c.i = 1;
	printf("%d\n",check_endian());
 printf("%d\n", c.c == 1);
}
