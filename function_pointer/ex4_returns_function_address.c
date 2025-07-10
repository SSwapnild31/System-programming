#include<stdio.h>

//int (*p)(int,int) fun_ret_addr(void)		Incorrect/Invalid

int(*fun_ret_addr(void))(int,int);
int mul(int,int);
int main()
{
	int a=10,b=20,r;
	int (*p)(int,int);
	
	p = fun_ret_addr();
	
	r = (*p)(a,b);	
	printf("r : %d\n",r);

	return 0;
}

//int(*)(int ,int) fun_ret_addr(void)		Incorrect/Invalid

int (*fun_ret_addr(void))(int,int)
{
	return mul;
}

int mul(int a,int b)
{
	return a*b;
}
