#include<stdio.h>
#include<unistd.h>
#include<signal.h>
#include<string.h>

struct data {
	int count, set, num ;
};

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
		close(p[0]);
		signal(SIGUSR1,sig_handle);
		pause();

		int num2, pos;

		FILE *f2 = fopen("data.txt","r");
		struct data v={0,0,0};

		fscanf(f2,"%d",&num2);
		printf("child : number from file  %d\n",num2);

		for(pos = 31; pos >= 0; pos--)
		{
			if(num2>>pos&1)
				v.count++;
			if(pos == 5 && num2>>pos&1)
				v.set = 1;
		}
		pos = 3;
		v.num = num2^1<<pos;

		printf("\nchild : count of 1 bits %d\n",v.count);
		printf("child : after toggling 3rd bit num is %d\n",v.num);

		if(v.set)	printf("child : 5th bit is SET\n");
		else 		printf("child : 5th bit is CLEAR\n");

		write(p[1],&v, sizeof(v));

	}
	else
	{
		close(p[1]);
		int num1;
		FILE *f1 = fopen("data.txt","w");

		printf("parent : Enter number ");
		scanf("%d",&num1);

		fprintf(f1,"%d",num1);
		fflush(f1);
		fclose(f1);
		printf("parent : number is written into file and SIGUSR1 signal send.\n");
		
		kill(pid,SIGUSR1);
		
		struct data v1;

		read(p[0],&v1,sizeof(v1));
		
		printf("\nparent : count of 1 bits %d\n",v1.count);
		printf("parent : after toggling 3rd bit num is %d\n",v1.num);

		if(v1.set)	printf("parent : 5th bit is SET\n");
		else 		printf("parent : 5th bit is CLEAR\n");
		
	}
	
	return 0;
}
