/*
 * after recv a file from server, send a message
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
	struct sockaddr_in server_addr;

	char buf[BUF_SIZE], message[BUF_SIZE];
	FILE *fp;
	int read_count = 0;

	if (3 != argc) {
		printf("Usage : %s <IP> <Port> \n", argv[0]);
		exit(1);
	}

	fp = fopen("received.dat", "wb");
	if (NULL == fp)
		error_handling("File open failed!");

	server_sock = socket(PF_INET, SOCK_STREAM, 0);
	if (-1 == server_sock) {
		error_handling("socket() error!");
		exit(1);
	}

	memset(&server_addr, 0, sizeof(server_addr));
	server_addr.sin_family = AF_INET;
	server_addr.sin_addr.s_addr = inet_addr(argv[1]);
	server_addr.sin_port = htons(atoi(argv[2]));

	if (-1 == connect(server_sock, (struct sockaddr *)&server_addr,
			  sizeof(server_addr))) {
		error_handling("connect() error!");
	}

	while ((read_count = read(server_sock, message, BUF_SIZE)))
		fwrite((void *)buf, 1, read_count, fp);

	fclose(fp);

	puts("File Received from server.\n");

	/* send a message */
	strcpy(message, "File Received. Thank you!");
	write(server_sock, message, strlen(message));

	close(server_sock);

	return 0;
}

void error_handling(char *message)
{
	fputs(message, stderr);
	fputc('\n', stderr);
	exit(1);
}

