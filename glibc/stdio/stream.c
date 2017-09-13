
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>

int main(void)
{
	FILE *fp;
	int fd;
	 /* open stream by read/write way */
	if((fp = fopen("test.txt", "w+")) == NULL) {
		perror("fail to open");
		exit(1);
	}
	/* load some info into this stream */
	fprintf(fp, "hello world\n");
	fclose(fp);
	/* open file by read/write way */
	if((fd = open("test.txt", O_RDWR)) == -1) {
		perror("fail to open");
		exit(1);
	}
	/* open stream in an opened file */
	if((fp = fdopen(fd, "a")) == NULL) {
		perror("fail to open stream");
		exit(1);
	}
	fprintf(fp,"hello world again\n");
	/* close stream, file is closed as well */
	fclose(fp);
	return 0;
}

