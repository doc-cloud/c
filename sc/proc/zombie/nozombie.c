
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main(void)
{
	pid_t pid;
	pid = fork();
	if (pid < 0) {
		printf("fail to fork\n");
		exit(1);
	} else if(0 == pid) {
		printf("the child\n");
		pid = fork();
		if (pid < 0) {
			printf("fail to fork\n");
			exit(1);
		/* grand child process do the real work, init is the reaper */
		} else if(0 == pid) {
			printf("do something you want\n");
			sleep(5);
			printf("done\n");
			exit(0);
		} else
			exit(0);
	} else {
		if(waitpid(pid,NULL,0) > 0)
			printf("child %d exited\n",pid);
		sleep(10);
		printf("the parent\n");
	}
	return 0;
}

