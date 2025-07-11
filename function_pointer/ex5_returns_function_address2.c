#include<stdio.h>

int dummy(int a,float b)
{
	return a+b;
}

int (*abc (int a,char b))(int,float)
{
	return dummy;
}

int main()
{
	int (*ptr)(int,float);
	
	ptr = abc(10,'A');
	
	int k = (*ptr)(10,20.5);
	
	printf("k : %d\n",k);
	
	return 0;
}
