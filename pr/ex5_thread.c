#include<stdio.h>
#include<pthread.h>

void *thread(void *p)
{
	printf("In Thread\n");
}

int main()
{
	pthread_t t1;

	pthread_create(&t1,0,thread,"Hello word");
	pthread_exit(0);
	
	return 0;
}
