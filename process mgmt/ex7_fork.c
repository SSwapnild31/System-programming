#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>

void main()
{
	printf("pid : %d\n",getpid());
	fork();
	printf("pid : %d\n",getpid());
	while(1);
}
