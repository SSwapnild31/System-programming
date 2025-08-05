#include"header.h"
#define size 100

void convert(char *p)
{
	while(*p)
	{
		if(*p>='a' && *p<='z')
			*p = *p - 32;
		else if(*p>='A' && *p<='Z')
			*p = *p + 32;
		p++;
	}
}

int main(int argc,char **argv)
{
	if(argc!=3)
	{
		printf("usage : ./server portno ipaddr\n");
		return 0;
	}
	
	int fd = socket(AF_INET,SOCK_DGRAM,0);
	
	if(fd<0)
	{
		perror("socket");
		return 0;
	}
	perror("socket");
	
	struct sockaddr_in socket_id,client_id;
	
	socket_id.sin_family = AF_INET;
	socket_id.sin_port = htons(atoi(argv[1]));
	socket_id.sin_addr.s_addr = inet_addr(argv[2]);
	
	int len = sizeof(socket_id);
	
	if(bind(fd,(struct sockaddr*)&socket_id,len)<0)
	{
		perror("bind");
		return 0;
	}
	perror("bind");
	
	char s[size];
	
	recvfrom(fd,s,sizeof(s),0,(struct sockaddr*)&client_id,&len);
	
	printf("client msg : %s\n",s);
	convert(s);
	
	sendto(fd,s,strlen(s)+1,0,(struct sockaddr*)&client_id,len);
	return 0;
}
