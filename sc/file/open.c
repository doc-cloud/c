#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>

int main(void)
{
	int fd;

	fd = open("test.txt", O_RDWR | O_CREAT, 0700);
	if (fd == -1) {
		perror("fail to open");
		exit(1);
	} else
		printf("open OK\n");

	close(fd);
	return 0;
}
