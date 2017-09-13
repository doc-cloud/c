
#include<stdio.h>

int main ()
{
	FILE *fp;
	char str[] = "Linkerist Heracles, vay";

	fp = fopen("file.txt", "w");
	fwrite(str, 1, sizeof(str), fp);

	fclose(fp);

	return 0;
}

