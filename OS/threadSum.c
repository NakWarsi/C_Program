#include<stdio.h>
#include<pthread.h>
#include<unistd.h>
#include<time.h>

pthread_t tid[5];
pthread_mutex_t lockwa;
time_t timewa1,timewa2;
int counter;

void* sum ()
{
	pthread_mutex_lock(&lockwa);
	timewa1=time(NULL);
	int i;
	int sumwa=0;
	counter++;
	if(counter==1)
	{
		for(i=1;i<10001;i++)
			sumwa=sumwa+i;
	}
	else if(counter==2)
	{
		for(i=10001;i<20001;i++)
			sumwa=sumwa+i;
	}
	else if(counter==3)
	{
		for(i=20001;i<30001;i++)
			sumwa=sumwa+i;
	}
	else if(counter==4)
	{
		for(i=30001;i<40001;i++)
			sumwa=sumwa+i;
	}
	else if(counter==5)
	{
		for(i=40001;i<50001;i++)
			sumwa=sumwa+i;
	}
	timewa2=time(NULL);
	long int time;
	time=timewa2-timewa1;
	printf("Sum : %d\tTime Taken for %d: %ld\n",sumwa,counter,time);
	pthread_mutex_unlock(&lockwa);
}

int main ()
{
	int i =0;
	int err;
	
	time_t tt;
	tt=time(NULL);
	printf("\ntime %ld\n",tt);

	if(pthread_mutex_init(&lockwa,NULL)!=0)
	{
		printf("mutex_init failed");
		return 1;
	}
	while(i<5)
	{
		err = pthread_create(&(tid[i]), NULL, &sum, NULL);
        if (err != 0)
            printf("\ncan't create thread :[%s]", strerror(err));
        i++;
    }


	    pthread_join(tid[0], NULL);
	    pthread_join(tid[1], NULL);
	    pthread_join(tid[2], NULL);
	    pthread_join(tid[3], NULL);
	    pthread_join(tid[4], NULL);

	    pthread_mutex_destroy(&lockwa);

    return 0;
}
