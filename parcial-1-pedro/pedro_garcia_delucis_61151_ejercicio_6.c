#include<stdio.h>

void impinv(char *str); //imprime el string al reves
int strlength(char *str); //calcula el largo de un string

void main()
{
    char string[] = "Hola como va";
    printf("%s al reves es: \n",string);
    impinv(string); 

    char otro_string[] = "neuquen";
    printf("%s al reves es: \n",otro_string);
    impinv(otro_string);
}

void impinv(char *str)
{
    int strLgth = strlength(str); //obtengo el largo del string, sin contar el terminador \0

    for (int i = strLgth; i >= 0; i--) //recorro el vector en sentido contrario, empezando por la posicion strLght y termiando en la primera posicion [0]
    {
        putchar(*(str + i)); //imprimo el caracter en consola
    }
    putchar('\n');
}

int strlength(char *str)
{
    int n = 0;
    while (*str++) //recorre el string hasta el terminador (se interpreta como un 0 y finaliza el while loop)
    {
        n++;
    }
    return n;
}