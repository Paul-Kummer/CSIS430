#include <stdio.h>
#include <unistd.h>

void fork_ex()
{
	int pid = fork();
	if (pid==0)
	{
		printf("Hello from child %d\n", pid);
	}
	else
	{
		printf("hello from parent %d\n", pid);
	}
}

int main()
{
	//for(int x=0; x<5; x++)
	//{
		fork_ex();
	//}
	return 0;
}
