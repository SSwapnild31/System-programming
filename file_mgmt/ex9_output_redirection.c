#include<stdio.h>
#include<errno.h>
#include<fcntl.h>
#include<unistd.h>
void main()
{
	close(1);
	int fd = open("data",O_WRONLY|O_CREAT|O_TRUNC,0664);
	
	if(fd<0)
	{
		perror("open");
		return ;
	}
	
	int a[5]={10,20,30,40,50};
	
	for(int i=0;i<5;i++)
		printf("%d ",a[i]);
}
