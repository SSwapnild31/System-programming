#include<stdio.h>
#include<pthread.h>

void* helper(void *msg){
  return msg;
}

int main()
{
  pthread_t t;
  int num, *res;
  
  printf("Enter number : ");
  scanf("%d",&num);
  
  pthread_create(&t, NULL, helper,(void*)&num);
  pthread_join(t, (void*)&res);
  
  printf("result of thread : %d\n",*(int*)res);
  return 0;
}
