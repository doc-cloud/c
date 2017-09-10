
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
#include <sys/ptrace.h>
#include <sys/wait.h>
#include <asm/ptrace.h>

static long pid;

int upeek(int pid,long off,long *res){
	long val;
	if(-1 == (val = ptrace(PTRACE_PEEKUSER,pid,off,0)))
		return -1;
	*res = val;
	return 0;
}

void trace_syscall(){
	long res;
	if(0 > (res = ptrace(PTRACE_SYSCALL,pid,(char *)1,0)))
		printf("Failed to execute until next syscall: %ld\n",res);
}

void sigchld_handler(int signum){
	long scno;
	if(upeek(pid,4 * ORIG_EAX,&scno) < 0)
		return ;
	if(0 != scno)
		printf("System call: %lu\n",scno);
	trace_syscall();
}

int main(int argc,char **argv){
	int res;
	if(2 != argc){
		printf("Usage: ptrace <pid>\n");
		exit(-1);
	}
	pid = strtol(argv[1],NULL,10);
	if(0 >= pid){
		printf("No valid pid specified\n");
		exit(-1);
	}else{
		printf("Tracing requested for PID %lu\n",pid);
	}

	struct sigaction sigact;
	sigact.sa_handler = sigchld_handler;
	sigaction(SIGCHLD,&sigact,NULL);

	if(0 > (res = ptrace(PTRACE_ATTACH,pid,0,0))){
		printf("Failed to attach: %d\n",res);
		exit(-1);
	}else
		printf("Attached to %lu\n",pid);
	for(;;){
		wait(&res);
		if(0 == res)
			exit(1);
	}
}

/*
 * test line for shutdown without quit
 * */

