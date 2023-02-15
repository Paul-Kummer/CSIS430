#include "types.h"
#include "stat.h"
#include "user.h"

int main(void)
{
	char *strOne = "CSIS430's Xv6 Lab Session";
	char *strTwo = "Calling hello() with an argument\n";

	for(int x=0; x<5; x++)
	{
		hello(strOne);
		hello(strTwo);
	}
	
	exit();
}