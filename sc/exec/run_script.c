#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main()
{
	pid_t pid;
	pid = fork();
	if(pid < 0) {
		printf("fail to fork\n");
		exit(1);
	} else if(pid == 0) {
		execl("./interp.sh", "interp", "arg1", "arg2", NULL); 
		_exit(0);
	}
	exit(0);
}
