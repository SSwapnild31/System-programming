#include<stdio.h>
#include<sys/shm.h>

#define SHM_KEY 41
#define SHM_SIZE 4096

int main(void)
{
	int id = shmget(SHM_KEY, SHM_SIZE, IPC_CREAT|0664);
	
	//If key is private then accsssible only to related process.
	//int id = shmget(IPC_PRIVATE,50,IPC_CREAT|0664);
	
	if(id < 0){
		perror("shmget");
		return 1;
	}
	printf("shmid: %d\n",id);

	void *shm = shmat(id, NULL, 0);
	if(shm == (void*) -1){
		perror("shmat");
		return 1;
	}
	perror("shmat");

	printf("Enter data: ");
	scanf("%s",(char*)shm);

	return 0;
}
