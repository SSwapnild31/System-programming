#include<stdio.h>
#include<stdlib.h>

int main()
{
	int a[5],i;
	srand(getpid());
	for(i=0;i<5;i++)
		a[i]= rand() % 899 + 101;
	
	for(i=0;i<5;i++)
		printf("%d ",a[i]);
	printf("\n");
	
	return 0;
}
