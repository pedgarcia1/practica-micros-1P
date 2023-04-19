//creo que la rta del ejercicio es 0, voy a chequear

unsigned char x = 255;
unsigned char y = 1;
#include<stdio.h>
int suma(char x,char y);
void main()
{
    printf("Suma: %d \n",suma(x,y));
    printf("Suma; %d \n",x+y); 
}

int suma(char x,char y)
{
    return (x+y);
}