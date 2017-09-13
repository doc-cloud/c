
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void bye(void)
{
	printf("test line\n");
}

int main(void)
{
	long a;
	int i;

	a = sysconf(_SC_ATEXIT_MAX);
	printf("ATEXIT_MAX = %ld\n", a);

	i = atexit(bye);
	if (0 != i) {
		fprintf(stderr, "cannot set exit function\n");
		exit(EXIT_FAILURE);
	}

	exit(EXIT_SUCCESS);
}

