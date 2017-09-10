
/*
 * get and set buffer size
 */

#include<stdio.h>

#include<stdlib.h>
#include<unistd.h>
#include<sys/socket.h>

void error_handling(char *message);

int main(int argc, char *argv[])
{
	int tcp_sock;
	int snd_buf, rcv_buf;
	socklen_t opt_len;
	int state;

	tcp_sock = socket(PF_INET, SOCK_STREAM, 0);

	printf("buffer size before modify ：\n");

	opt_len = sizeof(snd_buf);
	state = getsockopt(tcp_sock, SOL_SOCKET, SO_SNDBUF, (void *)&snd_buf, &opt_len);
	if (state) 
		error_handling("send buffer size, getsockopt() error!");
	printf("Input buffer size : %d\n", snd_buf);

	opt_len = sizeof(rcv_buf);
	state = getsockopt(tcp_sock, SOL_SOCKET, SO_RCVBUF, (void *)&rcv_buf, &opt_len);
	if (state)
		error_handling("receive buffer size, getsockopt() error!");
	printf("Output buffer size : %d\n", rcv_buf);
	/* set buffer size */
	snd_buf = 1024 * 4;
	rcv_buf = 1024 * 2;
	printf("set buffer size : send buffer(%d) recv buffer(%d)\n", snd_buf, rcv_buf);

	state = setsockopt(tcp_sock, SOL_SOCKET, SO_SNDBUF, (void *)&snd_buf, sizeof(snd_buf));
	if (state)
		error_handling("send buffer size, setsockopt() error!");

	state = setsockopt(tcp_sock, SOL_SOCKET, SO_RCVBUF, (void *)&rcv_buf, sizeof(rcv_buf));

	if (state)
		error_handling("receive buffer size, setsockopt() error!");
	printf("buffer size after modify :\n");
	opt_len = sizeof(snd_buf);
	state = getsockopt(tcp_sock, SOL_SOCKET, SO_SNDBUF, (void *)&snd_buf, &opt_len);
	if (state)
		error_handling("send buffer size, getsockopt() error!");
	printf("Input buffer size : %d\n", snd_buf);

	opt_len = sizeof(rcv_buf);
	state = getsockopt(tcp_sock, SOL_SOCKET, SO_RCVBUF, (void *)&rcv_buf, &opt_len);
	if (state)
		error_handling("receive buffer size, getsockopt() error!");
	printf("Output buffer size : %d\n", rcv_buf);

	return 0;
}

void error_handling(char *message)
{
	fputs(message, stderr);
	fputc('\n', stderr);
	exit(1);
}

