
#include <stdio.h>

int main()
{
	FILE *fp;
	int ch;

	fp = fopen("file.txt", "r");

	if( fp != NULL ) {
		while(!feof(fp)) {
			ch = fgetc(fp);
			printf("%c", ch);
		}
		rewind(fp);

		while(!feof(fp)) {
			ch = fgetc(fp);
			printf("%c", ch);
		}
		fclose(fp);
	}

	return(0);
}

