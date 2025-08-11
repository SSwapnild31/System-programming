//setting semaphore value

#include<stdio.h>
#include<sys/sem.h>
#include<stdlib.h>

void main(int argc,char **argv)
{
	if(argc!=3)
	{
		printf("./get semnum value\n");
		return ;
	}
	
	int id = semget(4,5,IPC_CREAT|0664);
	if(id<0)
	{
		perror("semget");
		return ; 
	}
	
	printf("id : %d\n",id);
	
	semctl(id,atoi(argv[1]),SETVAL,atoi(argv[2]));
	perror("shmctl");
}
