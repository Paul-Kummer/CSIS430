// File: p_mutex_solution.c
// gcc p_mutex_solution.c -o p_mutex_soltion -l pthread
//
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

pthread_mutex_t mutex1 = PTHREAD_MUTEX_INITIALIZER;

void print_critical_region(char* a, char* b) 
{
	pthread_mutex_lock(&mutex1);
	printf("1: %s\n", a);
	//sleep(1);
	printf("2: %s\n", b);
	pthread_mutex_unlock(&mutex1);
}

// These two functions will run concurrently.
void* foo_A(void *ptr) 
{
	print_critical_region("I am", " in foo_A");
}

void* foo_B(void *ptr) 
{
	print_critical_region("I am", " in foo_B");
}

int main() 
{
	pthread_t t1, t2;
	pthread_mutex_init(&mutex1, NULL);

	int iret1 = pthread_create(&t1, NULL, foo_A, NULL);
	int iret2 = pthread_create(&t2, NULL, foo_B, NULL);

	while(1){}

	return 0;
}
