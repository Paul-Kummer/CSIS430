#include <stdio.h>
#include <unistd.h>
#include <string.h>

#define MAX_COUNT 20
#define BUF_SIZE 100

int main()
{
	pid_t pid;
	int i;
	char buf[BUF_SIZE];
	
	fork();
	pid = getpid();
	
	for(i = 1; i<=MAX_COUNT; i++)
	{
			sprintf(buf, "this line is from pid %d, value = %d\n", pid, i);
			write(1, buf, strlen(buf));
	}
	
	return 0;
}
