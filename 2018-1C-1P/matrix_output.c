#include<stdio.h>

int M2D[][5] = {{1,2,3,4},{5,6,7,8},{9,10,11,12}};
int *p0 = M2D[0];
int *p1 = M2D[1];

void main()
{
    printf("%d \n",p0[4]);
    printf("%d \n",p1[5]);

    size_t a = 1;
}