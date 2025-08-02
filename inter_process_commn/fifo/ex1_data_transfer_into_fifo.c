#include<stdio.h>
#include<string.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>

int main()
{
	int r;
	r = mkfifo("f1",0664);
	perror("mkfifo");
	printf("r : %d\n",r);
	printf("Before..\n");
	
	int fd = open("f1",O_WRONLY);
	printf("after..\n");
	
	char s[20];
	printf("Enter the data : ");
	scanf("%s",s);
	write(fd,s,strlen(s)+1);
	
	return 0;
}
