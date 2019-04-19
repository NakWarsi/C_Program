#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

void *thread1()
{
    pthread_t id = pthread_self();
    while (1)
    {
        printf("Hello!!  %d\n ",id);
    }
}

void *thread2()
{
    while (1)
    {
        pthread_t id = pthread_self();
        printf("How are you?      %d\n",id);
    }
}

int main()
{
    int status,i;
    pthread_t tid1, tid2;

    pthread_create(&tid1, NULL, thread1, NULL);
    pthread_create(&tid2, NULL, thread2, NULL);
    pthread_join(tid1, NULL);
    pthread_join(tid2, NULL);
    return 0;
}
