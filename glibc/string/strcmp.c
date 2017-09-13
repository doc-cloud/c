#include <string.h>
#include <stdio.h>

int main(int argc, char **argv)
{
	char *s1="Hello, Programmers!";
	char *s2="Hello, Programmers!";
	int ret;

	ret = strcmp(s1,s2);
	if(!ret)
		printf("s1 and s2 are identical");
	else if (ret < 0)
		printf("s1 less than s2");
	else
		printf("s1 greater than s2");

	return 0;
}
