
#include <stdio.h>

int main()
{
	char buf[BUFSIZ];

	setbuf(stdout, buf);
	puts("Linkerist Heracles");

	sleep(5);
	fflush(stdout);
	return(0);
}

