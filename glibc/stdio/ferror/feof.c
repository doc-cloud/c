
#include <stdio.h>

int main ()
{
	FILE *fp;
	int c;
	int n = 0;

	fp = fopen("file.txt","r");
	if(NULL == fp) {
		perror("Error in opening file");
		return(-1);
	}
	while(!feof(fp)) {
		c = fgetc(fp);
		printf("%c", c);
	}

	fclose(fp);

	return 0;
}

