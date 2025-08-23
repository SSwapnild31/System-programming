#include<stdio.h>
#include<pthread.h>
#include<unistd.h>

void *thread_t(void *p)
{
	printf("In thread join %s\n",(char*)p);
	sleep(5);
	pthread_exit(0);
}

int main()
{
	void *p;
	pthread_t t1;
	pthread_create(&t1,0,thread_t,"Hello");
	
	printf("In main thread before..\n");
	pthread_join(t1,&p);
	
	printf("In main thread after join %s\n",(char*)p);
	return 0;
}
