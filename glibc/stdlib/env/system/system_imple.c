
#include <sys/wait.h>
#include <unistd.h>

int system_(const char * cmdstring)
{
	pid_t pid;
	int status;
	if(NULL == cmdstring)
		return 1;
	pid = fork();
	if (0 > pid) {
		status = -1;
	} else if(0 == pid) {
		execl("/bin/sh", "sh", "-c", cmdstring, NULL); 
		_exit(127);
	}
	if(waitpid(pid, &status, 0) == -1)
		status = -1;
	return status;
}

int main()
{
	system_("ls");
	return 0;
}

