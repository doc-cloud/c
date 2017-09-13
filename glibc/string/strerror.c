
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>

int main()
{
	int fd;
	errno = 0;

	fd = open("./test.txt", O_RDWR);
	/* there is no error */
	if(0 == errno)
		printf("Sucessful\n");
	else {
		int err = errno;
		printf("Fail : the reason is : %s\n",  strerror(err));
	}

	close(fd);
	return 0;
}

