#include<stdio.h>
#include<sys/shm.h>

#define SHM_KEY 41
#define SHM_SIZE 4096

int main()
{
	int id = shmget(SHM_KEY, SHM_SIZE, 0664);
	if(id < 0){
		perror("shmget");
		return 1;
	}
	printf("shmid: %d\n", id);

	void *shm = shmat(id, NULL, 0);
	if(shm == (void*) -1){
		perror("shmat");
		return 1;
	}
	perror("shmat");

	printf("Read data: %s\n",(char*)shm);

	return 0;
}
