// File print_random.c
// gcc print_random.c -o print_random -l pthread

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

//This func will run concurrently
void *print_random(void *ptr)
{
	printf("a\n");
	printf("b\n");
}

int main()
{
	pthread_t t1;
	int i = 1;
	int iret1 = pthread_create(&t1, NULL, print_random, NULL);
	//pthread_join(t1, NULL);
	printf("c\n");
}