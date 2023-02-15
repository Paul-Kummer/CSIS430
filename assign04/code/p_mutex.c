// File: p_mutex.c
// gcc p_mutex.c -o p_mutex -lpthread
//
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

void print_critical_region(char* a, char* b) {
  printf("1: %s\n", a) ;
  sleep(1);
  printf("2: %s\n", b) ;
}

// These two functions will run concurrently.
void* foo_A(void *ptr) {
  print_critical_region("I am", " in foo_A") ;
}

void* foo_B(void *ptr) {
  print_critical_region("I am", " in foo_B") ;
}

int main() {
  pthread_t t1, t2 ;

  int iret1 = pthread_create(&t1, NULL, foo_A, NULL) ;
  int iret2 = pthread_create(&t2, NULL, foo_B, NULL) ;

  while(1){}

  exit(0) ;
}
