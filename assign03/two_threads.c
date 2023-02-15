//Paul Kummer
//cx3645kg
//Assign03
//CSIS430

//gcc two_threads.c -o two_threads -lpthread

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>


long double fact(double num)
{
	double negCheckedNum = num<0?num*-1:num;
	long double result = 1;

	for(double x=1; x<=negCheckedNum; x++)
	{
		result *= x;
	}

	result = num<0?result*-1:result;

	return result;
}


double pow(double num, double power)
{
	//set result to one if the power is zero
	double result = power==0.0?1:num;

	for(int x=1; x<power; x++)
	{
		result *= num;
	}

	return result;
}


void* factorial(void* arg)
{
	printf("\n\t[ Factorial ]\n");

	//long double facResult;
	//must change the void pointer to an integer pointer. Then the pointer is dereferenced
	double factLength = *((double*)arg); 

	printf("Factorial Result: %Lf\n\n", fact(factLength));
}


void* approx_pi(void* arg)
{
	printf("\n\t[ Pi Approximation ]\n");
	
	//must change the void pointer to an integer pointer. Then the pointer is dereferenced
	double iterations = *((double*)arg);
	iterations = iterations>0?iterations:iterations*-1; //ensure it is positive
	long double pi = 0.0;
	
	//Gregory–Leibniz series
	//https://en.wikipedia.org/wiki/Approximations_of_%CF%80
	for(double k=0; k<iterations; k++)
	{
		pi += (pow(-1,k))/((2.0*k)+1);
	}
	pi *= 4.0;

	printf("Pi Result: %0.40Lf\n\n", pi);
}


int main(int argc, char *argv[])
{
	pthread_t factThread;
	pthread_t piThread;
	double n =  (double)atoi(argv[1]); //argument for factorial
	double m = (double)atoi(argv[2]);	//argument for pi approx

	//Create Threads
	pthread_create(&factThread, NULL, factorial, (void*) &n);
	pthread_create(&piThread, NULL, approx_pi, (void*) &m);

	//Wait for Threads to Finish
	pthread_join(factThread, NULL);
	pthread_join(piThread, NULL);

	return 0;
}