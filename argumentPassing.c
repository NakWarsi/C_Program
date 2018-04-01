#include<stdio.h>
int main(int argc,char* argv[])
{
printf("program name = %s \n",argv[0]);
//printf("pointer value of first command = %d \n",argc);
//if(argc==2)
//printf("first argument supplied is = %s \n", argv[1]);
//else if(argc>2)
//printf("to many argume \n");
//else
//printf("some argument expected here");
if(argc>2)
{
    printf("%d\n", (*argv[1]-'0')+(*argv[2]-'0'));
}

return 0;}