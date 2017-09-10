
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/stat.h>

/* mask owner, grp, and other user's read prot */
#define MASK S_IRUSR | S_IRGRP | S_IROTH

int main(void)
{
	int fd;
	mode_t mask;
	mask = umask(MASK);
	printf("the original mask is %x\n", (unsigned int)mask);
	if ((fd = open("test.txt", O_CREAT, 0777)) == -1) {
		perror("fail to create");
		exit(1);
	}
	close(fd);
	/* change the shell environment ? */
	return 0;
}

