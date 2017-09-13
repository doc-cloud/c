
#include <stdio.h>
#include <stdlib.h>

int main ()
{
	FILE *fp;
	int len;

	fp = fopen("file.txt", "r");
	if(NULL == fp) {
		perror ("Error opening file");
		exit(1);
	}
	fseek(fp, 0, SEEK_END);

	len = ftell(fp);
	fclose(fp);

	printf("Total size of file.txt = %d bytes\n", len);

	return 0;
}

