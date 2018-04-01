#include<stdio.h>
#include<stdlib.h>

// PGDIOT, PRN -180240126010
//NOTE- Ctrl +C to quit

typedef struct node
{
    int data;
    struct node * next;
}Node;

Node * head;

int push(int d) 
{
    Node * curNode = head;
    Node * newNode = (Node *)malloc(sizeof(Node));
    newNode->data = d;
    if(head == NULL)
    {
	newNode->next = head;
        head = newNode;
    }
    else
    {
	while(curNode->next!=NULL)
	{
	    curNode=curNode->next;
	}
	newNode->next = curNode->next;
        curNode->next = newNode;
    }
    return 1;
}

int pop()
{
    Node * curNode = head;
    Node * prevNode = NULL;
    while(curNode->next!=NULL)
    {
	prevNode = curNode;
	curNode = curNode->next;
    }
    if(curNode!=NULL)
    {
	if(prevNode)
	{
	    int d = curNode->data;
	    prevNode->next = curNode->next;
 	    free(curNode);
	    return d;
	}
	else
	{
	    int d = curNode->data;
	    head = curNode->next;
	    free(curNode);
	    return d;
	}
    }
    return 0;
}

void display()
{
    Node * curNode = head;
    printf("\nElements in the stack are : ");
    while(curNode!=NULL)
    {
	printf("%d ",curNode->data);
	curNode=curNode->next;
    }
}

void peek()
{
	Node *topNode=head;
	while(topNode->next!=NULL)
	{
		topNode=topNode->next;
	}
	printf("\nTop Most Element is  %d",topNode->data);
}

int IsEmpty()
{
	int rs=1;
	if(head==NULL)
	{
		printf("\nStack is Empty!!!");
	}
	else
	{
	rs=0;
	}
	return rs;
}

int main()
{
    int choice,n,result;
    do
    {
	printf("\n\n\nEnter Your Choice in Number ----");
	printf("\n 1. Push");
	printf("\n 2. Pop");
	printf("\n 3. Peek");
	printf("\n 4. Display");
	printf("\n\nEnter your choice : ");
	scanf("%d",&choice);
	switch(choice)
	{
	    case 1:
		   printf("\nEnter element to push: ");
		   scanf("%d",&n);
		   result = push(n);
		   if (result == 1)
			printf("\nInsert successfully.");
		   else
			printf("\nFailed !!!");
		   break;
	    case 2:
			result=IsEmpty();
		if(result==0)
		{
			result=pop();
                        printf("\nPoped element %d",result);
		}
		
                   break;
	    case 3:
		   if (result == -1)
                        printf("\nStack empty");
                   else
		{
                  peek();
		}
                   break;
	    case 4:
		   display();
		   break;
	    default:
		   printf("\nWrong choice entered.");
		   break;
	}
    }while(1);
    return 0;
}
