#include<stdio.h>
#include<dirent.h>

void main(int argc,char **argv)
{
	if(argc!=2)
	{
		printf("Usage : ./a.out dirname or path\n");
		return ;
	}

	DIR *dp = opendir(argv[1]);
	
	if(dp==0)
	{
		perror("opendir");
		return ;
	}
	
	struct dirent *p;
	
	while(p = readdir(dp))
	{
		if(p->d_name[0]!='.')
			printf("%s\n",p->d_name);
	}
}
