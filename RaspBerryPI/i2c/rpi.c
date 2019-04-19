#include <stdio.h>
#include <wiringPi.h>
#include <wiringPiI2C.h>

int main (int argc, char *argv[])
{
        int fd;
        int data;
        wiringPiSetup () ;
        fd=wiringPiI2CSetup (0x68) ;  /*Use i2cdetect command to find your respective device address*/
        if(fd==-1)
        {
                printf("Can't setup the I2C device\n");
                return -1;
        }
        else
        {
        wiringPiI2CWrite (fd, 11); //here '11' is just data.
                for (;;)
                {
                        data=wiringPiI2CRead(fd);
                        if(data==-1)
                        {
                                printf("No data\n");
                                //return -1;
                        }
                        else
                        {
                                //print data
                                printf("data=%d\n", data);
                        }
            sleep(1);
                }
        }
        return 0;
}
