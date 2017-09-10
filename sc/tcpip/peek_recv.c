
/* recv, test for input buffer, MSG_PEEK, MSG_DONTWAIT */

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<arpa/inet.h>
#include<sys/socket.h>

void error_handling(char *message);

#define BUF_SIZE 32

int main(int argc, char *argv[])
{
	int server_sock;
	int client_sock;

	struct sockaddr_in server_addr;
	struct sockaddr_in client_addr;
	socklen_t client_addr_size;

	char message[BUF_SIZE];

	int str_len;

	if (argc != 2) {
		printf("Usage : %s <port>\n", argv[0]);
		exit(1);
	}

	server_sock = socket(PF_INET, SOCK_STREAM, 0);
	if (-1 == server_sock)
		error_handling("socket() error.");

	memset(&server_addr, 0, sizeof(server_addr));
	server_addr.sin_family = AF_INET;
	server_addr.sin_addr.s_addr = htonl(INADDR_ANY);
	server_addr.sin_port = htons(atoi(argv[1]));

	if (-1 == bind(server_sock, (struct sockaddr *)&server_addr, sizeof(server_addr)))
		error_handling("bind() error");

	if (-1 == listen(server_sock, 5))
		error_handling("listen() error");

	client_addr_size = sizeof(client_addr);
	client_sock = accept(server_sock, (struct sockaddr *)&client_addr, &client_addr_size);

	if (-1 == client_sock)
		error_handling("accept() error");
	else
		printf("Connected client!\n");

	while (1) {
		str_len = recv(client_sock, message, sizeof(message) - 1, MSG_PEEK | MSG_DONTWAIT);
		/* set PEEK option and call recv, input buffer data will not be delete */
		/* DONTWAIT check the existing of data by nonblock way */
		if (str_len > 0)
			break;
	}

	message[str_len] = 0;
	printf("Buffering %lu bytes: %s\n", sizeof(message), message);

	str_len = 0;
	memset(message, 0, BUF_SIZE);
	str_len = recv(client_sock, message, sizeof(message) - 1, 0);
	message[str_len] = 0;
	printf("Received %lu bytes: %s\n", sizeof(message), message);

	close(client_sock);
	close(server_sock);

	return 0;
}

void error_handling(char *message)
{
	fputs(message, stderr);
	fputc('\n', stderr);
	exit(1);
}

