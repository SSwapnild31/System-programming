#include<stdio.h>
#include<pthread.h>

void *trd1(void *p)
{
	while(1)
		printf("In thread %s\n",(char*)p);
} 

int main()
{	
	pthread_t t1;
	
	pthread_create(&t1,0,trd1,"Hello");
	
	pthread_exit(0);

	return 0;
}
