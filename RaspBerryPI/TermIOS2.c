#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include<termios.h>
int uart0 = -1;
int main()
{
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
		close(uart0);
		break;
	    }
	}
    }
    return 0;
}
