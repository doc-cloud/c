#include <unistd.h>
#include <stdio.h>

int first_avail_fd()
{
	int fd;
	/* dupicate any opened file, almost all process opened in stdin  */
	fd = dup(0);
	printf("fd = %d\n", fd);
	close(fd);
	/* fd return the first available fd, but it be occupied by test file, close test file make it available */
	return fd;
}

int main()
{
	first_avail_fd();
	return 0;
}
