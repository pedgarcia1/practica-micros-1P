#include<stdio.h>

void tri(int n);

void main()
{
    int n = 7;

    tri(n);

}

void tri(int n)
{
    if (n < 1 || n > 60)
    {
        printf("el valor ingresado es incorrecto \n");            
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
           if (i == 0 || j == n-1 || j == i)
           {
            printf("*");
           }else{
            printf(" ");
           }
           
        if (j == n-1)
        {
            printf("\n");
        }
            
        }
        
    }
    

    
}