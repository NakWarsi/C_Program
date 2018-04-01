
#include<stdlib.h>
struct node{
int value;
struct node *next;
};
struct node *head;

int display(struct node *head)
{
struct node *temp=head;
while(temp != NULL)
	{
	printf("%d\n",temp->value);
	temp=temp->next;
	}
return 0;}


int insertinmiddle(int position,int X)
{
struct node *temp=head;
struct node *newnode;
newnode=(struct node*)malloc(sizeof(struct node));
newnode->value=X;
int i=0;
for(i=2;i<=position;i++)
	{
	if(temp->next!=NULL)
		temp=temp->next;
	}
newnode->next=temp->next;
temp->next=newnode;
return 0;
}



int insertatfront(int x)
{
//struct node head = *headref;
struct node *newnode;
newnode=(struct node*)malloc(sizeof(struct node));
newnode->value=x;
//struct node *temp;
//temp=head;
newnode->next=head;
head=newnode;
//*headref=head;
return 0;}


int insetatend(int X)
{
struct node *newnode;
newnode=(struct node*)malloc(sizeof(struct node));
newnode->value=X;
newnode->next=NULL;

struct node *temp=head;

while(temp->next!=NULL)
	{
	temp=temp->next;
	}
temp->next=newnode;
return 0;}


int deletefromfront()
{
struct node *headref;
headref=head;
head=head->next;
//*headref=head;
free(headref);
return 0;}


int deletefromend()
{
struct node *temp=head;
struct node *temp2;
while(temp->next->next!=NULL)
	{
	temp=temp->next;
	}
temp2=temp->next->next;
temp->next=NULL;
free(temp2);
return 0;}



int deletefrommid(int X)
{
struct node *temp=head;
struct node *pretemp;
//int i=0;
while(temp && temp->value != X)
	{
	pretemp=temp;
	temp=temp->next;
	}
pretemp->next=temp->next;

free(temp);
return 0;}




truct node *temp=head;

while(temp->next!=NULL)
        {
        temp=temp->next;
        }
temp->next=newnode;
return 0;}


int deletefromfront()
{
struct node *headref;
headref=head;
head=head->next;
//*headref=head;
//free(headref);
//return 0;}
//
//
//int deletefromend()
//{
//struct node *temp=head;
//struct node *temp2;
//while(temp->next->next!=NULL)
//        {
//
int main()
{
//struct node *head;
struct node *one=NULL;
struct node *two=NULL;
struct node *three=NULL;
one =(struct node*)malloc(sizeof(struct node));
two=(struct node*)malloc(sizeof(struct node));
three=(struct node*)malloc(sizeof(struct node));

one->value=100;
two->value=200;
three->value=300;

head=one;
one->next=two;
two->next=three;
three->next=NULL;

insertatfront(11111);
insetatend(400);
insertinmiddle(3,5566);
deletefromfront();
deletefromend();
deletefrommid(5566);
display(head);

return 0;}




















