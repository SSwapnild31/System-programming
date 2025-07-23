//signal-based program that periodically writes characters to a file using SIGALRM, and automatically stops after writing 'z'.

#include<stdio.h>
#include<unistd.h>
#include<signal.h>

FILE *fp;

void my_isr(int n)
{
	static char ch = 'a';
	fputc(ch,fp);
	ch++;
	if(ch == 'z')
	{
		fputc(ch,fp);
		fclose(fp);
		raise(9);
	}
	alarm(1);
}

void main()
{
	fp = fopen("Data","w");
	if(fp==0)
	{
		perror("fopen");
		return ;
	}
	signal(14,my_isr);
	alarm(1);
	while(1);
}
