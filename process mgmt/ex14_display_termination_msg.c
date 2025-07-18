//used some predefined macros to print child is  terminated normally or abnormally

#include<stdio.h>
#include<unistd.h>
#include<sys/wait.h>

void main()
{
	if(fork()==0)
	{
		printf("In c pid : %d\n",getpid());
		sleep(30);
		printf("In c after sleep\n");
	}
	else
	{
		int r,s;
		printf("In c pid : %d\n",getpid());
		printf("Before wait ..\n");
		r = wait(&s);
		if(WIFEXITED(s))
			printf("child terminated normally %d\n",WEXITSTATUS(s));
		else if(WIFSIGNALED(s))
			printf("child terminated abnormally %d\n",WTERMSIG(s));
		while(1);
	}
}
