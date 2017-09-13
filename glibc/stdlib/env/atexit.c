
/*
 * registers the given function to be called at normal process termination, either via exit(3) or via return from the program's main().
 * Functions so registered are called in the reverse order of their registration; no arguments are passed.
 * 
 * The same function may be registered multiple times: it is called once for each registration.
 * 
 * POSIX.1-2001 requires that an implementation allow at least ATEXIT_MAX (32) such functions to be registered.  The actual limit supported by  an	implementa‐
 * tion can be obtained using sysconf(3).
 * 
 * When  a child process is created via fork(2), it inherits copies of its parent's registrations.	Upon a successful call to one of the exec(3) functions, all
 * registrations are removed.
 */

#include <stdio.h>
#include <stdlib.h>

void f1(void)
{
	printf("the first exit handler\n");
}

void f2(void)
{
	printf("the second exit handler\n");
}

int main(void)
{
	if(-1 == atexit(f1)) {
		perror("fail to set exit handler");
		exit(1);
	}
	if(-1 == atexit(f1)) {
		perror("fail to set exit handler");
		exit(1);
	}
	if(-1 == atexit(f2)) {
		perror("fail to set exit handler");
		exit(1);
	}
	return 0;
}

