#include<stdio.h>
#include<string.h>

void tri(int n);
int str_lgth(char *str1);
int is_in_str(char *str1,char *str2);

#define X 20

void main()
{
    int n = 7;

    tri(n);

    char s1[] = "hola";
    char s2[] = "ona";

    int flag = is_in_str(s2,s1);

    // printf("%d \n",flag);

    char d = 50;
    printf("%X\n",d);   
    char x = 153;
    printf("%d \n",x);

    /*
    ej4. a) gcc main.c -Wall -o recuperatorio.exe -g -D DEBUG
    b) .\recuperatorio.exe
    */

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

int is_in_str(char *str1,char *str2)
{
    int largo1 = str_lgth(str1);
    int largo2 = str_lgth(str2);

    int flag = 0;

    for (int i = 0; i < largo2; i++)
    {
        if (str1[0] == str2[i])
        {
            flag = 1;
            for (int j = 0; j < largo1; j++)
            {
                if (str1[j] != str2[i+j])
                {
                    flag = 0;
                }
                
            }
            
        }
        
        
    }
    return flag;
    
    
}

int str_lgth(char *str1)
{
    int i = 0;
    while (str1[i] != '\0')
    {
        i++;
    }
    return i;
}