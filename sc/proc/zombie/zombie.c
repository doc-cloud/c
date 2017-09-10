#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

#define BUF_SIZE 30

void error_handling(char *message);

int main(int argc, char *argv[])
{
	pid_t pid;
	pid = fork();

	if (pid < 0) {
		error_handling("Error fork()!");
		exit(EXIT_FAILURE);
	} else if (pid == 0)
		printf("Hello, I am a child process.\n");
	else {
		printf("I am the parent process.\n");
		sleep(10);
	}

	if (pid == 0)
		printf("Child Process: End.\n");
	else
		printf("Parent process: End.\n");

	return 0;
}

void error_handling(char *message)
{
	fputs(message, stderr);
	fputc('\n', stderr);
	exit(1);
}
