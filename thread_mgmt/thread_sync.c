#include<stdio.h>
#include<pthread.h>
#include<unistd.h>

pthread_mutex_t m1;
pthread_t t1, t2;

void *thread1(void *arg){
	char ch = 'a';

	for(int i=0;i<26;i++){
		pthread_mutex_lock(&m1);
		printf("%c",ch++);
		fflush(stdout);
		sleep(1);
		pthread_mutex_unlock(&m1);
	}
	pthread_exit(0);
}

void *thread2(void *arg){
	char ch = 'A';
	
	for(int i=0;i<26;i++){
		pthread_mutex_lock(&m1);
		printf("%c",ch++);
		fflush(stdout);
		sleep(1);
		pthread_mutex_unlock(&m1);
	}
	pthread_exit(0);
}

void mutex_init(void){
	pthread_mutex_init(&m1, NULL);
}

int main()
{
	mutex_init();

	pthread_create(&t1, NULL, thread1, NULL);
	pthread_create(&t2, NULL, thread2, NULL);
	
	pthread_exit(0);
	
	return 0;
}
