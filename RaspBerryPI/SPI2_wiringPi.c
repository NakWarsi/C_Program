#include <stdio.h>
#include <wiringPiSPI.h>
#include <unistd.h>
#include <string.h>

int CHANNEL = 0;

int main()
{
   int fd, result;
   unsigned char buffer[100];

   printf("Initializing\n");

   // Configure the interface.
   // CHANNEL insicates chip select,
   // 500000 indicates bus speed.
   fd = wiringPiSPISetup(CHANNEL, 500000);

   printf("Init result: %d\n",fd);

   // clear display
   printf("Enter Data: ");
   scanf("%s",buffer);
   buffer[strlen(buffer)]='\n';
   printf("%s",buffer);
   int rslt = wiringPiSPIDataRW(CHANNEL, buffer, strlen(buffer));
   printf("%d",rslt);

//   sleep(5);
   printf("Data : %s\n",buffer);
   return 0;
}
