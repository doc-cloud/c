
#include <stdio.h>
#include <stdarg.h>

void write_fmt_to_stream(FILE *stream, char *format, ...)
{
	va_list args;

	va_start(args, format);
	vfprintf(stream, format, args);
	va_end(args);
}

int main ()
{
	FILE *fp;

	fp = fopen("file.txt","w");

	write_fmt_to_stream(fp, "two argument %s and %d \n", "Linkerist", 98);

	fclose(fp);

	return(0);
}

