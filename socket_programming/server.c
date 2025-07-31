#include"header.h"

int main(int argc,char **argv)
{
	int fd, len, nfd;
	
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
	
	printf("\nwaiting for client\n");
	nfd = accept(fd,(struct sockaddr*)&client_id,&len);

	if(fd<0)
	{
		perror("accept");
		return 0;
	}
	perror("accept");
	
	return 0;
}
