#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/ipc.h>
#include<sys/sem.h>

int main()
{
	int id = semget(4,5,IPC_CREAT|0664);
	if(id<0)
	{
		perror("semget");
		return 0;
	}
	
	int fd = open("data",O_WRONLY|O_APPEND|O_CREAT,0664);
	if(fd<0)
	{
		perror("open");
		return 0;
	}
	
	struct sembuf v;
	
	v.sem_num = 2;
	v.sem_op = 0;
	v.sem_flg = 0;
	
	printf("Before..!\n");
	
	semop(id,&v,1);
	semctl(id,2,SETVAL,1);
	
	printf("After..\n");
	
	for(char ch='A';ch<='Z';ch++)
	{
		write(fd,&ch,1);
		sleep(1);
	}
	
	semctl(id,2,SETVAL,0);
	printf("Done.\n");
	
	return 0;
}
