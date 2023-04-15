#include<stdio.h>

double prodEscalar(double *v1,double *v2, int largo);

// faltan comentarios
void main()
{
    double vec1[] = {1,2,3};
    double vec2[] = {4,5,6};

    double res = prodEscalar(vec1,vec2,sizeof(vec1)/sizeof(vec1[0]));

    printf("%f \n",res);

    int arr[] = {5,11,22,33};
    int *p = &arr[1];

    printf("%d \n",*p++); // (aumenta lo que hay en el puntero) (*p)++ != *p++ (aumenta puntero)
    printf("%d \n",(*p)++); 
    printf("%d \n",*p);

    // char otro[];
}

double prodEscalar(double *v1,double *v2, int largo)
{
    double out = 0;
    for (int i = 0; i < largo; i++)
    {
        out += v1[i]*v2[i];
    }
    return out;
}