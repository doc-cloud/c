
#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>

#define BUF_SIZE 30

int main(int argc, char *argv[])
{
	int fds[2];
	pid_t pid;
	char str[] = "Who are you?";
	char buf[BUF_SIZE];

	int state;
	state = pipe(fds);
	if (state != 0) {
		fputs("Error pipe()\n", stderr);
		exit(EXIT_FAILURE);
	}

	pid = fork();
	/* dupicate I/O fd, parent and child has it at same time */
	if (pid < 0) {
		fputs("Error fork()\n", stderr);
		exit(1);
	} else if (pid == 0)
		//only dfs[1] be used as input of the pipe
		write(fds[1], str, sizeof(str));
	else {
		//only dfs[0] as output
		str_len = read(fds[0], buf, BUF_SIZE);
		puts(buf);
	}
	return 0;
}

