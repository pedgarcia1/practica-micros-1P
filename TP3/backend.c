#include "backend.h"

/***********************************
 *          CREAR EL MUNDO         *
***********************************/
void gol_CreateWorld(mundo_t *ptr_mundo, int n, int m ) 
{

    srand(time(NULL)); // inicio semilla rand

    ptr_mundo->fil = n+2; //defino numero filas
    ptr_mundo->col = m+2; // defino numero columnas

    // recorro el vector como matriz, poniendo -1 en los bordes y 0 o 1 en los demas casilleros (0=DEAD, 1=ALIVE)
    for (int i = 0; i < ptr_mundo->fil; i++)
    {
        for (int j = 0; j < ptr_mundo->col; j++)
        {
            if (i == 0 || j == 0 || i == ptr_mundo->fil-1 || j == ptr_mundo->col-1)
            {
                ptr_mundo->newW[i*(ptr_mundo->col) + j] = -1;
            }else{
                ptr_mundo->newW[i*(ptr_mundo->col) + j] = rand()%2;
            }
            
        }
        
    }

    gol_CopyWorld(ptr_mundo);
    
}
    // Copia el newW en oldW 
void gol_CopyWorld(mundo_t* ptr_mundo)
{
    for (int i = 0; i < ptr_mundo->fil; i++)
    {
        for (int j = 0; j < ptr_mundo->col; j++)
        {
            ptr_mundo->oldW[i*(ptr_mundo->col) + j] = ptr_mundo->newW[i*(ptr_mundo->col) + j];
        }
        
    }
}

/***********************************
 *       EVOLUCIONAR EL MUNDO      *
***********************************/
// Evoluciona el mundo, recorriendo todos los elementos del tablero (no los bordes) y sus 8 vecinos para determinar su estado    
void gol_EvolveWorld( mundo_t* ptr )
{
    int col[] = {-1, -1, -1, 0, 0, 1, 1, 1};
    int fil[] = {-1, 0, 1, -1, 1, -1, 0, 1};
    int count;
    for (int i = 1; i < ptr->fil-1; i++)
    {
        for (int j = 1; j < ptr->col-1; j++)
        {
            for (int k = 0; k < 8; k++)
            {
                int posX,posY;
                posX=i+col[k];
                posY=j+fil[k];
                
                if (ptr->oldW[posX*(ptr->col) + posY] != -1 && ptr->oldW[posX*(ptr->col) + posY] == ALIVE)
                {
                    count++;
                }
            }

            if (ptr->oldW[i*(ptr->col) + j] == DEAD && ptr->oldW[i*(ptr->col) + j] != -1)
                {
                    if (count == 3)
                    {
                        ptr->newW[i*(ptr->col) + j] = ALIVE; 
                    }
                    
                }
            if (ptr->oldW[i*(ptr->col) + j] == ALIVE && ptr->oldW[i*(ptr->col) + j] != -1)
                {
                    if (count < 2 || count > 3)
                    {
                        ptr->newW[i*(ptr->col) + j] = DEAD;
                    }
                    
                }
            count = 0;
            
            
        }
        
    }
    
    gol_CopyWorld(ptr);
    
}
