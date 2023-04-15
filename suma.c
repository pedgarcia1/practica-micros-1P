#include<stdio.h>
unsigned char x=255;
unsigned char y=1;
int suma ( char x,char y);
int main(void)
{
 printf("Suma:%d \n",suma(x,y)); 
 return 0;
}
int suma ( char x,char y)
{
return(x+y);
}