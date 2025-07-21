#include<stdio.h>
#include<signal.h>
#include<unistd.h>

void my_isr(int n)
{
	printf("In isr n : %d pid : %d\n",n,getpid());
	signal(2,SIG_DFL);
}

void main()
{
	printf("pid : %d\n",getpid());
	signal(2,my_isr);
	printf("Done..\n");
	while(1);
}
