#include <stdio.h>
#include <unistd.h>

int main()
{
	int pid1 = fork();
	int pid2 = fork();
	
	printf("Hello World %d\n", pid1);
	printf("Hello World %d\n", pid2);
	
	return 0;
}
