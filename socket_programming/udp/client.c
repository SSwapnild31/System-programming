#include"header.h"
#define size 100

int main(int argc,char **argv)
{
	if(argc!=3)
	{
		printf("usage : ./client portno ipaddr\n");
		return 0;
	}
	
	int fd = socket(AF_INET,SOCK_DGRAM,0);
	
	if(fd<0)
	{
		perror("socket");
		return 0;
	}
	perror("socket");
	
	struct sockaddr_in server_id;
	
	server_id.sin_family = AF_INET;
	server_id.sin_port = htons(atoi(argv[1]));
	server_id.sin_addr.s_addr = inet_addr(argv[2]);
	
	int len = sizeof(server_id);
	char s[size];
	while(1)
	{
		printf("Enter msg	: ");
		scanf(" %[^\n]",s);

		sendto(fd,s,strlen(s)+1,0,(struct sockaddr*)&server_id,len);

		if(strcmp(s,"bye")==0)
			break;

		recvfrom(fd,s,sizeof(s),0,(struct sockaddr*)&server_id,&len);
		
		printf("server reply 	: %s\n",s);
	}
	close(fd);
}
