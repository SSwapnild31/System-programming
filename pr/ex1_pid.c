#include<stdio.h>
#include<unistd.h>

void main()
{
	if(fork()==0)
		printf("In child pid : %d \n",getpid());
	else
		printf("In child pid : %d \n",getpid());

}
