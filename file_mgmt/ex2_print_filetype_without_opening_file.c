#include<stdio.h>
#include<sys/types.h>
#include<sys/stat.h>

void main(int argc,char **argv)
{
	if(argc!=2)
	{
		printf("Usage : ./a.out filename\n");
		return ;
	}
	
	struct stat v;
	
	if(stat(argv[1],&v)<0)
	{
		perror("stat");
		return ;
	}
	
	if(S_ISREG(v.st_mode))
		printf("Regular file\n");
	else if(S_ISDIR(v.st_mode))
		printf("Directory file\n");
}
