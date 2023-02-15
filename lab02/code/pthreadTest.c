//gcc pthreadTest.c -0 pthreadTest -lpthread

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

int test_thread(void *varg)
{
	sleep(5);
	printf("Hello Thread \n");

	return 0;
}

int main()
{
	pthread_t thread_id;

	printf("Before Thread\n");

	pthread_create(&thread_id, NULL, test_thread, NULL);
	pthread_join(thread_id, NULL);

	printf("After Thread\n");

	return 0;
}