#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>

int main(int argc,char **argv)
{
	close(1);	
	int fd = open(argv[1],O_WRONLY|O_CREAT|O_TRUNC,0664);
	
	if(fd < 0)
	{
		perror("open");
		return 1; 
	}
	
	int a[5] = {10,20,30,40,50};
	
	for(int i=0;i<5;i++)
		printf("%d ",a[i]);
	
	return 0;
}
