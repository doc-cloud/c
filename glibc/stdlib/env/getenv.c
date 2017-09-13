
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	char * p;
	p = getenv("HOME");
	if(NULL == p){
		perror("fail to get env");
		exit(1);
	}
	printf("$HOME is %s\n", p);
	return 0;
}

