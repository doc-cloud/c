#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netinet/ip.h>
#include <arpa/inet.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define RECV_BUF_SIZE 1000

int main(){
	char *echo_host = "192.168.1.102";
	int echo_port = 7777;
	struct sockaddr_in *server = (struct sockaddr_in *)malloc(sizeof(struct sockaddr_in));
	int sockfd;

	server->sin_family = AF_INET;
	server->sin_port = htons(echo_port);
	server->sin_addr.s_addr = inet_addr(echo_host);

	sockfd = socket(AF_INET,SOCK_STREAM,0);

	if(-1 == bind(sockfd,(struct sockaddr *)server,sizeof(*server)))
		printf("bind failed\n");

	listen(sockfd,SOMAXCONN);

	struct sockaddr_in *client = (struct sockaddr_in *)malloc(sizeof(struct sockaddr_in));
	int clientfd;
	char *recvbuf = (char *)malloc(RECV_BUF_SIZE);
	int nbytes = 0;
	
	int client_size = sizeof(*client);

	clientfd = accept(sockfd,(struct sockaddr *)client,&client_size);

	printf("accept connect from %s : %u\n",inet_ntoa(client->sin_addr),ntohs(client->sin_port));

	printf("Numeric : %u\n",ntohl(client->sin_addr.s_addr));
	while(1){
		nbytes = read(clientfd,recvbuf,RECV_BUF_SIZE);
		if(0 >= nbytes){
			close(clientfd);
			printf("read error , connect closed!\n");
			exit(0);
		}
		printf("recvbuf size : %u\n",nbytes);
		printf("recvbuf text : %s\n",recvbuf);
		write(clientfd,recvbuf,nbytes);
	}
}
