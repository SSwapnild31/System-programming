#include<stdio.h>

int sum(int a, int b)
{
	return a+b;
}

int main()
{
	int (*p)(int,int);
	p = sum;
	
	printf("sum : %d\n",(*p)(10,20));
	
	return 0;
}
