#include<stdio.h>
#include<unistd.h>
#include<string.h>

void main()
{
	int p[2];
	pipe(p);
	perror("pipe");
	printf("p[0] : readend : %d\n",p[0]);
	printf("p[1] : writeend : %d\n",p[1]);
	printf("parent id : %d\n",getpid());
	if(fork()==0)
	{
		char s[10];
		read(p[0],s,sizeof(s));
		printf("\ndata received in pid : %d\n",getpid());
		printf("Data : %s\n",s);
	}
	else
	{
		char s[10];
		printf("\nEnter data : ");
		scanf("%s",s);
		write(p[1],s,strlen(s)+1);
		printf("data send from pid : %d\n",getpid());
	}
}
