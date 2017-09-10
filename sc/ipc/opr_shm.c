
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <stdlib.h>
#include <stdio.h>

int main(int argc, char *argv[])
{
	int shm_id;
	char *shm_buf;
	if (argc != 2) {
		printf("USAGE: atshm <identifier>");
		exit(1);
	}
	shm_id = atoi(argv[1]);
	/* import share memory section, kernel choose the position */
	if ((shm_buf = shmat(shm_id, 0, 0)) < (char *)0) {
		perror("shmat");
		exit(1);
	}
	/* output import position */
	printf(" segment attached at %p\n", shm_buf);
	system("ipcs -m");
	sleep(3);
	/* separate with imported shared memory */
	if ((shmdt(shm_buf)) < 0) {
		perror("shmdt");
		exit(1);
	}
	printf("segment detached \n");
	system("ipcs -m ");
	exit(0);
}

