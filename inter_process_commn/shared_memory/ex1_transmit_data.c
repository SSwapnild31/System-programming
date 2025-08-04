#include<stdio.h>
#include<sys/types.h>
#include<sys/shm.h>

int main()
{
	int id = shmget(4,50,IPC_CREAT|0664);
	if(id<0)
	{
		perror("shmget");
		return 0;
	}
	printf("id : %d\n",id);
	
	char *p;
	
	p = shmat(id,0,0);
	perror("shmat");
	
	printf("Enter data : ");
	scanf("%s",p);
	
	shmdt(p);
}
