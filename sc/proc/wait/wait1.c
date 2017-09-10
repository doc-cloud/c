
/*
 * avoid zombie by wait
 */

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/wait.h>

#define BUF_SIZE 30

void error_handling(char *message);

int main(int argc, char *argv[])
{
	pid_t pid;
	int status;

	pid = fork();

	if (pid < 0) {
		error_handling("Error fork()!");
		exit(EXIT_FAILURE);
	} else if (0 == pid)
		printf("Hello, I am a child process.\n");
	else {
		printf("I am the parent process.\n");
		/* cannot avoid zombie */
		//sleep(10);
		wait(&status);
		if (WIFEXITED(status))
			printf("Return value of child: %d\n", WEXITSTATUS(status));
		sleep(10);
	}

	if (pid == 0) {
		printf("Child Process: End.\n");
		return 123;
	} else
		printf("Parent process: End.\n");

	return 0;
}

void error_handling(char *message)
{
	fputs(message, stderr);
	fputc('\n', stderr);
	exit(1);
}

