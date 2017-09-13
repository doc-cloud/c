
#include <stdio.h>

int main(void)
{
	/* this buffer is large enough, if user input in command way */
	char buf[2048];
	/* read a line from screen */
	while(gets(buf) != NULL) {
		printf("%s\n", buf);
	}
	return 0;
}

