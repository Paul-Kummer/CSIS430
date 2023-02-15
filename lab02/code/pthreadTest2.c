//gcc pthreadTest2.c -0 pthreadTest2 -lpthread

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

int g = 0;

void *test_thread(void *vargp)
{
	int *myid = (int *)vargp;
	int s = 0;

	s++;
	++g;

	printf("Thread ID: %d, Static: %d, Global: %d\n", *myid, ++s, ++g);
}

int main()
{
	int i;
	pthread_t tid;

	for(i=0; i<3; i++)
	{
		pthread_create(&tid, NULL, test_thread, (void *)&tid);
	}

	pthread_exit(NULL);

	return 0;
}