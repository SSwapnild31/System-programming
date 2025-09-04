#include<stdio.h>
#include<pthread.h>

void *trd1(void *p)
{
	while(1)
		printf("pid : %d tid : %d\n",getpid(),pthread_self());
} 

void main()
{	
	pthread_t t1;
	
	pthread_create(&t1,0,trd1,0);
	
	while(1)	
		printf("pid : %d tid : %d\n",getpid(),pthread_self());
	
}
