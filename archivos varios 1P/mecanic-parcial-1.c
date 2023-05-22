#include <stdio.h>
#define m0 (1 << 0)
#define m1 (1 << 1)
#define m2 (1 << 2)
#define m3 (1 << 3)

int main()
{
    unsigned char port;
 port|=(m0 | m1| m2 | m3);

 printf("Port is %.2X: \n", port); // RESPUESTA: 0F

 port &= ~(m2 | m1);  // port = 1001 = 1+2^3 = 9 
 printf("Port is %.2X: \n", port); // RESPUESTA: 09

 port^= (m3 | m0); //^= XOR 1001^=1001 port = 0000
 printf("Port is %.2X: \n", port); // RESPUESTA: 00

    int *a
    printf("%d \n",sizeof(a));

 return 0;
}
// Teo comento esto desde github