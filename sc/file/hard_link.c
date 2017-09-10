
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>

#define MAX 1024

int main(void)
{
	int fd;
	struct stat statbuf;
	char buf[MAX];
	int n;
	if (stat("test.txt", &statbuf) == -1) {
		perror("fail to get status");
		exit(1);
	}
	printf("test.txt, the number of links is : %d\n", statbuf.st_nlink);
	/* create test2.txt, share the same inode with test.txt */
	if (link("test.txt", "test2.txt") == -1) {
		perror("fail to link");
		exit(1);
	}
	if (stat("test.txt", &statbuf) == -1) {
		perror("fail to get status");
		exit(1);
	}
	printf("test.txt, the number of links is : %d\n", statbuf.st_nlink);
	/* the state is test.txt's, in fact */
	if (stat("test2.txt", &statbuf) == -1) {
		perror("fail to get status");
		exit(1);
	}
	printf("test2.txt, the number of links is : %d\n", statbuf.st_nlink);
	printf("\n");
	if ((fd = open("test.txt", O_RDWR)) == -1) {
		perror("fail to open");
		exit(1);
	}
	strcpy(buf, "hello world");
	if ((n = write(fd, buf, strlen(buf))) == -1) {
		perror("fail to write");
		exit(1);
	}
	close(fd);
	if ((fd = open("test2.txt", O_RDWR)) == -1) {
		perror("fail to open");
		exit(1);
	}
	if ((n = read(fd, buf, n)) == -1) {
		perror("fail to read");
		exit(1);
	}
	buf[n] = '\0';
	printf("content of test2.txt is : %s\n", buf);
	close(fd);
	/*
	 * delete test2.txt 目录项, the disk file is not influenced,
	 * refer this by test.txt
	 */
	if (unlink("test2.txt") == -1) {
		perror("fail to unlink");
		exit(1);
	}
	/* get test.txt file stat */
	if (stat("test.txt", &statbuf) == -1) {
		perror("fail to get status");
		exit(1);
	}
	printf("test.txt, the number of links is : %d\n", statbuf.st_nlink);
	/* print this file refer count */
	/* open test.txt, avoid this file be deleted */
	if ((fd = open("test.txt", O_RDWR)) == -1) {
		perror("fail to open");
		exit(1);
	}
	/* the refer count of this file is zero */
	if (unlink("test.txt") == -1) {
		perror("fail to unlink");
		exit(1);
	}
	if (fstat(fd, &statbuf) == -1) {
		perror("fail to get status");
		exit(1);
	}
	printf("test.txt, the number of links is : %d\n", statbuf.st_nlink);
	printf("\n");
	/* due to file is remain opened, so this file can be use */
	if ((n = read(fd, buf, n)) == -1) {
		perror("fail to read");
		exit(1);
	}
	buf[n] = '\0';
	printf("content of test.txt is : %s\n", buf);
	close(fd);
	return 0;
}

