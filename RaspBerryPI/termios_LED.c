#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include<termios.h>
#include<string.h>
#include<wiringPi.h>
int uart0 = -1;
int main()
{
    wiringPiSetup();
    pinMode(7,OUTPUT);
    uart0 = open("/dev/ttyAMA0",O_RDWR | O_NOCTTY | O_NDELAY);
    struct termios opt;
    tcgetattr(uart0,&opt);
    opt.c_cflag = B9600 | CS8 | CLOCAL | CREAD;
    opt.c_iflag = IGNPAR;
    opt.c_oflag = 0;
    opt.c_lflag = 0;
    tcflush(uart0,TCIFLUSH);
    tcsetattr(uart0,TCSANOW,&opt);
    
    unsigned char tx_buff[20];
    unsigned char *p_tx_buff;
    p_tx_buff = &tx_buff[0];
    *p_tx_buff++ =  'H';
    *p_tx_buff++ =  'E';
    *p_tx_buff++ =  'L';
    *p_tx_buff++ =  'L';
    *p_tx_buff++ =  'O';
    
    if(uart0 != -1)
    {
 	int count = write(uart0,&tx_buff[0],(p_tx_buff-&tx_buff[0]));
	if(count < 0)
	{
	    printf("Uart TX err\n");
	}
 	else
	{
	    printf("Transmitted\n");
	}
    }
    
    while(1)
    {
	sleep(1);
	if(uart0!=-1)
	{
	    unsigned char rx_buff[256];
	    int rx_length = read(uart0,(void *)rx_buff,255);
	    if(rx_length<0)
	    {
		printf("Read ERROR\n");
	    }
	    else if (rx_length == 0)
	    {
		printf("Waiting....\n");
 	    }
	    else
	    {
		rx_buff[rx_length]='\0';
		printf("%i bytes read : %s\n",rx_length,rx_buff);
		if(strcmp(rx_buff,"ON")==0)
		{
		    digitalWrite(7,HIGH);
		    if(uart0 != -1)
		    {
			p_tx_buff = &tx_buff[0];
			*p_tx_buff++ =  'L';
			*p_tx_buff++ =  'E';
			*p_tx_buff++ =  'D';
			*p_tx_buff++ =  'O';
			*p_tx_buff++ =  'N';
		        int count = write(uart0,&tx_buff[0],(p_tx_buff-&tx_buff[0]));
		        if(count < 0)
		        {
		            printf("Uart TX err\n");
		        }
		        else
		        {
		            printf("Transmitted\n");
		        }
		    }
		}
		if(strcmp(rx_buff,"OFF")==0)
		{
                    digitalWrite(7,LOW);
		    if(uart0 != -1)
                    {
                        p_tx_buff = &tx_buff[0];
                        *p_tx_buff++ =  'L';
                        *p_tx_buff++ =  'E';
                        *p_tx_buff++ =  'D';
                        *p_tx_buff++ =  'O';
                        *p_tx_buff++ =  'F';
			*p_tx_buff++ =  'F';
                        int count = write(uart0,&tx_buff[0],(p_tx_buff-&tx_buff[0]));
                        if(count < 0)
                        {
                            printf("Uart TX err\n");
                        }
                        else
                        {
                            printf("Transmitted\n");
                        }
                    }
		}
		//close(uart0);
		//break;
	    }
	}
    }
    return 0;
}
