#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>

int main(int argc,char **argv)
{
	close(0);
	int a[5];
	
	int fd = open(argv[1],O_RDONLY);
	
	for(int i=0;i<5;i++)
		scanf("%d",&a[i]);
	
	for(int i=0;i<5;i++)
		printf("%d ",a[i]);
	printf("\n");

	return 0;
}
