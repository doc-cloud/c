
/*
 * echo server base on multi process
 */

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>

#include<arpa/inet.h>
#include<sys/socket.h>

#include<sys/wait.h>
#include<signal.h>

void error_handling(char *message);

#define BUF_SIZE 1024
void read_childproc(int sig);

int main(int argc, char *argv[])
{
	int server_sock;
	int client_sock;

	struct sockaddr_in server_addr;
	struct sockaddr_in client_addr;
	socklen_t client_addr_size;

	char buff[BUF_SIZE];
	int str_len, i;

	pid_t pid;
	struct sigaction sig_act;

	if (argc != 2) {
		printf("Usage : %s <port>\n", argv[0]);
		exit(1);
	}

	sig_act.sa_handler = read_childproc;
	sigemptyset(&sig_act.sa_mask);
	sig_act.sa_flags = 0;
	sigaction(SIGCHLD, &sig_act, 0);

	server_sock = socket(PF_INET, SOCK_STREAM, 0);
	if (-1 == server_sock)
		error_handling("socket() error.");

	memset(&server_addr, 0, sizeof(server_addr));
	server_addr.sin_family = AF_INET;
	server_addr.sin_addr.s_addr = htonl(INADDR_ANY);
	server_addr.sin_port = htons(atoi(argv[1]));

	/* alloc IP address and port */
	if (-1 == bind(server_sock, (struct sockaddr *)&server_addr, sizeof(server_addr)))
		error_handling("bind() error");

	if (-1 == listen(server_sock, 5))
		error_handling("listen() error");

	while (1) {
		client_addr_size = sizeof(client_addr);
		client_sock = accept(server_sock, (struct sockaddr *)&client_addr, &client_addr_size);

		if (-1 == client_sock)
			continue;
		else
			puts("new client connected...");
		//create a new process to deal with the client
		pid = fork();
		if (pid < 0) {
			fputs("Error fork()!", stderr);
			continue;
		} else if(0 == pid) {
			/* child process, business logic is here. */
			/* the socket has been deliver to child process yet, child need close the fd */
			close(server_sock);
			while ((str_len = read(client_sock, buff, BUF_SIZE)) != 0)
				write(client_sock, buff, str_len);

			close(client_sock);
			/* child process terminated */
			exit(0);
		} else
			/* the socket has been deliver to child process yet, server destroy it own fd */
			close(client_sock);
	}

	close(server_sock);

	return 0;
}

void read_childproc(int sig)
{
	pid_t pid;
	int status;
	pid = waitpid(-1, &status, WNOHANG);
	printf("removed child proc ID = %d\n", pid);
}

void error_handling(char *message)
{
	fputs(message, stderr);
	fputc('\n', stderr);
	exit(1);
}

