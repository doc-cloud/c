
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<arpa/inet.h>
#include<sys/socket.h>
#include<sys/epoll.h>
#include<errno.h>
#include<fcntl.h>

void error_handling(char *message);
void set_nonblocking_mod(int fd);

#define BUFF_SIZE 4
#define EPOLL_SIZE 30

int main(int argc, char *argv[])
{
	int sock_server;
	int sock_client;

	struct sockaddr_in addr_server;
	struct sockaddr_in addr_client;
	socklen_t size_addr_client;

	char buff[BUFF_SIZE];
	int str_len, i, errno;

	int epfd, count_event;
	struct epoll_event *ep_events;
	struct epoll_event event;

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

	epfd = epoll_create(EPOLL_SIZE);
	//epfd = epoll_create(0); //epoll_wait() Error
	ep_events = (struct epoll_event *)malloc(sizeof(struct epoll_event) * EPOLL_SIZE);

	/* Non-blocking mode socket */
	set_nonblocking_mod(sock_server);
	/* monitor events of need read */
	event.events = EPOLLIN;
	event.data.fd = sock_server;
	epoll_ctl(epfd, EPOLL_CTL_ADD, sock_server, &event);
	while (1) {
		count_event = epoll_wait(epfd, ep_events, EPOLL_SIZE, -1);
		if (count_event == -1) {
			puts("epoll_wait() Error");
			break;
		}
		/* check call times of epoll_wait */
		puts("Return epoll_wait()");

		for (i = 0; i < count_event; i++) {
			if (ep_events[i].data.fd == sock_server) {
				size_addr_client = sizeof(addr_client);
				sock_client = accept(sock_server, (struct sockaddr *)&addr_client, &size_addr_client);
				set_nonblocking_mod(sock_client);
				/* non blocking */
				event.events = EPOLLIN | EPOLLET;
				event.data.fd = sock_client;
				epoll_ctl(epfd, EPOLL_CTL_ADD, sock_client, &event);
				printf("Connected client : %d\n", sock_client);
			} else {
				while (1) {
					str_len = read(ep_events[i].data.fd, buff, BUFF_SIZE);
					if (str_len > 0) {
						buff[str_len] = 0;
						printf("Message from client %d: %s\n", i, buff);
						/* echo to client */
						write(ep_events[i].data.fd, buff, str_len);
					} else if (str_len == 0) {
						epoll_ctl(epfd, EPOLL_CTL_DEL, ep_events[i].data.fd, NULL);
						close(ep_events[i].data.fd);
						printf("Disconnected client %d!\n", ep_events[i].data.fd);
						break;
					} else {
						/* The buffer is empty. */
						if (errno == EAGAIN)
							break;
					}
				}
			}
		}
	}

	close(sock_server);
	close(epfd);

	return 0;
}

void error_handling(char *message)
{
	fputs(message, stderr);
	fputc('\n', stderr);
	exit(EXIT_FAILURE);
}

void set_nonblocking_mod(int fd)
{
	int flag;
	flag = fcntl(fd, F_GETFL, 0);
	fcntl(fd, flag | O_NONBLOCK);
}

