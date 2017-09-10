#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

int main(void)
{
	int fd;
	char *p = "linux ok\n";
	fd = open("test.txt", O_WRONLY | O_TRUNC);
	if (fd == -1) {
		perror("fail to open");
		exit(1);
	}
	if (write(fd, p, strlen(p)) == -1) {
		perror("fail to write");
		exit(1);
	}
	close(fd);
	return 0;
}

