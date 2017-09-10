
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<arpa/inet.h>
#include<sys/socket.h>

void error_handling(char *message);

int main(int argc, char *argv[])
{
	int server_sock;
	struct sockaddr_in server_addr;
	int idx = 0;
	int read_len = 0;

	char message[30];
	int str_len = 0;

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

	//str_len = read(server_sock, message, sizeof(message) - 1);
	while(read_len = read(server_sock, &message[idx++], 1)) {
		if(-1 == read_len)
			error_handling("read() error!");
			
		str_len += read_len;
	}

	if (-1 == str_len)
		error_handling("read() error!");
	printf("function call : %d\n", str_len);
	printf("Message from server : %s \n", message);

	close(server_sock);

	return 0;
}

void error_handling(char *message)
{
	fputs(message, stderr);
	fputc('\n', stderr);
	exit(1);
}

