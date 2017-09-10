
/* multi thread chat program, server */

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<arpa/inet.h>
#include<sys/socket.h>
#include<pthread.h>

#define BUFF_SIZE 100
#define CLIENT_MAX 256

void error_handling(char *message);
void *client_handler(void *arg);
void send_msg(char *msg, int len);

int count_client = 0;
int socks_client[CLIENT_MAX];
pthread_mutex_t mutex;

int main(int argc, char *argv[])
{
	int sock_server;
	int sock_client;

	struct sockaddr_in addr_server;
	struct sockaddr_in addr_client;
	socklen_t size_addr_client;

	pthread_t pthread_id;

	if (argc != 2) {
		printf("Usage : %s <port>\n", argv[0]);
		exit(1);
	}

	pthread_mutex_init(&mutex, NULL);

	sock_server = socket(PF_INET, SOCK_STREAM, 0);
	if (-1 == sock_server) {
		error_handling("socket() error.");
	}

	memset(&addr_server, 0, sizeof(addr_server));
	addr_server.sin_family = AF_INET;
	addr_server.sin_addr.s_addr = htonl(INADDR_ANY);
	addr_server.sin_port = htons(atoi(argv[1]));

	if (-1 == bind(sock_server, (struct sockaddr *)&addr_server, sizeof(addr_server)))
		error_handling("bind() error");

	if (-1 == listen(sock_server, 5))
		error_handling("listen() error");

	while (1) {
		size_addr_client = sizeof(addr_client);
		sock_client = accept(sock_server, (struct sockaddr *)&addr_client, &size_addr_client);

		pthread_mutex_lock(&mutex);
		/* Lock access the public code */
		socks_client[count_client++] = sock_client;
		pthread_mutex_unlock(&mutex);

		pthread_create(&pthread_id, NULL, client_handler, (void *)&sock_client);
		pthread_detach(pthread_id);
		printf("Client IP:%s \n", inet_ntoa(addr_client.sin_addr));

	}

	close(sock_server);
	pthread_mutex_destroy(&mutex);
	return 0;
}

void error_handling(char *message)
{
	fputs(message, stderr);
	fputc('\n', stderr);
	exit(EXIT_FAILURE);
}

void *client_handler(void *arg)
{
	int sock_client = *((int *)arg);
	int str_len = 0, i;
	char msg[BUFF_SIZE];

	while ((str_len = read(sock_client, msg, BUFF_SIZE - 1)) > 0) {
		//msg[str_len] = 0;
		//printf("Received a messgae: %s", msg);
		send_msg(msg, str_len);
	}

	pthread_mutex_lock(&mutex);

	/* remove disconnect client */
	for (i = 0; i < count_client; i++) {
		if (sock_client == socks_client[i]) {
			while (i++ <= count_client - 1)
				socks_client[i] = socks_client[i + 1];
			break;
		}
	}
	count_client--;
	pthread_mutex_unlock(&mutex);
	close(sock_client);

	return NULL;
}

/* send message to all clients */
void send_msg(char *msg, int len)
{
	int i;

	pthread_mutex_lock(&mutex);

	for (i = 0; i < count_client; i++)
		write(socks_client[i], msg, len);

	pthread_mutex_unlock(&mutex);
}

