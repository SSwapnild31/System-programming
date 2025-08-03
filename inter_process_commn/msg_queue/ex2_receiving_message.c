#include<stdio.h>
#include<sys/types.h>
#include<sys/ipc.h>
#include<sys/msg.h>
#include<stdlib.h>

struct msgbuf
{
	long mtype;
	char s[20];
};

int main(int argc,char *argv[])
{
	if(argc!=2)
	{
		printf("usage : ./rcv msg\n");
		printf("usage : ./rcv 2\n");
		return 0;
	}
	
	int id = msgget(4,IPC_CREAT|0664);
	
	if(id<0)
	{
		perror("msgget");
		return 0;
	}
	
	struct msgbuf v;
	
	msgrcv(id,&v,sizeof(v),atoi(argv[1]),0);
	
	perror("msgrcv");
	
	printf("data : %s\n",v.s);
	return 0;
}
