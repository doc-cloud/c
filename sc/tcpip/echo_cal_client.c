
/*
 * echo client calculates integer, wait for server after sending its' integer and operation, recv result from server
 * app protocol :
 * client connect to server, 1 byte for number of integer
 * int for integer
 * 1 byte for operator(+, -, *)
 * result for 1 machine word size
 * once get a result, disconnect with server
 */

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<arpa/inet.h>
#include<sys/socket.h>

void error_handling(char *message);

#define BUF_SIZE 1024
#define RESULT_SIZE sizeof(int)
#define OPERAND_SIZE sizeof(int)

int main(int argc, char *argv[])
{
	int server_sock;
	struct sockaddr_in server_addr;

	char message[BUF_SIZE];
	int operand_count, result, i;

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

	printf("Operand count : ");
	scanf("%d", &operand_count);
	message[0] = (char)operand_count;

	for (i = 0; i < operand_count; i++) {
		printf("Operand %d : ", i + 1);
		scanf("%d", (int *)&message[i * OPERAND_SIZE + 1]);
	}
	fgetc(stdin);
	fputs("Operator(+ or - or *) : ", stdout);
	/* replace above following one with two sentences above, otherwise, program suspend after for done */
	//printf("Operator(+ or - or *) : ");
	scanf("%c", &message[operand_count * OPERAND_SIZE + 1]);

	write(server_sock, message, operand_count * OPERAND_SIZE + 2);

	read(server_sock, &result, RESULT_SIZE);
	printf("Result from server : %d \n", result);

	close(server_sock);

	return 0;
}

void error_handling(char *message)
{
	fputs(message, stderr);
	fputc('\n', stderr);
	exit(1);
}

