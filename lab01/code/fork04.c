#include <stdio.h>
#include <unistd.h>

void fork_ex()
{
	int x=1;
	int pid = fork();
	
	if (pid==0)
	{
		printf("Child x = %d\n", ++x);
	}
	else
	{
		printf("Parent x = %d\n", --x);
	}
}

int main()
{
	fork_ex();

	return 0;
}
