
#include <stdio.h>
#include <stdlib.h>

int main ()
{
	FILE *fp;

	printf("open nofile.txt\n");

	fp = fopen( "nofile.txt","r" );
	if(fp == NULL) {
		printf("Going to abort the program\n");
		abort();
	}
	printf("Going to close nofile.txt\n");
	fclose(fp);

	return(0);
}
