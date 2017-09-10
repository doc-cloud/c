
#include <sys/msg.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct msg {
	long msg_types;
	char msg_buf[511];
};

int main(void)
{
	int qid;
	int pid;
	int len;
	struct msg pmsg;
	qid = 65536;
	pmsg.msg_types = getpid();
	sprintf(pmsg.msg_buf, "hello!this is :%d\n", getpid());
	len = strlen(pmsg.msg_buf);
//	if ((qid = msgget(IPC_PRIVATE, IPC_CREAT | 0666)) < 0) {
//		perror("msgget");
//		exit(1);
//	}
	if ((msgsnd(qid, &pmsg, len, 0)) < 0) {
		perror("msgsn");
		exit(1);
	}
	printf("successfully send a message to the queue: %d \n", qid);
	exit(0);
}

