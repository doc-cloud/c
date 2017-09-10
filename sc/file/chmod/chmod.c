
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>

#define NEW_MOD S_IRUSR | S_IRGRP | S_IROTH

int main(void)
{
	int fd;
	struct stat statbuf;
	mode_t mode;

	/* change file prot by absolute permission word */
	if (chmod("test.txt", NEW_MOD) == -1) {
		perror("fail to change model");
		exit(1);
	}
	if (stat("test2.txt", &statbuf) == -1) {
		perror("fail to stat");
		exit(1);
	}
	/* change file prot by relative permission word */
	mode = statbuf.st_mode;
	/* mask all prot of file */
	mode &= (~S_IRWXU & ~S_IRWXG & ~S_IRWXO);
	/* open read prot of all user */
	mode |= (NEW_MOD);
	if (chmod("test2.txt", mode) == -1) {
		perror("fail to change model");
		exit(1);
	}
	return 0;
}

