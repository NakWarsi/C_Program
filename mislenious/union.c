#include<stdio.h>
#include<string.h>
union data{
int x;
char y;
char arr[10];
};

int main()
{
union data obj;

obj.x=20;
printf("%d\n",obj.x);

obj.y='P';
strcpy(obj.arr,"nak warsi");
printf("%c\n",obj.y);
printf("%s\n",obj.arr);

printf("%d\n",obj.x);
printf("%c\n",obj.y);
return 0;}
