#include <stdio.h>
#include <string.h>
#include <pthread.h>
#include <stdlib.h>
#include <unistd.h>
#include <semaphore.h>
#include <time.h>

pthread_t tid[2];
sem_t mutex;
int i=0,sum=0;
int x=1;
pthread_mutex_t lock;

void *thread1()
{
    
    pthread_mutex_lock(&lock);
    x=x+1000;
    while (i<x)
    {
        sum = sum + i;
        i++;
    }
    printf("currentsum =%d\n",sum);
    //sleep(10);
    printf("\\");
    pthread_mutex_unlock(&lock);
}


int main()
{

    int status, i;
    pthread_t tid1, tid2, tid3, tid4, tid5;
    
    clock_t t;
    t=clock();
    pthread_create(&tid1, NULL, thread1, NULL);
    pthread_create(&tid2, NULL, thread1, NULL);
    pthread_create(&tid3, NULL, thread1, NULL);
    pthread_create(&tid4, NULL, thread1, NULL);
    pthread_create(&tid5, NULL, thread1, NULL);

    pthread_join(tid1, NULL);
    t=clock()-t;
    double time_taken=((double)t)/(CLOCKS_PER_SEC);
    printf("time1  :%d\n",time_taken);

    pthread_join(tid2, NULL);
    t = clock() - t;
    time_taken = ((double)t) / (CLOCKS_PER_SEC);
    
    printf("time2  :%d\n", time_taken);
    pthread_join(tid3, NULL);
    t = clock() - t;
    
    time_taken = ((double)t) / (CLOCKS_PER_SEC);
    printf("time3  :%d\n", time_taken);
    pthread_join(tid4, NULL);
    t = clock() - t;
    
    time_taken = ((double)t) / (CLOCKS_PER_SEC);
    printf("time4  :%d\n", time_taken);
    
    pthread_join(tid5, NULL);
    t = clock() - t;
    time_taken = ((double)t) / (CLOCKS_PER_SEC);
    
    printf("time5  :%d\n", time_taken);
    
    printf("sum   :%d\n",sum);
    return 0;
}
