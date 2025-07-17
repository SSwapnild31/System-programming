#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>

void main()
{
	int i=10;
	if(vfork()==0)
	{
		i=200;
		printf("In c i : %d\n",i);
		sleep(10);
		exit(0);
	}
	else
	{
		sleep(15);
		printf("In p i : %d\n",i);
	}
}

/*
o/p : 		In c i : 200
		In p i : 200
*/
