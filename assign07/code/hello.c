#include "types.h"
#include "stat.h"
#include "user.h"

int main(int argc, char *argv[])
{
	if(argc > 1)
	{
		for(int x=1; x<argc; x++)
		{
			hello(argv[x]);
			hello(" ");
		}
		hello("\n");
	}
	else
	{
		hello("Hello World\n");
	}

	exit();
}