#include<stdio.h>
#include<stdint.h>

void print_bin(uint8_t byte);
void print_string(char *s);


void main()
{
    uint8_t byte = 0b10001010;
    print_bin(byte);

    byte = 0x8A;
    print_bin(byte);
}

void print_bin(uint8_t n)
{
    int nBits = 8*sizeof(uint8_t); //calculo cantidad de bits
    char str[] = "0b";
    print_string(str); //imprimo solo la primer parte 0b

    for (int i = 0; i < nBits; i++) //recorre la cantidad de bits del uint8_t
    {
        uint8_t mask = 1 << (nBits - i -1); //creo una mascara de bit empezando por el mas significativo y terminando en el menos 
        if (i%4 == 0 && i != 0) //se imprime _ cada 4 bits (el primero se ignora)
        {
            putchar('_');
        }
        
        if (n & mask) //operacion AND bitwise, se imprime un 1 si en esa posicion del numero hay un bit = 1, se imprime 0 si no.
        {
            putchar('1');
        }else{ putchar('0'); }
        
    }
    putchar('\n');
}

void print_string(char *s)
{
    int i = 0;
    while (*(s+i) != '\0') //recorre hasta llegar al terminador e imprime el string
    {
        putchar(*(s+i));
        i++;
    }
    
}