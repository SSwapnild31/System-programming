#include<stdio.h>
#include<sys/stat.h>
#include<sys/types.h>
#include<unistd.h>
#include<fcntl.h>

void main()
{
	int r;
	r = mkfifo("f1",0664);
	perror("mkfifo");	
	printf("r : %d\n",r);
	printf("Before..\n");
	
	int fd = open("f1",O_RDONLY);
	printf("waiting for data..\n");
	
	char s[20];
	read(fd,s,sizeof(s));
	printf("data : %s\n",s);
}
