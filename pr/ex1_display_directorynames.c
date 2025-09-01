#include<stdio.h>
#include<dirent.h>

int main(int argc,char **argv)
{
	if(argc!=2)
	{
		printf("usage : ./a.out dirname/path\n");
		return 1;
	}
	
	DIR *dp = opendir(argv[1]);
	if(dp==0)
	{
		perror("opendir");
		return 1;
	}
	
	struct dirent *p;
	
	while(p=readdir(dp))
		if(p->d_name[0]!='.')
			printf("%s\n",p->d_name);
	return 0;
}
