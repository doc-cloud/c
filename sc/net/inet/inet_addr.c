
#include<stdio.h>
#include<arpa/inet.h>

int main(int argc, char *argv[])
{
	char addr1[] = "127.0.0.1";
	char *addr2 = "192.168.1.255";
	char *addr3 = "192.168.1.256";

	unsigned long conv_addr;

	conv_addr = inet_addr(addr1);
	if (INADDR_NONE == conv_addr)
		printf("Error 1\n");
	else
		printf("Network ordered interger addr : %#lx \n", conv_addr);

	conv_addr = inet_addr(addr2);
	if (INADDR_NONE == conv_addr)
		printf("Error 2\n");
	else
		printf("Network ordered interger addr : %#lx \n", conv_addr);

	conv_addr = inet_addr(addr3);
	if (INADDR_NONE == conv_addr)
		printf("Error 3\n");
	else
		printf("Network ordered interger addr : %#lx \n", conv_addr);

	return 0;
}

