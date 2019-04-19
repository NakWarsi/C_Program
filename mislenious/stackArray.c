#include<stdio.h>
#include<stdlib.h>
#define max 10
void push();
void pop();
void display();
int top = -1;
int stack[max];
int main()
{
int ch;
while(1)
    {
        printf("\n 1 for push(), 2 for pop(), 3 for display(), 4 for exit(0)\n");
        scanf("%d",&ch);
        switch(ch){
            case 1:
                push();
                break;
            case 2:
                pop();
                break;
            case 3:
                display();
                break;
            case 4:
                exit(0);
            default:
                printf("kuchh dhang ka daal bc");
        }
    }
return 0;}

void push()
{
    int a;
    if(top == max-1)
       {
            printf("\n stack is full");
       }   
    else
    {
        printf("Enter the value to push\n");
        scanf("%d",&a);   
        ++top;
        stack[top]=a;
    }
}


void pop()
{
    if(top< 0 )
    {
        printf("stack is empty");
    }
    else{
        printf("\n %d have deleted now \n",stack[top]);
        --top;
    }
}

void display()
{
    if(top<0)
    {
        printf("stack is empty");
    }
    else
    {
        for(int i=0;i<=top;i++)
            printf("%d",stack[i]);
    }
}
