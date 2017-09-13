
/* fputs() writes the string s to stream, without its terminating null byte ('\0'). */

#include <stdio.h>

int main ()
{
	FILE *fp;

	fp = fopen("file.txt", "w+");

	fputs("Linkerist\n", fp);
	fputs("Heracles\n", fp);

	fclose(fp);

	fputs("Linkerist", stdout);
	fputs("Heracles\n", stdout);

	return(0);
}

