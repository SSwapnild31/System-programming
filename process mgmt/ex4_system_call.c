#include<stdio.h>
#include<stdlib.h>

void main()
{
	char s[10];
	printf("Enter command : ");
	scanf("%[^\n]",s);
	system(s);
}
