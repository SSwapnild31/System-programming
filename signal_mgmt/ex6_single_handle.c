#include<stdio.h>
#include<unistd.h>
#include<signal.h>

void my_isr(int n)
{
	static int c;
	printf("In isr n : %d pid : %d\n",n,getpid());
	c++;
	if(c==3)
		signal(2,SIG_DFL);
}

void main()
{
	printf("pid : %d\n",getpid());\
	signal(2,my_isr);
	printf("Done..\n");
	while(1);
}
