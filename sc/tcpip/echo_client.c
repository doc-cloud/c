
/*
 * echo client base on TCP
 */

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<arpa/inet.h>
#include<sys/socket.h>

void error_handling(char *message);

#define BUF_SIZE 1024

int main(int argc, char *argv[])
{
	int server_sock;
	struct sockaddr_in server_addr;

	char message[BUF_SIZE];
	int str_len, recv_len, recv_cnt;

	if (3 != argc) {
		printf("Usage : %s <IP> <Port> \n", argv[0]);
		exit(1);
	}

	server_sock = socket(PF_INET, SOCK_STREAM, 0);
	if (-1 == server_sock) {
		error_handling("socket() error!");
		exit(1);
	}

	memset(&server_addr, 0, sizeof(server_addr));
	server_addr.sin_family = AF_INET;
	server_addr.sin_addr.s_addr = inet_addr(argv[1]);
	server_addr.sin_port = htons(atoi(argv[2]));

	if (-1 == connect(server_sock, (struct sockaddr *)&server_addr, sizeof(server_addr)))
		error_handling("connect() error!");
	else
		puts("Connected......");

	while (1) {
		printf("Input message(Q to quit) : ");
		fgets(message, BUF_SIZE, stdin);

		if (0 == strcmp(message, "q\n") || 0 == strcmp(message, "Q\n"))
			break;

		str_len = write(server_sock, message, strlen(message));
		recv_len = 0;
		/* reduce the dead loop because of abnormal case */
		while (recv_len < str_len) {
			recv_cnt = read(server_sock, &message[recv_len], BUF_SIZE - 1 - recv_len);
			if (-1 == recv_cnt)
				error_handling("read() error!");
			recv_len += recv_cnt;
		}
		message[recv_len] = 0;
		printf("Message from server : %s \n", message);
	}

	close(server_sock);

	return 0;
}

void error_handling(char *message)
{
	fputs(message, stderr);
	fputc('\n', stderr);
	exit(1);
}

