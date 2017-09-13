
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <pthread.h>

void *tfn1(void *arg)
{
	printf("the thread\n");
	return NULL;
}

int main(void)
{
	int err;
	pthread_t tid;
	pthread_attr_t attr;

	err = pthread_attr_init(&attr);
	if (err != 0) {
		printf("can’t init attr %s\n", strerror(err));
		exit(1);
	}

	/* set thread attribute to thread is detach with thread exit state info */
	err = pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_DETACHED);
	if (err != 0) {
		printf("can’t set attr %s\n", strerror(err));
		exit(1);
	}

	/* create a thread by this thread attribute, it is detached */
	err = pthread_create(&tid, &attr, tfn1, NULL);
	if (err != 0) {
		printf("can’t create thread %s\n", strerror(err));
		exit(1);
	}

	sleep(1);
	/* due to detached, cannot get exit status of this thread, join error */
	err = pthread_join(tid, NULL);
	if (err != 0)
		printf("thread has been detached\n");

	return 0;
}

