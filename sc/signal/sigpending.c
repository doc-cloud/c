
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>

void sigusr1_handler(int signo)
{
	printf("catch SIGUSR1\n");
}

int main(void)
{
	sigset_t set;
	sigset_t sig_pend;
	sigemptyset(&set);
	sigemptyset(&sig_pend);
	if((signal(SIGUSR1, sigusr1_handler)) == SIG_ERR){
		perror("can’t set handler for SIGUSR1");
		exit(1);
	}
	sigaddset(&set, SIGUSR1);
	if(sigprocmask(SIG_BLOCK, &set, NULL) == -1){
		perror("fail to set signal-mask");
		exit(1);
	}
	/* 10 seconds sleep, catch signal, note : process will not aweek by pending signal */
	sleep(10);
	/* get all pending signal set */
	if(sigpending(&sig_pend) == -1){
		perror("fail to get pending signal");
		exit(1);
	}
	/* is there a SIGUSR1 is pending ? */
	if(sigismember(&sig_pend, SIGUSR1) == 1)
		printf("there is a signal, SIGUSR1, is pending\n");
	else{
		perror("fail to test signal-set");
		exit(1);
	}
	/* undo the block for SIGUSR1, can be handled */
	if(sigprocmask(SIG_UNBLOCK, &set, NULL) == -1){
		perror("fail to set signal-mask");
		exit(1);
	}
	printf("SIGUSR1 is available again\n");
	return 0;
}

