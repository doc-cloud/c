
/*
 * server send a file to client, and shutdown output stream, recv reply message.
 */ 

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<arpa/inet.h>
#include<sys/socket.h>

#define BUF_SIZE 30

void error_handling(char *message);

int main(int argc, char *argv[])
{
	int server_sock;
	int client_sock;

	struct sockaddr_in server_addr, client_addr;
	socklen_t client_addr_size;

	FILE *fp;
	char buf[BUF_SIZE];

	int read_count;

	if (argc != 2) {
		printf("Usage : %s <port>\n", argv[0]);
		exit(1);
	}

	fp = fopen("file_server.c", "rb");
	if (NULL == fp)
		error_handling("Open file failed!");

	server_sock = socket(PF_INET, SOCK_STREAM, 0);
	if (-1 == server_sock)
		error_handling("socket() error.");

	memset(&server_addr, 0, sizeof(server_addr));
	server_addr.sin_family = AF_INET;
	server_addr.sin_addr.s_addr = htonl(INADDR_ANY);
	server_addr.sin_port = htons(atoi(argv[1]));

	/* bind address and port number */
	if (-1 == bind(server_sock, (struct sockaddr *)&server_addr, sizeof(server_addr)))
		error_handling("bind() error");

	if (-1 == listen(server_sock, 5))
		error_handling("listen() error");

	client_addr_size = sizeof(client_addr);
	client_sock = accept(server_sock, (struct sockaddr *)&client_addr, &client_addr_size);

	if (-1 == client_sock)
		error_handling("accept() error");

	while (1) {
		read_count = fread((void *)buf, 1, BUF_SIZE, fp);
		if (read_count < BUF_SIZE) {
			write(client_sock, buf, read_count);
			break;
		}
		write(client_sock, buf, BUF_SIZE);
	}
	fclose(fp);

	/* shutdown output stream */
	shutdown(client_sock, SHUT_WR);

	/* recv info after recv file */
	read_count = read(client_sock, buf, BUF_SIZE);
	buf[read_count] = 0;
	printf("Message from client : %s\n", buf);

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

