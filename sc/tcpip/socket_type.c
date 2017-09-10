
/*
 * operate socket option by getsockopt, setsockopt
 */

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/socket.h>

void error_handling(char *message);

int main(int argc, char *argv[])
{
	int tcp_sock, udp_sock;
	int sock_type;
	socklen_t optlen;
	int state;

	optlen = sizeof(sock_type);

	tcp_sock = socket(PF_INET, SOCK_STREAM, 0);
	udp_sock = socket(PF_INET, SOCK_DGRAM, 0);

	printf("SOCK_STREAM : %d\n", SOCK_STREAM);
	state = getsockopt(tcp_sock, SOL_SOCKET, SO_TYPE, (void *)&sock_type, &optlen);
	if (state)
		error_handling("tcp_sock, getsockopt() error!");
	printf("The type of tcp socket : %d\n", sock_type);

	printf("SOCK_DGRAM: %d\n", SOCK_DGRAM);

	state = getsockopt(udp_sock, SOL_SOCKET, SO_TYPE, (void *)&sock_type, &optlen);
	if(state)
		error_handling("udp_sock, getsockopt() error!");
	printf("The type of udp socket : %d\n", sock_type);

	return 0;
}

void error_handling(char *message)
{
	fputs(message, stderr);
	fputc('\n', stderr);
	exit(1);
}

