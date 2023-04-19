#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    void *puntero = NULL;
    int *pint;

    puntero = calloc(10, sizeof(int));

    pint = puntero;

    pint[0] = 10;
    pint[1] = 20;
    pint[2] = 30;

    char array[12];
   
    for (int i = 0; i < 12; i++)
    {
        array[i] = ((char *) puntero)[i];

    }
    // print the array
    for (int i = 0; i < 12; i++)
    {
        printf("%d ", array[i]);
    }
    printf("\n");
    // wait for Q to be pressed
    //while (getchar() != 'q');
    free(puntero);
    //hola teo
    // otro comentario de pedro
    // otro commntario mas
    return 0;
}