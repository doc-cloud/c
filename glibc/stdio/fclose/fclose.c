
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	FILE *fp;
	int i;	
	fp = fopen("test.txt", "wb");
	if(fp == NULL) {
		perror("fail to open");
		exit(1);
	}
	i = 0;
	while(i < 5) {
		fprintf(fp, "hello world\n");
		sleep(3);
		i++;
	}
	/* you may check the return value of fclose in network environment */
	fclose(fp);
	return 0;
}

