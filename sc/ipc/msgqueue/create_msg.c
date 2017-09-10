
#include <sys/msg.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int qid;
	key_t key;
	key = 112;
	qid = msgget(key, IPC_CREAT | 0666);
	if (qid < 0) {
		perror("msgget");
		exit(1);
	}
	printf("created queue id : %d \n", qid);
	system("ipcs -q");
	exit(0);
}

