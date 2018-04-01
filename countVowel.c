#include<stdio.h>
int main()
{
char a[10];
printf("enter an string\n");
scanf("%s",a);
int i=0,count=0;
while(a[i]!='\0')
	{
	if(a[i]=='a'||a[i]=='e'||a[i]=='i'||a[i]=='o'||a[i]=='u'||a[i]=='A'||a[i]=='E'||a[i]=='I'||a[i]=='O'||a[i]=='U')
		count++;
	i++;
	}
printf("%d \n",count);
return 0;
}
