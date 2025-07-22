#include<stdio.h>
#include<unistd.h>
#include<signal.h>

void my_isr(int n)
{
	printf("In isr n : %d pid : %d\n",n,getpid());
	alarm(1);
}

void main()
{
	printf("pid : %d\n",getpid());
	signal(SIGALRM,my_isr);
	alarm(10);
	printf("Done..\n");
	while(1);
}
