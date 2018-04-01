#include<stdio.h>
int main()
{
int x=10,y=20,z=30;
typedef int* intptr;
intptr a,b,c;
a=&x;
b=&y;
c=&z;
printf("x= %d  \ny= %d \nz= %d\n",*a,*b,*c);
return 0;}
