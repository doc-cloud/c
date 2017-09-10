
#include <stdio.h>
#include <signal.h>

int main(void)
{
	sigset_t sig_set;
	sigemptyset(&sig_set);
	/* set SIGKILL bit, note : use signal encode minus 1 */
	sigaddset(&sig_set, SIGKILL);

	/* this bit is be set ? */
	if((sigismember(&sig_set, SIGKILL)) == 1)
		printf("SIGKILL has been set\n");
	else
		printf("can’t set signal set\n");
	return 0;
}

