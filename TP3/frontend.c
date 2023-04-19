#include "frontend.h"
//* FRONT END *//

/***********************************
 *    PREGUNTAR SI SE CONTINUA     *
***********************************/
int gol_iterFlag(void) {
    int c;
    printf("Para continuar presione Enter.\n\n");
    printf("Para terminar presione q y luego Enter.\n");
    do {
        c = getchar();
    } while (c != '\n' && c != 'q');

    if (c == 'q') 
        return 0;
    else {
        printf("\n\n\n\n\n");
        return 1;
    }
        
}


/* GLOBAL FUNCTION DEFINITIONS */

/***********************************
 *    OBTENER ALTURA DEL MUNDO     *
***********************************/
int get_h(void){
    
    int h;
    printf("Ingrese el alto: ");
    scanf("%d", &h);
    printf("\n");
    while(h<2){
    printf("Valor invalido, Ingrese el alto mayor a 2: ");
    scanf("%d", &h); 
    printf("\n");   
    }
    return h;
}

/***********************************
 *     OBTENER ANCHO DEL MUNDO     *
***********************************/
int get_w(void){
    
    int w;
    printf("Ingrese el ancho: ");
    scanf("%d", &w);
    printf("\n");
    while(w<2){
    printf("Valor invalido, Ingrese el ancho mayor a 2: ");
    scanf("%d", &w);    
    printf("\n");
    }
    return w;
}

/***********************************
 *        MOSTRAR EL MUNDO         *
***********************************/
void gol_printWorld(mundo_t* ptr_mundo)
{
    for (int i = 1; i < ptr_mundo->fil-1; i++) {
    for (int j = 1; j < ptr_mundo->col-1; j++) {
        if (ptr_mundo->oldW[i * ptr_mundo->col + j] == 1) {
            printf("| * ");
        } else if (ptr_mundo->oldW[i * ptr_mundo->col + j] == 0) {
            printf("| 0 ");
        }
        if (j == ptr_mundo->col-2) {
            printf("|\n");
        }
    }
    if (i != ptr_mundo->fil - 2) {
        for (int j = 1; j < ptr_mundo->col-1; j++) {
            printf("+---");
            if (j == ptr_mundo->col-2) {
                printf("+\n");
            }
        }
    }
}
printf("\n");
}

