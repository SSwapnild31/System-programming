#include<stdio.h>
#include<unistd.h>
#include<string.h>


void convert(char *p)
{
	for(int i=0;p[i];i++)
	{
		if(p[i]>='a' && p[i]<='z')
			p[i]=p[i]-32;
	}
}

int main()
{
	int p[2],q[2];
	
	pipe(p);
	pipe(q);
	printf("parent id : %d\n",getpid());
	
	if(fork()==0)
	{
		char s[10];
		printf("Before read in c, pid : %d\n",getpid());
		read(p[0],s,sizeof(s));
		printf("Received data in c : %s\n",s);
		convert(s);
		write(q[1],s,strlen(s)+1);
	}
	else
	{
		char s[10];
		printf("\nEnter data, p in pid : %d\n",getpid());
		scanf("%s",s);
		write(p[1],s,strlen(s)+1);
		read(q[0],s,sizeof(s));
		printf("converted data in p : %s\n",s);
	}
	
	return 0;
}
