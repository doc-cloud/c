
#include <stdio.h>
#include <stdlib.h>
#include <setjmp.h>

typedef struct node * Node;

Node head;

/* store jmp_buf structure of stack frame */
jmp_buf env;

struct node {
	int val;
	Node next;
};

int insert(int val)
{
	Node p, q;
	p = head;
	if(p != NULL) {
		while(p->next != NULL)
			p = p->next;	
	}
	q = (Node)malloc(sizeof(struct node));

	if(q == NULL)
		longjmp(env, 10);
	q->next = NULL;
	q->val = val;

	if(NULL == p) {
		head = q;
		return 1;	
	}
	p->next = q;
	return 1;
}

void print()
{
	Node p = head;
	while(p != NULL) {
		printf("%d\n", p->val);
		p = p->next;
	}
}

void destroy()
{
	Node p = head;
	while(p != NULL) {
		Node q;
		q = p;
		p = p->next;
		free(q);
	}
	head = NULL;
}

int main(void)
{
	Node p;
	int i;
	int res = -1;
	res = setjmp(env);
	if(res != 0)
		goto err;
	printf("insert\n");
	for(i = 1; i< 8; i++)
		insert(i);
	print();
	res = 0;
err:
	destroy();
	return res;
}

