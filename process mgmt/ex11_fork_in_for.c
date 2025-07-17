#include<stdio.h>
#include<unistd.h>

void main()
{
	for(int i=0;i<3;i++)
	{
		if(fork()==0)
			printf("Hai..\n");
	}
	while(1);
}

//	7 times Hai will print
