#include<stdio.h>

int sum(int a,int b)
{
	return a+b;
}

void main()
{
	int i=10,j=20,k;
	int (*p)(int,int);
	
	k = sum(i,j);
	printf("k : %d\n",k);
	p = sum;
	k = (*p)(i,j);			// k = p(i,j);
	printf("k : %d\n",k);
}
