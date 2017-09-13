
/* copy binary file */

#include<stdio.h>
#include<stdlib.h>

#define BUFF_SIZE 3

void error_handling(char *message);

int main(int argc, char *argv[])
{
	FILE *fp_read, *fp_write;
	unsigned char buff[BUFF_SIZE];
	int bytes;

	if (3 != argc) {
		printf("Usage : %s <oldfile> <newfile>\n", argv[0]);
		exit(1);
	}

	fp_read = fopen(argv[1], "rb");

	if (NULL == fp_read)
		error_handling("fopen() file for reading error!");
	fp_write = fopen(argv[2], "wb");
	if (NULL == fp_write)
		error_handling("fopen() file for writing error!");

	while ((bytes = fread(buff, sizeof(unsigned char), BUFF_SIZE, fp_read)) > 0)
		fwrite(buff, sizeof(unsigned char), bytes, fp_write);

	fclose(fp_read);
	fclose(fp_write);
	return 0;
}

void error_handling(char *message)
{
	fputs(message, stderr);
	fputc('\n', stderr);
	exit(1);
}

