#include<stdio.h>
#include<unistd.h>
#include<sys/wait.h>

int main()
{
	int p[2];
	pipe(p);
	
	if(fork()==0)
	{
		close(p[0]);
		dup2(p[1],1);
		execl("ps","ps","-e",NULL);
	}
	else
	{
		if(fork()==0)
		{
			close(p[1]);
			dup2(p[0],0);
			execl("grep","grep","pts/0",NULL);
		}
		else
		{
			close(p[0]);
			close(p[1]);
			wait(0);
			wait(0);
		}
	}
	return 0;
}
