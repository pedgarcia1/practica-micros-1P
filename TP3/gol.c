#include "frontend.h"

int main()
{
// Creo una estructura tipo mundo_t
mundo_t mundo;
mundo_t *ptr_mundo = &mundo;

// Pregunto altura y ancho al front end
int x,y;
y = get_w();
x = get_h();

// Reservo memoria para la matriz, agregando 2 filas y 2 columnas extra para llenar con -1 (Borde) newW
void *ptr_malloc_1 = calloc((x+2)*(y+2),sizeof(int));
ptr_mundo->newW = ptr_malloc_1;
// Reservo para oldW
void *ptr_malloc_2 = calloc((x+2)*(y+2),sizeof(int));
ptr_mundo->oldW = ptr_malloc_2; 
// Llamo al Back-End para crear el mudno, pasandole el puntero a la estructura
gol_CreateWorld(ptr_mundo,x,y);


char Continueflag = TRUE;
// Empieza el juego, mientras el usuario envie enter se evoluciona, si aprieta q termina
do
{
    gol_printWorld(ptr_mundo);
    
    Continueflag = gol_iterFlag();

    gol_EvolveWorld(ptr_mundo);
    
} while (Continueflag);
// al terminar se borra el mundo

free(ptr_malloc_1);
free(ptr_malloc_2);
return 0;
}
