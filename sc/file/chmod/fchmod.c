
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>

#define READ_MASK S_IRUSR | S_IRGRP | S_IROTH
#define WRITE_MASK S_IWUSR | S_IWGRP | S_IWOTH

int main(void)
{
	int fd;
	struct stat statbuf;
	/* if not exist, use read operation mask as prot word */
	if ((fd = open("test.txt", O_RDONLY | O_CREAT, READ_MASK)) == -1) {
		perror("fail to open");
		exit(1);
	}
	printf("before changing model\n");
	if (fstat(fd, &statbuf) == -1) {
		perror("fail to get status");
		exit(1);
	}
	if (statbuf.st_mode & S_IRUSR)
		printf("user can read\n");
	if (statbuf.st_mode & S_IRGRP)
		printf("group user can read\n");
	if (statbuf.st_mode & S_IROTH)
		printf("other user can read\n");
	printf("\n");
	/*
	 * change file prot use by  write operation
	 * read prot is gone after change, write prot instead
	 */
	if (fchmod(fd, WRITE_MASK) == -1) {
		perror("fail to change model");
		exit(1);
	}
	printf("after changing model\n");
	if (fstat(fd, &statbuf) == -1) {
		perror("fail to get status");
		exit(1);
	}
	printf("check the file by file-descriptor\n");

	/* updated ? */
	if (statbuf.st_mode & S_IWUSR)
		printf("user can write\n");
	if (statbuf.st_mode & S_IWGRP)
		printf("group user can write\n");
	if (statbuf.st_mode & S_IWOTH)
		printf("other user can write\n");
	printf("\n");

	/* updated ? */
	if (stat("test.txt", &statbuf) == -1) {
		perror("fail to get status");
		exit(1);
	}
	printf("check the file in the disk\n");

	/* prot is update in disk */
	if (statbuf.st_mode & S_IWUSR)
		printf("user can write\n");
	if (statbuf.st_mode & S_IWGRP)
		printf("group user can write\n");
	if (statbuf.st_mode & S_IWOTH)
		printf("other user can write\n");
	printf("\n");

	sleep(10);
	printf("done\n");
	close(fd);
	return 0;
}

