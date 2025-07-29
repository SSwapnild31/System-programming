#include<stdio.h>
#include<errno.h>
#include<unistd.h>
#include<fcntl.h>

void main()
{
	close(0);
	int fd = open("data",O_RDONLY);
	
	if(fd<0)
	{
		perror("data");
		return ;
	}
	
	int a[5];

	for(int i=0;i<5;i++)
		scanf("%d",&a[i]);

	for(int i=0;i<5;i++)
		printf("%d ",a[i]);
	printf("\n");
}
