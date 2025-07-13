#include<stdio.h>
#include<unistd.h>
void main()
{
	printf("pid : %d\n",getpid());
	sleep(5);
	printf("after sleep\n");
}
