#include<unistd.h>

int main()
{
	if(fork()==0)
		execl("/bin/ls","ls",NULL);
	else
		execl("/bin/pwd","pwd",NULL);
	return 0;
}
