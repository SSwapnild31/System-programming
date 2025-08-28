#include<stdio.h>
#include<unistd.h>
#include<string.h>

int main()
{
	int p[2];
	pipe(p);
	perror("pipe");
	
	if(fork()==0)
	{
		char s[10];
		printf("In c before read\n");
		read(p[0],s,sizeof(s));
		printf("In c data : %s\n",s);
	}
	else
	{
		char s[10];
		printf("In p enter data\n");
		scanf("%[^\n]",s);
		write(p[1],s,strlen(s)+1);
	}

	return 0;
}
