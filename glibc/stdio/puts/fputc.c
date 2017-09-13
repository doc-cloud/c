
#include <stdio.h>

int main ()
{
	FILE *fp;
	int ch;

	fp = fopen("file.txt", "w+");
	for(ch = 33 ; ch <= 100; ch++)
		fputc(ch, fp);
	fclose(fp);

	for(ch = 33 ; ch <= 100; ch++)
		fputc(ch, stdout);

	return(0);
}

