#include<stdio.h>
#include<sys/stat.h>

void main(int argc,char **argv)
{
	if(argc!=3)
	{
		printf("Usage : ./a.out fname1 fname2\n ");
		return ;
	}
	
	struct stat v,v1;
	
	if(stat(argv[1],&v)<0)
	{
		perror("stat");
		return ;
	}

	if(stat(argv[2],&v1)<0)
	{
		perror("stat");
		return ;
	}
	
	if(v.st_ino == v1.st_ino)
	{
		lstat(argv[1],&v);
		lstat(argv[2],&v1);
		if(v.st_ino == v1.st_ino)
			printf("Hard link\n");
		else
			printf("Soft link\n");
	}
	else
		printf("No link..!\n");
}
