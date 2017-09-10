#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(void)
{
	pid_t pid;
	pid = fork();
	if (pid < 0) {
		printf("fail to fork\n");
		exit(1);
	} else if (0 == pid) {
		/*
		 * call exec, run hello in this directory,
		 * do not need command params, and inherit environment table of parent process
		 */
		if(execvp("hello", NULL) < 0) {
			printf("fail to exec\n");
			exit(0);
		}
		/* should never be exec, hello program instead of these */
		printf("the child is not hello\n");
		exit(0);
	}
	printf("the parent\n");
	return 0;
}
