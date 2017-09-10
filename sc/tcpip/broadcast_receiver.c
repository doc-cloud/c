
/* some problem in it, the last datagram show twice, and program cannot exit */

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<arpa/inet.h>
#include<sys/socket.h>

#define BUFF_SIZE 128

void error_handling(char *message);
void debug_print(int no);

int main(int argc, char *argv[])
{
	int sock_recv;
	struct sockaddr_in addr_recv;

	char buff[BUFF_SIZE];
	int str_len;

	if (2 != argc) {
		printf("Usage : %s <Port> \n", argv[0]);
		exit(1);
	}

	sock_recv = socket(PF_INET, SOCK_DGRAM, 0);
	if (-1 == sock_recv) {
		error_handling("socket() error!");
	}

	memset(&addr_recv, 0, sizeof(addr_recv));
	addr_recv.sin_family = AF_INET;
	addr_recv.sin_addr.s_addr = htonl(INADDR_ANY);
	addr_recv.sin_port = htons(atoi(argv[1]));

	if (-1 ==
	    bind(sock_recv, (struct sockaddr *)&addr_recv, sizeof(addr_recv)))
		error_handling("Error bind()");

	/* receive and display the multicast message */
	while (1) {
		str_len = recvfrom(sock_recv, buff, BUFF_SIZE - 1, 0, NULL, 0);
		if (str_len < 0)
			break;
		buff[str_len] = 0;
		fputs(buff, stdout);
	}
	/* the same problem */

	puts("File Received from server is over!\n");
	close(sock_recv);

	return 0;
}

void error_handling(char *message)
{
	fputs(message, stderr);
	fputc('\n', stderr);
	exit(1);
}

void debug_print(int no)
{
	printf("Debug: %d\n", no);
}

