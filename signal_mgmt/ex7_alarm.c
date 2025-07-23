#include<stdio.h>
#include<unistd.h>
#include<signal.h>

void my_isr(int n)
{
	printf("In isr n : %d pid : %d\n",n,getpid());
}

void main()
{
	int r ;
	printf("pid : %d\n",getpid());\
	signal(SIGALRM,my_isr);
	r = alarm(10);
	printf("1. r : %d\n",r);
	sleep(3);
	r = alarm(5);
	printf("2. r : %d\n",r);
	printf("Done..\n");
	while(1);
}
