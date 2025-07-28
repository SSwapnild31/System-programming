#include<stdio.h>

int sum(int,int);
int callback(int,int, int (*)(int,int));

void main()
{
	int i=10, j=20, r;

	r = callback(i,j,sum);
	printf("r : %d\n",r);
}

int callback(int m,int n, int (*p)(int,int))
{	
	int r;
	r = (*p)(m,n);
	return r;
}

int sum(int a,int b)
{
	return a+b;
}
