#include<stdio.h>
#include <fcntl.h>

void main()
{
	//FILE *fp = fopen("data","r");
	//int fd = open("data",O_RDONLY);
	
	//FILE *fp = fopen("data","w");
	//int fd = open("data",O_WRONLY|O_TRUNC|O_CREAT,0664);
	
	//FILE *fp = fopen("data","a");
	//int fd = open("data",O_WRONLY|O_APPEND|O_CREAT,0664);
	
	int fd = open("data",O_RDONLY);

	if(fd<0)
	{
		perror("open");
		return ;
	}

	printf("fd : %d\n",fd);
}
