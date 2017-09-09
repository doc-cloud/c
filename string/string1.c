#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void test(const char *s)
{
	//s[0] = 'a';
	printf("%s\n", s);
}

void test1(char *s)
{
	//memset(s, 0, strlen(s));
	s[0] = 'a';
	//s++;
	s[1] = 'b';
}

int main01(void)
{
	test("Hello World!\n");
	char s[] = "hello world";
	test1(s);
	printf("s = %s\n", s);

	return 0;
}

int main(int argc, char *argv[])
{
	int i;
	for (i = 0; i < argc; i++)
		printf("argv[%d] = %s\n", i, argv[i]);
	getchar();
	return 0;
}
