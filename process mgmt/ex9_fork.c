#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>

void main()
{
	printf("pid : %d\n",getpid());
	if(fork()==0)
	{
		printf("In c pid : %d\n",getpid());
	}
	else
	{
		printf("I p pid : %d\n",getpid());
	}
	while(1);
}
