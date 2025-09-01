#include<stdio.h>
#include<dirent.h>
#include<string.h>
#include<unistd.h>
#include<fcntl.h>

int main(int argc,char **argv)
{
	if(argc!=3)
	{
		printf("usage : ./a.out filename dirname/path\n");
		return 1;
	}
	
	DIR *dp = opendir(argv[2]);
	if(dp==0)
	{
		perror("opendir");
		return 1;
	}
	
	struct dirent *p;
	int fp = open(argv[1],O_WRONLY|O_TRUNC|O_CREAT,0664);
	char ch = '\n';
	while(p=readdir(dp))
	{
		if(p->d_name[0]!='.')
		{
			write(fp,p->d_name,strlen(p->d_name));
			write(fp,&ch,1);
		}
	}
	
	return 0;
}
