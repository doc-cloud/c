
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>

int main(void)
{
	int fd;
	fd = creat("test.txt", 0700);
	if(-1 == fd){
		perror("fail to creat");
		exit(1);
	} else
		printf("creat OK\n");
	return 0;
}

