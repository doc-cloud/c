
/* my owner file I/O function library */
#include <errno.h>
#include <fcntl.h>
#include <unistd.h>

/* encapsulate read, add error handle, skeleton is same as read */
ssize_t my_read(int fd, void *buffer, size_t length)
{
	ssize_t done = length;
	/* interrupted by signal, read again */
	while (done > 0) {
		done = read(fd, buffer, length);
		/* handle exception */
		if (done == -1)
			/* interrupted by signal, abandon read content, read again */
			if (errno == EINTR)
				done = length;
		else {
			/* other error, output error reason, and return */
			perror("fail to read");
			return -1;
		} else
			break;
	}
	/* return the bytes number really read */
	return done;
}

/* encapsulate write, add error handle, skeleton is same as write */
ssize_t my_write(int fd, void *buffer, size_t length)
{
	ssize_t done = length;
	/* interrupted by signal, write again */
	while (done > 0) {
		done = write(fd, buffer, length);
		/* handle exception */
		if (done != length)
			/* interrupted by signal, abandon read content, write again */
			if (errno == EINTR)
				done = length;
		else {
			/* other error, output error reason, and return */
			perror("fail to write");
			return -1;
		} else
			break;
	}
	/* return the bytes number really written */
	return done;
}

