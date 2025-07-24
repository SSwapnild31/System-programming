#include<stdio.h>
#include<unistd.h>
#include<signal.h>
#include<sys/wait.h>

void my_isr(int n)
{
	printf("In isr n : %d pid : %d\n",n,getpid());
	wait(0);
}

void main()
{
	if(fork()==0)
	{
		printf("In c pid : %d\n",getpid());
		sleep(15);
		printf("c done\n");
	}
	else
	{
		printf("In p pid : %d\n",getpid());
		signal(17,my_isr);
		while(1);
	}
}
