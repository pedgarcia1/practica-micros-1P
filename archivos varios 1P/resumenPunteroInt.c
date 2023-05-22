#include <stdio.h>

int main(void)
{
    
    int i, b, a;
    int arr[6] = {21, 23, 25, 27, 29, 31};
    int *ptr = arr;
    printf("El arreglo arr es: ");
    for (i = 0; i < 6; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n\n");
    printf("El puntero ptr apunta a la direccion de arr[0]: %p\n", ptr);
    printf("Si yo hago ptr+1 entonces va a apuntar a la direccion de arr[1]: %p\n", ++ptr);
    printf("La dirección esta en hexa, por lo que aumentar el valor en 1 sinifica que me corrí un byte\n");
    printf("Notese que el valor de la dirección es ahora 4 veces mas que el anterior, dado que el tamaño de un entero es de 4 bytes\n");

    printf("\n");

    printf("Si quier acceder al contenido del elemento 4 de arr a través del puntero ptr, entonces puedo hacer ptr[2]: %d\n", ptr[2]);
    printf("Ojo porque ptr ya apuntaba al segundo elemento del arreglo, entonces ptr[2] es lo mismo que arr[4].\n");
    // \n
    printf("\n");
    printf("Entonces hacer ptr[1] es lo mismo que hacer *(ptr+1): %d\n", *(ptr+1));
    printf("Atenti al uso de parentesis en la expresión anterior, porque si no se confunde con el operador de indirección(*)\n");
    printf("\n");
    printf("Todo esto es al pedo porque arr ya es un puntero, entonces puedo hacer arr[1] o *(arr+1) y es lo mismo que hacer arr[1].\n");
    printf("Pero no puedo hacer arr++ porque arr es un puntero constante, no puedo modificar su valor.\n");
    return 0;
}