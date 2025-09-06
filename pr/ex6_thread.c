#include<stdio.h>
#include<pthread.h>

void *thread(void *p)
{
	printf("In Thread %s\n",(char*)p);
	return "Hello";	
}

int main()
{
	void *p;
	pthread_t t1;

	pthread_create(&t1,0,thread,"Hello word");
	pthread_join(t1,&p);
	
	printf("In main, thread return value %s\n",(char *)p);
	return 0;
}
