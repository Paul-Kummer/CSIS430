#include "types.h"
#include "stat.h"
#include "user.h"

int main(int argc, char *argv[])
{
	//int returnVal;

	if(argc > 1)
	{
		hello(argv[1]);
	}
	else
	{
		hello("Hello World");
	}

	exit();
}