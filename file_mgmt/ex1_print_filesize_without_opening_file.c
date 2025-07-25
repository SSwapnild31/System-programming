#include<stdio.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<unistd.h>

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

	printf("File size : %ld\n",v.st_size);
	printf("Inode : %lu\n",v.st_ino);
}
