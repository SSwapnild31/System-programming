//TCP server side program

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

	int fd, len, nfd;
	char s[size];

	fd = socket(AF_INET,SOCK_STREAM,0);
	
	if(fd<0)
	{
		perror("socket");
		return 0;
	}

	perror("socket");
	
	struct sockaddr_in serv_id, client_id; 
	
	serv_id.sin_family = AF_INET;
	serv_id.sin_port = htons(atoi(argv[1]));
	serv_id.sin_addr.s_addr = inet_addr(argv[2]);
	
	len = sizeof(serv_id);
	
	if(bind(fd,(struct sockaddr*)&serv_id,len)<0)
	{
		perror("bind");
		return 0;
	}

	perror("bind");
	
	if(listen(fd,5)<0)
	{
		perror("listen");
		return 0;
	}
	perror("listen");
	
	while(1)
	{
		printf("\nwaiting for client\n");
		nfd = accept(fd,(struct sockaddr*)&client_id,&len);

		if(fd<0)
		{
			perror("accept");
			return 0;
		}
		
		printf("\n---------------------------\n");
		
		if(fork()==0)
		{
			printf("\033[32mclient connected\nip address : %s\033[0m\n",inet_ntoa(client_id.sin_addr));

			printf("\n---------------------------\n");

			while(1)
			{
				read(nfd,s,sizeof(s));
				printf("client msg	: %s\n",s);
				if(strcmp(s,"bye")==0)
					break;
				convert(s);
				//printf("send replay	: ");
				//scanf(" %[^\n]",s);
				write(nfd,s,strlen(s)+1);
			}	
			printf("\n---------------------------\n");
		}
	}

	close(nfd);
	close(fd);
	
	return 0;
}
