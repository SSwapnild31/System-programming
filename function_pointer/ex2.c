#include<stdio.h>

void main()
{
	int (*p)(const char*, ...);
	
	p = printf;
	(*p)("Hello word..\n");
	printf("Hello world..\n");
}
