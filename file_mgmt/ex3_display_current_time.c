#include<stdio.h>
#include<time.h>
#include<stdlib.h>
#include<unistd.h>

void main()
{
	time_t t1;
	while(1)
	{
		time(&t1);
		printf("%s\n",ctime(&t1));
		//printf("%lu\n",t1);
		sleep(1);
		system("clear");
	}	
}
