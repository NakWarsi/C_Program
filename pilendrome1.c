#include<stdio.h>
int reverse(int);
int main()
{
int a,c;
printf("enter the number");
scanf("%d",&a);
c=reverse(a);
if(c==a)
printf("piledrome");
else
printf("not a pilendrome");
}
int reverse(int n){
int rev=0;
while(n!=0){
rev=rev*10+n%10;
n=n/10;
}
return rev;
}
