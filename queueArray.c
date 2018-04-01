#include<stdio.h>
#include<stdlib.h>
#define max 10
void enqueue();
void dequeue();
void display();
int queue[max];
int front=-1;
int rear=-1;
int size=-1;
int main()
{
    int ch;
    while(1){
        printf("enter 1 for enqueue(), 2 for dequeue(), 3 for display(), 4 for exit(0)");
        scanf("%d",&ch);
        switch(ch){
            case 1:
                enqueue();
                break;
            case 2:
                dequeue();
                break;
            case 3:
                display();
                break;
            case 4:
                exit(0);
            default:
                printf("kuchh dang ka daal");
            }
    }
return 0;}


void enqueue()
{
    if(size<max)
        {
            int a;
            printf("enter tha value to put in queue");
            scanf("%d",&a);
            if(size<0)
            {
                size++;
                front=0;
                rear=0;
                queue[0]=a;
            }
            else if(rear==max-1)
            {
                queue[0]=a;
                rear =0;
                size++;
            }
            else{
                size++;
                rear++;
                queue[rear]=a;
            }
        }
    else{
        printf("queue is full");
    }
}


void dequeue()
{
    if(size>-1)
    {
        size--;
        front++;
    }    
    else{
        printf("\n queue is empty\n");
    }
}






void display()
{
    if(size<0)
    {
        printf("\n queue is empty");
    }
    else{
        if(rear>front)
        {
            for(int i=front;i<=rear;i++)
                printf("%d",queue[i]);
        }
        else{
            for(int i=front;i<max;i++)
                printf("%d",queue[i]);
            for(int i=0;i<=rear;i++)
                printf("%d",queue[i]);
        }
    }
}