
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
#include <errno.h>

int main(void)
{
	struct sigaction act;
	pid_t pid;

	/*
	 * sa_handler : use default handler
	 * sa_sigaction : do not use backup sigaction
	 */
	act.sa_handler = SIG_DFL;
	act.sa_flags = SA_NOCLDWAIT;
	act.sa_sigaction = NULL;
	sigemptyset(&act.sa_mask);
	/* load signal handler, real goal: set signal option */
	if (sigaction(SIGCHLD, &act, NULL) == -1) {
		perror("fail to set handler for SIGCHILD");
		exit(1);
	}

	pid = fork();
	if (pid < 0) {
		perror("fail to fork");
		exit(1);
	} else if (pid == 0) {
		printf("the 1st child\n");
		exit(0);
	} else {
		pid = fork();
		if (pid < 0) {
			perror("fail to fork");
			exit(1);
		} else if (pid == 0) {
			printf("the 2nd child\n");
			sleep(5);
			exit(0);
		} else {
			/* wait, it must error and exit */
			if (wait(NULL) == -1)
				if (errno == ECHILD)
					printf("all child quit, no child is zome\n");

			printf("the parent\n");
		}
	}
	return 0;
}

