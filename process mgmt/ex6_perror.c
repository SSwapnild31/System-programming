#include<stdio.h>
#include<errno.h>

int main(int argc,char **argv)
{
	FILE *fp;
	fp = fopen(argv[1],"r");
	if(fp==0)
	{
		perror("fopen");
		return 0;
	}

	printf("File present..\n");
	printf("%d %d\n",EACCES,ENOENT);
	
	return 0;
}
