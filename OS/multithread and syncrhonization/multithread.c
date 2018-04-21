#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

void *thread1()
{
    int i=0;
    pthread_t id = pthread_self();     // get the ID of current thread
    while (i<10)
    {
        printf("Hello!!  %d\n ",id);
        //break;
    }    
}

void *thread2()
{
    int i=0;
    while (i<10)
    {
        pthread_t id = pthread_self();
        printf("How are you?   %d   %d\n",i,id);
        i++;
    }
}

int main()
{
    int status,i;
    pthread_t tid1, tid2;

    pthread_create(&tid1, NULL, thread1, NULL);
    pthread_create(&tid2, NULL, thread2, NULL);
    //pthread_join(tid1, NULL);
    //pthread_join(tid2, NULL);

    printf("exiting\n");
    return 0;
}
