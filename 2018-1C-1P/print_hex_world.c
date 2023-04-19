#include<stdio.h>
#include<stdint.h>

void print_hex_word(uint32_t word);
void dec_to_hex(uint32_t a, char *hex);

void main()
{
    uint32_t w = 0xAB24FF12;

    print_hex_word(w);
}

void print_hex_word(uint32_t word)
{

    int numChar = sizeof(uint32_t);
    char hex[2*numChar+1];

    dec_to_hex(word,hex);

    int i = 0;
    while (*(hex+i) != '\0')
    {
        putchar(*(hex+(2*numChar-1-i)));
        i++;
    }
    
}

void dec_to_hex(uint32_t word, char *hex)
{
    int j = 0;
    uint32_t r, q;
    
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

