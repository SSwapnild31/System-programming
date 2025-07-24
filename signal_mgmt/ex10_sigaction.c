#include<stdio.h>
#include<unistd.h>
#include<signal.h>

void my_isr(int n)
{
	printf("In isr n : %d pid : %d\n",n, getpid());
	while(1);
}

void main()
{
	if(fork()==0)
	{
		printf("In c pid : %d\n",getpid());
		while(1);
	}
	else
	{
		printf("In p pid : %d\n",getpid());
		//signal(17,my_isr);
		struct sigaction v;
		v.sa_handler = my_isr;
		sigemptyset(&v.sa_mask);
		v.sa_flags = SA_NOCLDSTOP|SA_NOCLDWAIT;
		sigaction(17,&v,0);
		while(1);
	}
}
