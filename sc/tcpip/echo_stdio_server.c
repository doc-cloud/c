
/*
 * standard I/O implement of echo server
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
	int client_sock;
	FILE *fp_write, *fp_read;

	struct sockaddr_in server_addr;
	struct sockaddr_in client_addr;
	socklen_t client_addr_size;

	char message[BUF_SIZE];

	int str_len, i;

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

	for (i = 0; i < 5; i++) {
		client_sock = accept(server_sock, (struct sockaddr *)&client_addr, &client_addr_size);
		if (-1 == client_sock)
			error_handling("accept() error");
		else
			printf("Connected client : %d\n", i + 1);

		fp_read = fdopen(client_sock, "r");
		fp_write = fdopen(client_sock, "w");
		/*
		while( (str_len = read(client_sock, message, BUF_SIZE)) != 0 )
			write(client_sock, message, str_len);
		close(client_sock);
		*/
		while (!feof(fp_read)) {
			/* fgets base on string, fputs provide service */
			fgets(message, BUF_SIZE, fp_read);
			fputs(message, fp_write);
			fflush(fp_write);
			/* standard I/O provide extra buffer internally, certainly send data to socket buffer by fflush */
		}
		fclose(fp_read);
		fclose(fp_write);
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

