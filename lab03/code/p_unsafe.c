// File: p_unsafe.c
// gcc p_unsafe.c -o p_unsafe -lpthread 
// 
#include <stdio.h> 
#include <stdlib.h> 
#include <pthread.h> 
#include <unistd.h>

char s1[] = "abcdefg" ; 
char s2[] = "abc" ; 
char* c ;

void last_char(char* a, int i) 
{ 
  printf("last letter a is %s and i is %d\n", a, i) ; 
  sleep(i) ; 
  c = NULL ;
  sleep(i) ; 
  c = a ; 
  sleep(i) ; 
  while (*(c)) 
  {
	c++ ; 
	printf("%c\n", *(c-1)) ; 
  }
}

// This function will run concurrently. 
void *call_last_char(void *ptr) 
{ 
  last_char(s2, 2) ; 
} 

int main() 
{ 
  pthread_t t1 ; 
  int iret1 = pthread_create(&t1, NULL, call_last_char, NULL) ; 
  last_char(s1, 5) ; 
  sleep(10) ; 
  printf("Ended nicely this time\n") ; 
  exit(0) ; 
}