#include<unistd.h>
#include<stdio.h>

int main(int argc,char **argv,char **env)
{
	for(int i=0;env[i];i++)
	{
		printf("%s\n",env[i]);
		sleep(1);
	} 
	printf("Done\n");
	return 0;
}
