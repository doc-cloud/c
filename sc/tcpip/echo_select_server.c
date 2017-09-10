
/*
 * echo server multiplexing I/O implement by select
 */

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<arpa/inet.h>
#include<sys/socket.h>
#include<sys/time.h>
#include<sys/select.h>

void error_handling(char *message);

#define BUFF_SIZE 32

int main(int argc, char *argv[])
{
	int server_sock;
	int client_sock;

	struct sockaddr_in server_addr;
	struct sockaddr_in client_addr;
	socklen_t client_addr_size;

	char buff[BUFF_SIZE];
	fd_set reads, reads_init;
	struct timeval timeout, timeout_init;

	int str_len, i, fd_max, fd_num;

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

	/* register fd_set var */
	FD_ZERO(&reads_init);
	/* monitor socket: server_sock */
	FD_SET(server_sock, &reads_init);
	/* stdin also works */
	FD_SET(0, &reads_init);
	fd_max = server_sock;

	timeout_init.tv_sec = 5;
	timeout_init.tv_usec = 0;

	while (1) {
		reads = reads_init;
		timeout = timeout_init;
		fd_num = select(fd_max + 1, &reads, NULL, NULL, &timeout);
		if (fd_num < 0) {
			fputs("Error select()!", stderr);
			break;
		} else if (0 == fd_num){
			puts("Time-out!");
			continue;
		}
		for (i = 0; i <= fd_max; i++) {
			if (FD_ISSET(i, &reads)) {
				/* connection request */
				if (i == server_sock) {

					client_addr_size = sizeof(client_addr);
					client_sock = accept(server_sock, (struct sockaddr *)&client_addr, &client_addr_size);
					if (-1 == client_sock)
						/* bad robustness, program corrupt */
						error_handling("accept() error");
					else {
						/* register socket which connect to client */
						FD_SET(client_sock, &reads_init);
						if (fd_max < client_sock)
							fd_max = client_sock;
						printf("Connected client : %d\n", client_sock);
					}
				} else {
					/* read message! */
					str_len = read(i, buff, BUFF_SIZE);
					if (str_len) {	//echo to client
						buff[str_len] = 0;
						printf("Message from client %d: %s", i, buff);
						write(i, buff, str_len);
					} else {	//close connection
						FD_CLR(i, &reads_init);
						close(i);
						printf("Disconnected client %d!\n", i);
					}
				} /* end of i==|!=server_sock */
			} /* end of if(FD_ISSET) */
		} /* end of while */

	} /* end of for */

	close(server_sock);

	return 0;
}

void error_handling(char *message)
{
	fputs(message, stderr);
	fputc('\n', stderr);
	exit(EXIT_FAILURE);
}

