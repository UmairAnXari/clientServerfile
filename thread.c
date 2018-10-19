#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

int dataSet[1000];
int chunkSize = 100;
void *Add(void *args)
{
 int start = (int)args;
 int end = start+chunkSize, sum=0, i;
 for(i=start; i<end; i++)
 {
  sum = sum + i;
 }
 return ((void*)sum);
}
int main()
{
 int status[10], totalSum = 0;

 pthread_t thread[10];
 for(int x=0; x<10; x++)
  pthread_create(&thread[x],NULL,Add,(void*)(x*100));
 
 for(int y=0; y<10; y++)
  pthread_join(thread[y],(void**)&status[y]);

 for(int z=0; z<10; z++)
  totalSum = totalSum + status[z];

 printf("Total Sum Is %d", totalSum);

 return 0;
}
