
#include <varargs.h>

#define MAXARGS    100

/*    execl is called by
 *        execl(file, arg1, arg2, ..., (char *)0);
 */
execl(va_alist)
va_dcl
{
	va_list ap;
	char *file;
	char *args[MAXARGS];
	int argno = 0;

	va_start(ap);
	file = va_arg(ap, char *);
	while ((args[argno++] = va_arg(ap, char *)) != (char *)0) ;
	va_end(ap);
	return execv(file, args);
}

