#include<stdio.h>

void main()
{
    char txt[] = "renuncia.txt";

    FILE * f;
    f = fopen(txt,"r");

    char out;
    int count = 0;
    while (out != EOF)
    {
        fscanf(f, "%s",out);
        count++;
    }
    
    fclose(f);
}
