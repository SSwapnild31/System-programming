//getting semaphore value

#include<stdio.h>
#include<sys/sem.h>
#include<stdlib.h>

void main(int argc,char **argv)
{
	if(argc!=2)
	{
		printf("./get semnum\n");
		return ;
	}
	
	int id = semget(4,5,IPC_CREAT|0664);
	if(id<0)
	{
		perror("semget");
		return ; 
	}
	
	printf("id : %d\n",id);
	
	int r = semctl(id,atoi(argv[1]),GETVAL);
	
	if(r<0)
	{
		perror("shmctl");
		return ;
	}
	printf("r : %d\n",r);
}
