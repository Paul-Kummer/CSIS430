#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <unistd.h>

#define MAX_COUNT 20

void ChildProcess();
void ParentProcess();

int main()
{
	pid_t pid;
	pid = fork();

	if(pid==0)
	{
		ChildProcess();
	}

	else
	{
		ParentProcess();
	}

	return 0;
}

void ChildProcess()
{
	int i;

	for(i=1; i<=MAX_COUNT; i++)
	{
		printf("\tThis line is from child, value = %d\n", i);
	}

	printf("\t*** Child Process Complete ***\n");
}

void ParentProcess()
{
	int i;

	for(i=1; i<=MAX_COUNT; i++)
	{
		printf("\tThis line is from parent, value = %d\n", i);
	}

	printf("\t*** Parent Process Complete ***\n");
}