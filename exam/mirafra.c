#include<stdio.h>
#include<unistd.h>
#include<signal.h>

void sig_handle(int signum)
{
	printf("child : Received SIGUSR1 signal and number readed from file\n");
}

int main()
{
	int p[2];
	pipe(p);
	
	int pid = fork();
	
	if(pid==0)
	{	
		signal(SIGUSR1,sig_handle);
		pause();

		int num2, pos, count = 0, set = 0;

		FILE *f2 = fopen("data.txt","r");

		fscanf(f2,"%d",&num2);
		printf("child : number from file  %d\n",num2);

		for(pos = 31; pos >= 0; pos--)
		{
			if(num2>>pos&1)
				count++;
			if(pos == 5 && num2>>pos&1)
				set = 1;
		}
		pos = 5;
		num2 = num2^1<<pos;
	}
	else
	{
		int num1;
		FILE *f1 = fopen("data.txt","w");
		printf("parent : Enter number ");
		scanf("%d",&num1);
		fprintf(f1,"%d",num1);
		kill(pid,SIGUSR1);
		printf("parent : number is written into file and SIGUSR1 signal send.\n");
	}
	
	return 0;
}
