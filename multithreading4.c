#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>
#include <stdlib.h> 

char n[1024];
sem_t len;

void * read1()
{
        while(1){
          
            printf("\nEnter a string");
            scanf("%s", n);
            sem_post(&len);  //to unlock the process
        }
}

void * write1()
{
        while(1){
                sem_wait(&len);
                printf("\nThe string entered is :");
                printf("==== %s\n",n);
        }

}

int main()
{
        int status;
        pthread_t tr, tw;

        pthread_create(&tr,NULL,read1,NULL);
        pthread_create(&tw,NULL,write1,NULL);

        pthread_join(tr,NULL);
        pthread_join(tw,NULL);
        return 0;
}
