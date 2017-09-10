
#include<stdio.h>
#include<string.h>
#include<arpa/inet.h>

int main(int argc, char *argv[])
{
	char str_addr[20];
	char *str_ptr;
	struct sockaddr_in sockaddr;

	sockaddr.sin_addr.s_addr = htonl(0x1020304);
	str_ptr = inet_ntoa(sockaddr.sin_addr);
	strcpy(str_addr, str_ptr);
	printf("Dotted-Decimal notation IP addr : %s \n", str_addr);

	return 0;
}

