#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <fcntl.h>
#include <unistd.h>

#define MAX 1024

int main(void)
{
	int fd;
	off_t off;
	char buf[MAX];
	fd = open("test.txt", O_RDWR);
	if (fd == -1) {
		perror("fail to open");
		exit(1);
	}

	printf("before reading\n");
	off = lseek(fd, 0, SEEK_CUR);
	if (off == -1) {
		perror("fail to lseek");
		exit(1);
	}

	printf("the offset is : %d\n", (int)off);
	if (read(fd, buf, 5) == -1) {
		perror("fail ot read");
		exit(1);
	}

	printf("after reading\n");
	off = lseek(fd, 0, SEEK_CUR);
	if (off == -1) {
		perror("fail to lseek");
		exit(errno);
	}
	printf("the offset is : %d\n", (int)off);

	close(fd);
	return 0;
}
