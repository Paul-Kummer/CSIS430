// File print_num.c
// gcc print_num.c -o print_num -l pthread

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

int i; //global variable to share data

//This function will run concurrently.
void *print_num(void *ptr)
{
	while(1)
	{
		sleep(1);
		printf("While in print_num: %d\n", i);
	}
}

int main()
{
	pthread_t t1;
	i = 1;
	int iret1 = pthread_create(&t1, NULL, print_num, NULL);
	while(1)
	{
		sleep(4);
		printf("While in main: %d\n", i);
		i++;
	}
	exit(0);
}