
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <pthread.h>

/* three task at same time */
#define MAX_ITEM 3

typedef struct job *Job;

struct job {
	pthread_t tid;
	Job next;
	int val;
};

pthread_mutex_t q_lock = PTHREAD_MUTEX_INITIALIZER;

int insert(Job head, int val, pthread_t tid)
{
	Job p, q;
	p = head;
	if (p != NULL) {
		while (p->next != NULL) {
			p = p->next;
		}
	}
	q = (Job) malloc(sizeof(struct job));
	if (q == NULL) {
		perror("fail to malloc");
		return -1;
	}
	q->next = NULL;
	q->val = val;
	/* set node owner, thread 1 */
	q->tid = tid;
	if (p == NULL) {
		head = q;
		return 0;
	}
	p->next = q;
	return 0;
}

void get_job(Job head, Job task, int *count, pthread_t tid)
{
	Job p, q;
	q = head;
	p = q->next;

	while (p != NULL) {
		/* find the task node belong to current thread */
		if (tid == p->tid) {
			q->next = p->next;
			/* pick off the node from original task queue */
			p->next = NULL;
			while (task->next != NULL)
				task = task->next;
			/* link to new current thread task queue */
			task->next = p;
			p = q->next;
			(*count)++;
		} else {
			q = p;
			p = p->next;
		}
	}

}

int free_job(Job head)
{
	Job p, q;
	for (p = head; p != NULL; p = p->next) {
		q = p;
		free(q);
	}
	return 0;
}

void print(Job head)
{
	Job p;
	for (p = head->next; p != NULL; p = p->next)
		printf("thread %u: %d\n", (unsigned int)p->tid, p->val);
}

/* read the data in list */
void *tfn7(void *arg)
{

	/* list node number fetched each time */
	int count;
	/* queue head belong to current thread */
	Job task;
	/* set head node, the node does not store effective info */
	task = (struct job *)malloc(sizeof(struct job));
	task->next = NULL;
	task->val = 0;
	task->tid = -1;
	pthread_t tid;
	/* get current tid, judge task is belong to current thread ? */
	tid = pthread_self();
	count = 0;
	while (count < MAX_ITEM)
		if (pthread_mutex_trylock(&q_lock) == 0) {
			get_job(arg, task, &count, tid);
			pthread_mutex_unlock(&q_lock);
		}
	print(task);
	if (free_job(task) == -1)
		exit(1);
	return (void *)0;
}

int main(void)
{
	Job item;
	pthread_t tid1, tid2;
	int i, err;
	item = (struct job *)malloc(sizeof(struct job));
	item->next = NULL;
	item->val = 0;
	item->tid = -1;
	/* create two thread, they will get different task node according to their own tid */
	if ((err = pthread_create(&tid1, NULL, tfn7, item)) == -1) {
		printf("fail to create thread %s\n", strerror(err));
		exit(0);
	}
	if ((err = pthread_create(&tid2, NULL, tfn7, item)) == -1) {
		printf("fail to create thread %s\n", strerror(err));
		exit(0);
	}

	/* set task node into task queue */
	printf("===the 1st put===\n");
	/* lock the task queue */
	pthread_mutex_lock(&q_lock);
	/* 1 for thread 1, 1 for thread 2 */
	for (i = 0; i < 2; i++) {
		if (insert(item, i, tid1) == -1)
			exit(1);
		if (insert(item, i + 1, tid2) == -1)
			exit(1);
	}
	if (insert(item, 10, tid1) == -1)
		exit(1);
	/* release lock, task queue contain 5 task node, 3 for thread 1, 2 for thread 2 */
	pthread_mutex_unlock(&q_lock);

	/*
	 * sleep, make sure thread can fetch task node, cannot do join here
	 * only two node belong to thread 2, thread will not exit before three node be fetch
	 * once do join, it will dead lock
	 */
	sleep(5);

	/* there is no task node in queue */
	printf("===the 2nd put===\n");

	pthread_mutex_lock(&q_lock);
	if (insert(item, 9, tid2) == -1)
		exit(1);
	pthread_mutex_unlock(&q_lock);

	/* can do join now */
	err = pthread_join(tid1, NULL);
	if (err != 0) {
		printf("can’t join thread %s\n", strerror(err));
		exit(1);
	}
	err = pthread_join(tid2, NULL);
	if (err != 0) {
		printf("can’t join thread %s\n", strerror(err));
		exit(1);
	}
	printf("main thread done\n");
	if (item->next == NULL)
		printf("No job in the queue\n");
	free(item);
	return 0;
}

