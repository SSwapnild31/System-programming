#include<stdio.h>

int sum(int a,int b)
{
	return a+b;
}

int sub(int a,int b)
{
	return a-b;
}

int mul(int a,int b)
{
	return a*b;
}

int div(int a,int b)
{
	return a/b;
}

int main()
{
	int i=10,j=20,k;
	int (*p[4])(int,int)={sum,sub,mul,div};
	
	for(k=0;k<4;k++)
		printf("res : %d\n",(*p[k])(i,j));
		
	return 0;
}
