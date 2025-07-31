#include"header.h"
#define size 100

int main(int argc,char **argv)
{
	int fd, len;
	
	fd = socket(AF_INET,SOCK_STREAM,0);
	
	if(fd<0)
	{
		perror("socket");
		return 0;
	}
	perror("socket");
	
	struct sockaddr_in server_id;
	
	server_id.sin_family = AF_INET;
	server_id.sin_port   = htons(atoi(argv[1]));
	server_id.sin_addr.s_addr = inet_addr(argv[2]);
	
	len = sizeof(server_id);
	
	if(connect(fd,(struct sockaddr*)&server_id,len)<0)
	{
		perror("connect");
		return 0;
	}
	perror("connect");
	printf("---------------------------\n");
	char s[size];
	while(1)
	{
		printf("send msg	: ");
		scanf(" %[^\n]",s);
		write(fd,s,strlen(s)+1);
		if(strcmp(s,"bye")==0)
			break;
		read(fd,s,sizeof(s));
		printf("server replay	: %s\n",s);
	}
	printf("---------------------------\n");
	
	close(fd);
	
	return 0;
}
