
/* integer calculate server */

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<arpa/inet.h>
#include<sys/socket.h>

void error_handling(char *message);
int calculate(int operand_num, int operand[], char operator);

#define BUF_SIZE 1024
#define RESULT_SIZE sizeof(int)
#define OPERAND_SIZE sizeof(int)

int main(int argc, char *argv[])
{
	int server_sock;
	int client_sock;

	struct sockaddr_in server_addr;
	struct sockaddr_in client_addr;
	socklen_t client_addr_size;

	char message[BUF_SIZE];

	int operand_count, result, i;
	int recv_cnt, recv_len;

	if (argc != 2) {
		printf("Usage : %s <port>\n", argv[0]);
		exit(1);
	}

	server_sock = socket(PF_INET, SOCK_STREAM, 0);
	if (-1 == server_sock) {
		error_handling("socket() error.");
	}

	memset(&server_addr, 0, sizeof(server_addr));
	server_addr.sin_family = AF_INET;
	server_addr.sin_addr.s_addr = htonl(INADDR_ANY);
	server_addr.sin_port = htons(atoi(argv[1]));

	if (-1 == bind(server_sock, (struct sockaddr *)&server_addr, sizeof(server_addr)))
		error_handling("bind() error");

	if (-1 == listen(server_sock, 5))
		error_handling("listen() error");

	client_addr_size = sizeof(client_addr);

	for (i = 0; i < 5; i++) {
		client_sock = accept(server_sock, (struct sockaddr *)&client_addr, &client_addr_size);
		if (-1 == client_sock)
			error_handling("accept() error");
		else
			printf("Connected client : %d\n", i + 1);

		//read(client_sock, &operand_count, 1);
		/* cannot read right operand_count directly, instead with these two sentences */
		read(client_sock, &message[BUF_SIZE - 1], 1);
		operand_count = (int)message[BUF_SIZE - 1];
		printf("Operand Num : %d\n", operand_count);

		recv_len = 0;
		while (recv_len < (operand_count * OPERAND_SIZE + 1)) {
			recv_cnt =
			    read(client_sock, &message[recv_len],
				 BUF_SIZE - recv_len);
			recv_len += recv_cnt;
		}
		//printf("Received message length : %d\n", recv_len);

		result =
		    calculate(operand_count, (int *)message,
			      message[operand_count * OPERAND_SIZE]);
		//printf("Result : %d\n", result);              

		write(client_sock, &result, RESULT_SIZE);

		close(client_sock);
	}

	close(server_sock);

	return 0;
}

int calculate(int operand_num, int operand[], char operator)
{
	int i, result;
	switch (operator) {
	case '+':
		result = 0;
		for (i = 0; i < operand_num; i++)
			result += operand[i];
		break;
	case '-':
		result = operand[0];
		for (i = 1; i < operand_num; i++)
			result -= operand[i];
		break;
	case '*':
		result = 1;
		for (i = 0; i < operand_num; i++)
			result *= operand[i];
		break;
	default:
		return 0;
	}
	return result;
}

void error_handling(char *message)
{
	fputs(message, stderr);
	fputc('\n', stderr);
	exit(1);
}

