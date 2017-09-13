
#include <stdio.h>
#include <string.h>

int main ()
{
	const char str[] = "http://www.yiibai.com/html";
	const char ch = '.';
	char *ret;

	ret = strrchr(str, ch);

	printf("String after |%c| is - |%s|\n", ch, ret);

	return(0);
}

