//file: p_mutex_lock.c
// gcc p_mutex_lock.c -o p_mutex_lock -l pthread

#include <stdio.h> 
#include <stdlib.h> 
#include <pthread.h> 
#include <unistd.h>

pthread_mutex_t mutex1 = PTHREAD_MUTEX_INITIALIZER ; 
pthread_t tid[2];
int counter;

void *trythis(void* arg)
{
	unsigned long i = 0;
	pthread_mutex_lock(&mutex1);
	counter += 1;
	printf("\n[ Job %d has started ]\n", counter);
	for (i=0; i < 10; i++)
	{
		printf("\n\tJob %d is computing\n", counter);
	}
	printf("\n*** Job %d is finished ***\n", counter);
	pthread_mutex_unlock(&mutex1);
	
	return NULL;
}

int main(void)
{
	int i =0;
	int error;
	pthread_mutex_init(&mutex1, NULL);
	
	while(i<2)
	{
		pthread_create(&(tid[i]),NULL, &trythis, NULL);
		i++;
	}
	
	pthread_join(tid[0], NULL);
	pthread_join(tid[1], NULL);
}