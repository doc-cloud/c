
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int fd[2];
	char str[256];
	if ((pipe(fd)) < 0) {
		perror("pipe");
		exit(1);
	}
	write(fd[1], "create the pipe successfully !\n", 1024);
	read(fd[0], str, sizeof(str));
	printf("%s", str);
	printf("pipe file descriptors are %d,%d \n", fd[0], fd[1]);
	close(fd[0]);
	close(fd[1]);
	return 0;
}

