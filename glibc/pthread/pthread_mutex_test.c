
#include<stdio.h>
#include<pthread.h>
#include<unistd.h>
#include<stdlib.h>

#define THREAD_NUM 30

void *thread_inc(void *arg);
void *thread_dec(void *arg);

long long num = 0;
pthread_mutex_t mutex;

int main(int argc, char *argv[])
{
	pthread_t thread_id[THREAD_NUM];
	int i;

	pthread_mutex_init(&mutex, NULL);

	printf("sizeof(long long) = %lu\n", sizeof(long long));
	for (i = 0; i < THREAD_NUM; i++) {
		if (i % 2)
			pthread_create(&(thread_id[i]), NULL, thread_inc, NULL);
		else
			pthread_create(&(thread_id[i]), NULL, thread_dec, NULL);
		//pthread_join(thread_id[i], NULL); //The result is OK.
	}
	for (i = 0; i < THREAD_NUM; i++)
		pthread_join(thread_id[i], NULL);

	pthread_mutex_destroy(&mutex);

	printf("Result = %lld\n", num);
	return 0;
}

void *thread_inc(void *arg)
{
	int i;

	pthread_mutex_lock(&mutex);
	for (i = 0; i < 50000000; i++)
		num += 1;
	pthread_mutex_unlock(&mutex);

	return NULL;
}

/*
 * the scope division is different, thread_inc have larger scope, but the delay period is longer for other threads,
 * thread_dec have small scope, but lock, unlock function due to more times for call, compromise it.
 */
void *thread_dec(void *arg)
{
	int i;
	for (i = 0; i < 50000000; i++) {
		pthread_mutex_lock(&mutex);
		num -= 1;
		pthread_mutex_unlock(&mutex);
	}
	return NULL;
}

