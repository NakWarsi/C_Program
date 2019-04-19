#include<stdio.h>
#include<stdlib.h>
struct node{
    int value;
    struct node *next;
};
struct node *head;

void display();
void search();
//void count();
void addbeg();
void addafter();
void addend();
void reverse();

int main()
{
    int ch;
    while(1){
    printf("Enter  1 for display(), 2 for search(), 3 for count(), 4 for addbeg(), 5 for add after(), 6 for addend(), 7 for exit()");
    scanf("%d",&ch);
    switch(ch){
        case 1:
            display();
            break;
        case 2:
            search();
            break;
        // case 3:
        //     count();
        //     break;
        case 4:
            addbeg();
            break;
        // case 5:
        //     addafter();
        //     break;
        case 6:
            addend();}
    }
return 0;}

void display()
{
    struct node *temp=head;
    while(temp!=NULL)
    {
        printf("%d",temp->value);
        temp=temp->next;
    }
}


void search()
{
int a;
printf("enter the value to search");
scanf("%d",&a);
int flag=0;
int index=0;
struct node *temp=head;
while(temp!=NULL)
{
    if(temp->value==a)
    {
        flag=1;
        break;
    }
    temp=temp->next;
    index++;
}
if(flag==1)
    printf("the value is found at %d position",index);
else
    printf("the value is not found");
}


void addbeg(){
    int a;
    struct node *newnode;
    newnode=(struct node *)malloc(sizeof(struct node));
    printf("enter the value to add\n");
    scanf("%d",&a);
    newnode->value=a;
    newnode->next=head;
    head=newnode;
}


void addend()
{
    int a;
    struct node *temp;
    struct node *newnode;
    newnode=(struct node *)malloc(sizeof(struct node));
    printf("enter the value to add\n");
    scanf("%d", &a);
    newnode->value = a;

    temp=head;
    while(temp->next!=NULL)
    {
        temp=temp->next;
    }
    temp->next=newnode;
    newnode->next=NULL;
}
