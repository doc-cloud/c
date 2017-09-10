
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<arpa/inet.h>
#include<sys/socket.h>

void error_handling(char *message);

#define BUFF_SIZE 1024

int main(int argc, char *argv[])
{
	int sock_server;
	int sock_client;
	FILE *fp_write, *fp_read;

	struct sockaddr_in addr_server;
	struct sockaddr_in addr_client;
	socklen_t addr_client_size;

	char message[BUFF_SIZE];

	if (argc != 2) {
		printf("Usage : %s <port>\n", argv[0]);
		exit(1);
	}

	sock_server = socket(PF_INET, SOCK_STREAM, 0);
	if (-1 == sock_server)
		error_handling("socket() error.");

	memset(&addr_server, 0, sizeof(addr_server));
	addr_server.sin_family = AF_INET;
	addr_server.sin_addr.s_addr = htonl(INADDR_ANY);
	addr_server.sin_port = htons(atoi(argv[1]));

	if (-1 == bind(sock_server, (struct sockaddr *)&addr_server, sizeof(addr_server)))
		error_handling("bind() error");

	if (-1 == listen(sock_server, 5))
		error_handling("listen() error");
	addr_client_size = sizeof(addr_client);

	sock_client = accept(sock_server, (struct sockaddr *)&addr_client, &addr_client_size);
	/* accept create I/O socket automatically */
	if (-1 == sock_client)
		error_handling("accept() error");
	else
		printf("Connected client... \n");

	fp_read = fdopen(sock_client, "r");
	/* duplicate fd base on created */
	fp_write = fdopen(dup(sock_client), "w");
	/* call fgets, fputs base on string */
	fputs("FROM SERVER: Hi~ client? \n", fp_write);
	fputs("I love you.\n", fp_write);
	fputs("You are awesome! \n", fp_write);
	fflush(fp_write);

	/* no matter how complex fd it was, it turn to halfway, deliver EOF, when call shutdown */
	shutdown(fileno(fp_write), SHUT_WR);
	fclose(fp_write);

	fgets(message, BUFF_SIZE, fp_read);
	fputs(message, stdout);
	fclose(fp_read);

	return 0;
}

void error_handling(char *message)
{
	fputs(message, stderr);
	fputc('\n', stderr);
	exit(1);
}

