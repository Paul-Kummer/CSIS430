#include <stdio.h>
#include <sys/wait.h>
#include <unistd.h>

int main()
{
	pid_t id1 = fork();
	pid_t id2 = fork();

	if(id1 > 0 && id2 > 0)
	{
		wait(NULL);

		printf("Parent Terminated\n");
	}

	else if (id1 == 0 && id2 > 0)
	{
		//sleep(2);
		wait(NULL);

		printf("1st Child Terminated\n");
	}

	else if (id1 > 0 && id2 == 0)
	{
		//sleep(1);

		printf("2nd Child Terminated\n");
	}
	
	else
	{
		printf("Grand Child Terminated\n");
	}

	return 0;
}