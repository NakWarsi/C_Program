#include<stdio.h>
int main()
{
FILE *fp;
char ch;
char a[10],x[10];
fp=fopen("file.text","r+");
if(fp==NULL)
printf("can not open the file");

//printf("enter something");
char b;
fscanf(fp,"%s",a);
printf("%s\n",a);

rewind(fp);
scanf("%s",x);
//printf("%s",b);
fprintf(fp,"%s",x);
//fclose(fp);
	
//fp=fopen("file.text","r");
//rewind(fp);

fseek(fp,0,SEEK_SET);
while((ch=getc(fp))!=EOF)
	printf("%c",ch);

fclose(fp);
return 0;
}
