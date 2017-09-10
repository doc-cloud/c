/*
 * select, standard I/O monitor, echo the input content
 */

#include<stdio.h>
#include<unistd.h>
#include<sys/time.h>
#include<sys/select.h>

#define BUFF_SIZE 30

int main(int argc, char *argv[])
{
	fd_set reads, reads_init;
	struct timeval timeout, timeout_init;
	char buff[BUFF_SIZE];
	int result, str_len;

	/* register fd_set var */
	FD_ZERO(&reads_init);
	/* 0 -- stdin(console) */
	FD_SET(0, &reads_init);

	timeout_init.tv_sec = 5;
	timeout_init.tv_usec = 0;

	while (1) {
		/* after select, all bits set to zero except changed fd, store the original value */
		reads = reads_init;
		/* timeval member value set to remain time before time over, reinitialize it before use it */
		timeout = timeout_init;
		result = select(1, &reads, NULL, NULL, &timeout);
		if (result < 0) {
			fputs("Error select()!", stderr);
			break;
		} else if (result == 0)
			puts("Time-out!");
		else {
			if (FD_ISSET(0, &reads)) {
				str_len = read(0, buff, BUFF_SIZE);
				buff[str_len] = 0;
				printf("Message from console: %s", buff);
			}
		}

	}
	return 0;
}
