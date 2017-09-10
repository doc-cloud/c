#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

/* global variable, in data segment */
int global;

int main()
{
	pid_t pid;
	/* local variable, in stack */
	int stack = 1;
	int * heap;
	/* allocate memory, in heap */
	heap = (int *)malloc(sizeof(int));

	*heap = 2;
	pid = fork();
	if (pid < 0) {
		printf("fail to fork\n");
		exit(1);	
	} else if (0 == pid) {
		global++;
		stack++;
		(*heap)++;
		printf("the child, data : %d, stack : %d, heap : %d\n", global, stack, *heap);
		exit(0);
	}
	sleep(2);
	printf("the parent, data : %d, stack : %d, heap : %d\n", global, stack, *heap);
	return 0;
}
