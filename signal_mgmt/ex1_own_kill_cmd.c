#include<stdio.h>
#include<stdlib.h>
#include<signal.h>
#include<sys/types.h>

void main(int argc,char **argv)
{
	if(argc!=3)
	{
		printf("Uasge : ./my_kill signum pid\n");
		return ;
	}
	
	kill(atoi(argv[2]),atoi(argv[1]));
	perror("kill");
}
