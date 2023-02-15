#include "types.h"
#include "stat.h"
#include "user.h"
#include "fcntl.h"

int main(int argc, char* argv[])
{
	int n;
	int workLoad = (1000 * 1000 * 1000);
	
	int k; //loop counter
  	int id = 0; //process id
	double x = 0;
	double z = 0;
	double d = 1;

	if(argc <2)
	{
		n = 1;
	}
	else
	{
		n = atoi(argv[1]);
	}

	if(n < 0 || n > 20)
	{
		n = 2;
	}



	for(k = 0; k < n; k++)
	{
		id = fork();

		//sti();

		if(id < 0)
		{
			printf(1,"%d failed in fork! \n", getpid());
		}

		else if(id == 0)
		{
			printf(1, "Child %d created \n", id);

			for(z = 0; z < workLoad; z += d)
			{
				x = x + 3.14 * 200.19;
			}

			break;
		}

		else
		{
			printf(1, "Parent %d creating child %d\n", getpid(), id);

			wait();
		}
	}

	//myfork(n, workLoad);

	exit();
}