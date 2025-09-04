#include<stdio.h>
#include<pthread.h>

void *newt(void *p)
{
	int num = *(int*)p;
	int i;
	for(i=2;i<num;i++)
	{
		if(num%i==0)
			break;
	}
	if(num==i)
		printf("Number is prime\n");
	else
		printf("Number is not prime\n");
}

void main()
{
	int num;
	printf("Enter number : ");
	scanf("%d",&num);
	
	pthread_t t1;
	pthread_create(&t1,0,newt,&num);
	
	pthread_exit(0);
	
}
