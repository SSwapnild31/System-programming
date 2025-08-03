#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/ipc.h>
#include<sys/msg.h>
#include<stdlib.h>
#include<string.h>

struct msgbuf
{
	long mtype;
	char s[20];
};

int main(int argc,char *argv[])
{
	if(argc!=3)
	{
		printf("usage : ./snd mtype msg\n");
		printf("Ex    : ./snd   2   hello\n");
		return 0;
	}
	
	int id = msgget(4,IPC_CREAT|0644);
	
	if(id<0)
	{
		perror("msgget");
		return 0;
	}
	
	struct msgbuf v;
	v.mtype = atoi(argv[1]);
	strcpy(v.s,argv[2]);
	
	msgsnd(id,&v,strlen(v.s)+1,0);
	perror("msgsnd");
	
	return 0;
}
