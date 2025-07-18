#include<stdio.h>
#include<unistd.h>
#include<sys/wait.h>

void main()
{
	if(fork()==0)
	{
		printf("In c pid : %d\n",getpid());
		sleep(15);
		printf("In c after sleep\n");
	}
	else
	{
		int r,s;
		printf("In p pid : %d\n",getpid());
		printf("Before wait..\n");
		r = wait(&s);
		printf("After wait r : %d s : %d\n",r,s);
		while(1);
	}
}
