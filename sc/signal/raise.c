
#include <stdio.h>
#include <signal.h>

int main(void)
{
	printf("kill myself\n");
	raise(SIGKILL);
	printf("should not be here, never\n");
	return 0;
}

