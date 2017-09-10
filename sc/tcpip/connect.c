
#include <unistd.h>
#include <sys/socket.h>

#define SLEEP_SEC 60
#define MAX_TIMES 10

/* like connect, check connect return error */
int connect_poll(int sockfd, const struct sockaddr *addr, socklen_t len)
{
	int count;
	for (count = 0; count <= MAX_TIMES; count++) {
		if (connect(sockfd, addr, len) == 0)
			return 0;
		sleep(SLEEP_SEC);
	}
	return -1;
}

