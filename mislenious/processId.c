#include<stdio.h>
#include <sys/types.h>
#include <unistd.h>
int main()
{
while(1){
int x=getpid();
int y=getppid();
printf("pid =   %d\n",x);
printf("ppid = ............................................ %d\n",y);
}
return 0;}
