#include <stdio.h>

void universal_swap(void*, void*, int);

int main(){
    int a = 5, b = 3;
    float c = 2.7, d = 5.92;

    void* pA = &a, *pB = &b, *pC = &c, *pD = &d;
    
    printf("%d, %d \n", a, b);
    printf("%f, %f\n", c, d);

    universal_swap(pA, pB, sizeof(a));
    universal_swap(pC, pD, sizeof(c));

    printf("%d, %d \n", a, b);
    printf("%f, %f\n", c, d);

    return 0;
}

void universal_swap(void* p1, void* p2, int n){
    char *p_aux1 = (char*) p1;
    char *p_aux2 = (char*) p2;
    char *p_aux;

    for (int i = 0; i < n; i++)
    {
        *p_aux = p_aux1[i];
        p_aux1[i] = p_aux2[i];
        p_aux2[i] = *p_aux;
    }
    
}