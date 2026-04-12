#include<stdio.h>
#include<unistd.h>

int main()
{	
	if(fork() == 0){
		printf("child id : %d\n",getpid());
		printf("child parent id : %d\n",getppid());
	}
	else{
		printf("parent id : %d\n",getpid());
		printf("parent parent id : %d\n",getppid());
	}
}
