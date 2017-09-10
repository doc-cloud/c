
/*
 * convert fd into FILE *
 */

#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>

int main(int argc, char *argv[])
{
	int fd;
	FILE *fp;

	if (2 != argc) {
		printf("Usage: %s <filename>\n", argv[0]);
		exit(1);
	}

	fd = open(argv[1], O_CREAT | O_RDWR | O_TRUNC);
	if (-1 == fd) {
		fputs("Error open()", stderr);
		exit(EXIT_FAILURE);
	}

	fp = fdopen(fd, "w");
	fputs("Linux TCP/IP network programming.\n", fp);
	/* get corresponding fd */
	printf("File descriptor is %d, from FILE : %d\n", fd, fileno(fp));

	close(fp);
	return 0;
}

