#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<strings.h>

void main()
{
	int fd = open("data",O_RDONLY);
	if(fd<0)
	{
		perror("open");
		return ;
	}
	
	printf("fd : %d\n",fd);
	
	char s[10];
	int r;
	
	bzero(s,sizeof(s));
	r = read(fd,s,7);
		
	if(r<0)
	{
		perror("read");
		return ;
	}
	
	//s[r]='\0';
	
	printf("r : %d\n",r);
	printf("data : %s\n",s);
}
