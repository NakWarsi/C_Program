#include<stdio.h>
#include<string.h>
#include <unistd.h>
int main()
{
FILE *fp;
fp = fopen("/sys/class/gpio/export","w");
fwrite("17", sizeof(char), strlen("17"), fp);
fclose(fp);
fp = fopen("/sys/class/gpio/gpio17/direction","w");
fwrite("out", sizeof(char), strlen("out"), fp);
fclose(fp);
while(1)
{
    fp = fopen("/sys/class/gpio/gpio17/value","w");
    fwrite("0", sizeof(char), strlen("0"), fp);
    fclose(fp);
    sleep(1);
    fp = fopen("/sys/class/gpio/gpio17/value","w");
    fwrite("1", sizeof(char), strlen("1"), fp);
    fclose(fp);
    sleep(1);

}
return 0;
}

