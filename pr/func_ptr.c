#include<stdio.h>

int sum(int a)
{
	printf("In sum a : %d\n",a);
}

int mul(int a,int (*p)(int))
{
	printf("In mul a : %d\n",a);
}

int main()
{

int (*p)(int,int(*)(int));

p = mul;

p(10,sum);

}
