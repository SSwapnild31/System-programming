/*  Parent process:
        create two childs :
            Child 1: Reads the contents of a directory and writes the names into a file called "data" after every1 second.
            Child 2: Waits for a signal (SIGUSR1) and writes a string to the same file upon receiving the signal via a signal handler.
    Parent:
        Waits for Child 1 to finish.
        use kill to sends SIGUSR1 to Child 2.
*/


#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<string.h>
#include<dirent.h>
#include<sys/types.h>
#include<sys/wait.h>
#include<fcntl.h>

void my_isr(int n)
{
	int fd = open("data",O_WRONLY|O_APPEND|O_CREAT,0664);
	char s[]="Received SIGUSR1\n";
	write(fd,s,strlen(s));
	close(fd);
	printf("Isr done\n");
}

int main(int argc,char **argv)
{
	if(argc!=2)
	{
		printf("usage : ./a.out dir_name\n");
		printf("usage : ./a.out signal_mgmt\n");
		return 0;
	}

	int r = fork();

	if(r==0)
	{
		int fd = open("data", O_WRONLY | O_APPEND | O_CREAT, 0664);
		DIR *dp = opendir(argv[1]);
		
		struct dirent *v;
		
		while(v = readdir(dp))
		{
			write(fd,v->d_name,strlen(v->d_name));
			write(fd,"\n",1);
			sleep(1);
		}
		close(fd);
		closedir(dp);
							//printf("pid : %d done\n",getpid());
	}
	else
	{
		int r2 = fork();

		if(r2==0)
		{
			signal(SIGUSR1,my_isr);
							//printf("waiting for signal\n");
			pause();
							//printf("signal received\n");
							//printf("pid : %d done\n",getpid());
		}
		else
		{
			int s;
			waitpid(r,0,0);
			kill(r2,SIGUSR1);
			waitpid(r2,0,0);
							//printf("all done\n");
		}
	}
	
	return 0;
}
