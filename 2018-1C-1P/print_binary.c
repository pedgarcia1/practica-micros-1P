#include<stdio.h>
#include<stdint.h>
#include<stdlib.h>

void print_binary(uint16_t n);
void print_string(char *s);


void main()
{
    uint16_t number = 0b01110001;
    print_binary(number);

    number = 0xABCD;
    print_binary(number);

    number = 100;
    print_binary(number);
}

void print_binary(uint16_t n)
{
    int nBits = 8*sizeof(uint16_t);
    char str[] = "Number in binary is:";
    print_string(str);

    for (int i = 0; i < nBits; i++)
    {
        uint16_t mask = 1 << (nBits - i -1);
        if (i%4 == 0)
        {
            putchar(' ');
        }
        
        if (n & mask)
        {
            putchar('1');
        }else{ putchar('0'); }
        
    }
    putchar('\n');
}

void print_string(char *s)
{
    int i = 0;
    while (*(s+i) != '\0')
    {
        putchar(*(s+i));
        i++;
    }
    
}