#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

void abc()
{
	printf("In abc func\n");
}

void main()
{
	printf("Hello\n");
	atexit(abc);
	printf("Hai..\n");
	sleep(10);
	printf("bye..\n");
}
