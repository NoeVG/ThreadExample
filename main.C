/**
  This code, to show the multitask in Linux through fork
  Problem:
    Is necessary to calc the sum of N numbers.
*/

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <time.h>
#include <sys/types.h>
#include <unistd.h>

#define THREAD 10
double sumNumbers(int ,int );

///THREAD
void *myThreadFun(void *vargp)
{
  ///print total.
    printf("Process! PID[%d] ,from Thread,Total: %f \n",getpid(),sumNumbers(0,1E9));
    return NULL;
}

int main(int argc, char const *argv[]) {
  pthread_t thread_id;
  printf("Before Thread\n");
  ///Create threads
  for(int i = 0;i < THREAD ;i++){
    pthread_create(&thread_id, NULL, myThreadFun, NULL);
    pthread_join(thread_id, NULL);
  }
  printf("After Thread\n");
  return 0;
}
///Sum numbers function
double sumNumbers(int startN,int endN)
{
  double result = 0;
  /// sum the numbers
  for(int i = startN; i <= endN ; i++){
    result +=i;
  }
  return result;
}
