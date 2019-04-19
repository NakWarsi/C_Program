 #include<stdio.h>
void add(int,int);
void sub(int,int);
void mult(int,int);
int main()
{
int choice,x=5,y=6;
//void (*ptr)(int,int)=&add;
//(*ptr)(x,y);
void(*ptr1[])(int,int)={add,sub,mult};
printf("enter choice\n");
scanf("%d",&choice);

if(choice>2) return 0;

(*ptr1[choice])(x,y);	

return 0;
}

void add(int a,int b)
{
printf("\nSum = %d",(a+b));
}

void sub(int a,int b){
printf("\n %d",(a-b));
}

void mult(int a,int b)
{
printf("\n %d",(a*b));
}
