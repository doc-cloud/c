#include <stdio.h>
#include <unistd.h>

#include <pthread.h>
#include <stdio.h>

pthread_t tid;

volatile int a = 2;
volatile int *ptr = &a;

pthread_mutex_t mutex;

int
square(volatile int * ptr)
{
#ifdef DEBUG_VOLATILE
 sleep(3);
 return *ptr * *ptr;
#else
 int a = *ptr;
 sleep(3);
 return a * a;
#endif
}

void *hacker()
{
 printf("haha, I am a hacker\n");
 pthread_mutex_lock(&mutex);
 ++*ptr;
 pthread_mutex_unlock(&mutex);
 sleep(1);
 printf("I changed the memory asynchronously!\n");
 pthread_exit(NULL);
}

void
main()
{
 //volatile int a = 2;
 //volatile int *ptr = &a;

 pthread_mutex_init(&mutex, NULL);
 pthread_create(&tid, NULL, hacker, NULL);
 
 printf("%d\n", square(ptr));

 pthread_join(tid, NULL);
}
