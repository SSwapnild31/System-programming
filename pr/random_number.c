#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
	
	srand(time(NULL));
	
	int random = rand();
	
	printf("random number: %d\n", random);

	return 0;
}
