#include <stdio.h>
#include <unistd.h>
#define MSGSIZE 16
char* msg1 = "hello, world #1";
char* msg2 = "hello, world #2";
char* msg3 = "hello, world #3";

int main()
{
    char inbuf[MSGSIZE];
    int p[2], i;
    int pid,cnt;
    int n;
    printf("enter some value\n");
    scanf("%d", &n);
    cnt=3;
    if (pipe(p) < 0)
        exit(1);
 
    /* continued */
    /* write pipe */
    pid=fork();
    if(pid==0){
        int j=0;
        while(j<2)
        {
    printf("Inside child\n");
    write(p[1], msg1, MSGSIZE);
    write(p[1], msg2, MSGSIZE);
    write(p[1], msg3, MSGSIZE);
 
    for (i = 0; i < cnt; i++) {
        /* read pipe */
        read(p[0], inbuf, MSGSIZE);
        printf("% s\n", inbuf);
        printf("%d",n*n);
    }
    sleep(3);
    j++;
    }
    }
    else{
    printf("\nThis is parent\n");
    }return 0;
}
