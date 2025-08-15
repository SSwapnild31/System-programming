#include<stdio.h>
#include<sys/types.h>
#include<sys/ipc.h>
#include<sys/sem.h>
#include<stdlib.h>
#include<unistd.h>

int main(int argc,char **argv)
{
	if(argc!=2)
	{
		printf("usage : ./a.out semop(>0,0,<0)\n");
		return 0;
	}
	
	int id = semget(4,5,IPC_CREAT|0664);
	
	if(id<0)
	{
		perror("semget");
		return 0;
	}
	
	struct sembuf v;
	
	v.sem_num = 2;
	v.sem_op  = atoi(argv[1]);
	v.sem_flg = SEM_UNDO;
	
	printf("Before..\n");
	
	semop(id,&v,1);
	
	printf("After..\n");
	
	sleep(15);
	
	printf("Done..\n");
	
	return 0;
}
