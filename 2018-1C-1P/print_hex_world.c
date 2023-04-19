#include<stdio.h>
#include<stdint.h>

void print_hex_word(uint16_t word);
void dec_to_hex(uint16_t a, char *hex);

void main()
{
    uint16_t w = 0xAC24;

    print_hex_word(w);
}

void print_hex_word(uint16_t word)
{

    int numChar = sizeof(uint16_t);
    char hex[2*2+1];

    dec_to_hex(word,hex);

    int i = 0;
    while (*(hex+i) != '\0')
    {
        putchar(*(hex+(numChar-i+1)));
        i++;
    }
    
}

void dec_to_hex(uint16_t word, char *hex)
{
    int j = 0;
    int r, q;
    
    q = word;
    while (q != 0)
    {
        r = q % 16;
        if (r < 10)
        {
            hex[j++] = 48 + r;
        }
        else
        {
            hex[j++] = 55 + r;
        }
        q = q / 16;
    }
    hex[j] = '\0';
}

