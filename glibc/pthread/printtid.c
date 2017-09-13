
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

void *thfn(void *arg)
{
	pid_t pid;
	pthread_t tid;
	pid = getpid();
	tid = pthread_self();
	printf("the new thread: pid is: %u, tid is: %u\n", (unsigned int)pid, (unsigned int)tid);
	return NULL;
}

int main(void)
{
	pid_t pid;
	int err;
	pthread_t tid, mtid;
	pid = getpid();
	mtid = pthread_self();
	err = pthread_create(&tid, NULL, thfn, NULL);
	/* err is same as errno, it can be convert by strerror to description */
	if (err != 0) {
		/* cannot use perror, the error numner is not in errno */
		printf("can’t create thread %d\n", strerror(err));
		exit(1);
	}
	/* make sure new thread be invoked before main thread */
	sleep(1);
	printf("the main thread: pid is: %u, tid is: %u\n", (unsigned int)pid, (unsigned int)mtid);
	return 0;
}

