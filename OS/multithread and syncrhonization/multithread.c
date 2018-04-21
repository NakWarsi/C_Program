#include <stdio.h>
#include <pthread.h>  //header for pthread library
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

void *thread1()
{
    while (1)
    {
        printf("Hello!!\n");
    }
}

void *thread2()
{
    while (1)
    {
        printf("How are you?\n");
    }
}

int main()
{ 
    int status,i;  
    pthread_t tid1, tid2;            //variable which stores all the infermation about the thread

    pthread_create(&tid1, NULL, thread1, NULL);     //creating thread 1
    //sleep(3);
    pthread_create(&tid2, NULL, thread2, NULL);    
    pthread_join(tid1, NULL);                       //joining thread 1
    pthread_join(tid2, NULL);
   
    return 0;
}
