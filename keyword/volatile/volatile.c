#include <stdio.h>

/*
volatile提醒编译器它后面所定义的变量随时都有可能改变，因此编译后的程序每次需要存储或读取这个变量的时候，都会直接从变量地址中读取数据。如果没有volatile关键字，则编译器可能优化读取和存储，可能暂时使用寄存器中的值，如果这个变量由别的程序更新了的话，将出现不一致的现象。
*/

int main01()
{
	volatile int i = 100;
	i = i + 5;
	/* outside device change the value */
	i = i + 10;
	i = i + 30;
	//i = i + 45;

	printf("%d\n", i);

	return 0;
}

int main()
{
	register int i;
	i = 100;
	i = i + 50;
	i = i + 20;

	/*
	//assembly pseudocode:

	__asm
	{
		mov i, 100
		mov eax, i
		add eax, 50
		mov i, eax
		mov eax, i
		add eax, 20
		mov i, eax
	}

	__asm
	{
		mov eax, 100
		add eax, 50
		add eax, 20
	}

	*/

	printf("%d\n", i);
}
