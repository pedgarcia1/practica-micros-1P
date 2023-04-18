#include <stdio.h>
#include <stdint.h>

void print_bin(uint8_t byte);

void main()
{
    uint8_t n = 0x8A;

    print_bin(n);
}

void print_bin(uint8_t byte)
{
    uint8_t mask;
    char bit;
    printf("0b");
    for (int i = 0; i < 8*sizeof(byte); i++)
    {
        mask = 1 << (8*sizeof(byte)-1-i);
        bit = mask & byte;

        if (i%4 == 0 && i != 0)
        {
            printf("_");
        }
        
        
        if(bit)
        {
            printf("1");
        }else{
            printf("0");
        }
        

    }
    printf("\n");
    
}

// Otro comentario para ver como pingo anda github.