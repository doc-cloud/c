
#include <stdio.h>
#include <stdarg.h>

void write_fmt(char *format, ...)
{
	va_list args;

	va_start(args, format);
	vprintf(format, args);
	va_end(args);
}

int main ()
{
	write_fmt("named %s integer : %d\n", "Linkerist", 98);
	write_fmt("named %s, real %s\n", "Linkerist", "Heracles");

	return 0;
}

