
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>

int first_avail_fd()
{
	int fd;
	fd = open("test.txt", O_RDONLY);
	printf("fd = %d\n", fd);
	close(fd);
	return fd;
}

int main()
{
	first_avail_fd();
	return 0;
}

