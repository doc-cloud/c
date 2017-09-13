
#include <stdio.h>

int main ()
{
	FILE *fp;
	int c;
	int n = 0;

	fp = fopen("file.txt","r");
	if(NULL == fp) {
		perror("Error in opening file");
		exit(1);
	}

	do {
		c = fgetc(fp);
		printf("%c\n", c);
	} while(c != EOF);

	fclose(fp);

	return(0);
}

