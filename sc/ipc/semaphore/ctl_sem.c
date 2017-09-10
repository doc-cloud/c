#include <sys/sem.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int sem_id;
	int nsems = 1;
	int flags = 0666;
	sem_id = semget(IPC_PRIVATE, nsems, flags);
	if (sem_id < 0) {
		perror("semget");
		exit(1);
	}
	printf("successfully created a semaphore: %d \n", sem_id);
	system("ipcs -s");
	if ((semctl(sem_id, 0, IPC_RMID)) < 0) {
		perror("semctl");
		exit(1);
	} else {
		printf("semaphore removed \n");
		system("ipcs -s ");
	}
	exit(0);
}
