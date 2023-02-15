// File: p_mutex.c
// gcc p_mutex.c -o p_mutex -lpthread 
// 
#include <stdio.h> 
#include <stdlib.h> 
#include <pthread.h> 
#include <unistd.h> 

pthread_mutex_t mutex1 = PTHREAD_MUTEX_INITIALIZER ; 

void print_critical_region(char* a, char* b) 
{ 
  pthread_mutex_lock(&mutex1);
  printf("1: %s\n", a) ; 
  sleep(1); 
  printf("2: %s\n", b) ; 
  pthread_mutex_unlock(&mutex1);
} 

// These two functions will run concurrently. 
void* print_i(void *ptr) 
{ 
  print_critical_region("I am", " in i") ; 
} 
void* print_j(void *ptr) 
{ 
  print_critical_region("I am", " in j") ; 
} 

int main() 
{ 
  pthread_t t1, t2 ; 
  pthread_mutex_init(&mutex1, NULL);
  int iret1 = pthread_create(&t1, NULL, print_i, NULL) ; 
  int iret2 = pthread_create(&t2, NULL, print_j, NULL) ; 
  while(1)
  {} 
  exit(0) ; 
} 