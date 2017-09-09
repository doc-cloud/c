#include <stdio.h>

int main01()
{
	int a = 10;
	int b = 3;
	int c = a % b;
	printf("c = %d\n", c);

	//a = a + 5;
	a += 5;

	a = a + 1;
	a += 1;
	a++;
	a = a - 1;
	a -= 1;
	a--;
	return 0;
}

int main02()
{
	int i = 5;
	//i++;
	//++i;
	
	//int a = ++i;
	//int a = i++;
	int a = i++ + ++i;
	//i = i + 1;
	//int a = i + i;
	//i = i + 1;

	printf("%d\n", a);
	printf("%d\n", i);
	return 0;
}

int main03()
{
	int a = 2;
	int b = 3;
	int c = 4;
	int d = 5;
	int i = (a = b, a + d);

	printf("i = %d\n", i);

	a = 2; b = 3; c = 4; d = 5;
	i = (a + (b - c)) * d;
	printf("i = %d\n", i);

	a = 4;
	b = 3;
	c = 8;

	i = a = b = c;
	printf("i = %d\n", i);

	{
		i = 100;
		a = 30;
	}

	;//空语句

	printf("i = %d\n", i);


	for (; ; )//循环语句，代表复合语句内部的代码要执行3次
	{
		printf("hello\n");
	}

	return 0;
}

int main()
{
	//double f = 3 / 2;
	//double f = (double)3 / 2;
	//double f = 3.0 / 2;

	int a = 3;
	int b = 2;
	double f = (double)a / b;
	printf("%f\n", f);
	return 0;
}
