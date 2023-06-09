#include<stdio.h>
#include <math.h>

#define N_TERM 12

double prodEscalar(double *v1,double *v2, int largo);
double seno_iter(double x);
int factorial(int x);

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

    *(p+1) = 3;

    --p[-1];
    printf("%d \n",*(p-1));

    int var = -11.7;
    // double aux = (double) (var/3);

    printf("%010f \n", (double) (var--/3));
    // char otro[];

    double x = 0.3; //angulo en rad
    printf("%f %f",seno_iter(x),sin(x));
    
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

double seno_iter(double x)
{
    // int f,termi;
    double res = 0;
    int count = 0;
    for (int i = 1; i < N_TERM; i = i+2)
    {
        // f = factorial(i);
        // termi = pow(-1,count);
        res += pow(-1,count)*pow(x,i)/(factorial(i));
        count++;
    }
    return res;
}

int factorial(int x)
{
    int res = 1;
    for (int i = 0; i < x; i++)
    {
        res = res*(x-i);
    }
    return res;
}

// Comentario de prueba Teo
