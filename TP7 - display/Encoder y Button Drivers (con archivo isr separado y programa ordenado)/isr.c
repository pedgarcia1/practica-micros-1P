/***************************************************************************//**
  @file     +Nombre del archivo (ej: template.c)+
  @brief    +Descripcion del archivo+
  @author   +Nombre del autor (ej: Salvador Allende)+
 ******************************************************************************/

/*******************************************************************************
 * INCLUDE HEADER FILES
 ******************************************************************************/

// +Incluir el header propio (ej: #include "template.h")+
#include "isr.h"
#include "hardware.h"

/*******************************************************************************
 * CONSTANT AND MACRO DEFINITIONS USING #DEFINE
 ******************************************************************************/



/*******************************************************************************
 * ENUMERATIONS AND STRUCTURES AND TYPEDEFS
 ******************************************************************************/



typedef struct
{
  void (*function_ptr)(void);
  unsigned int counter_reset;
  unsigned int counter;
} isr_t;


/*******************************************************************************
 * VARIABLES WITH GLOBAL SCOPE
 ******************************************************************************/

// +ej: unsigned int anio_actual;+


/*******************************************************************************
 * FUNCTION PROTOTYPES FOR PRIVATE FUNCTIONS WITH FILE LEVEL SCOPE
 ******************************************************************************/

// +ej: static void falta_envido (int);+


/*******************************************************************************
 * ROM CONST VARIABLES WITH FILE LEVEL SCOPE
 ******************************************************************************/

// +ej: static const int temperaturas_medias[4] = {23, 26, 24, 29};+


/*******************************************************************************
 * STATIC VARIABLES AND CONST VARIABLES WITH FILE LEVEL SCOPE
 ******************************************************************************/

// +ej: static int temperaturas_actuales[4];+


static isr_t *vector_ptr;
static unsigned int length = 0;
/*******************************************************************************
 *******************************************************************************
                        GLOBAL FUNCTION DEFINITIONS
 *******************************************************************************
 ******************************************************************************/

void send_to_isr (void(*function)(void), unsigned int period) {

    isr_t *vector_ptr_copy = realloc(vector_ptr, (length+1)*sizeof(isr_t));

    if (vector_ptr_copy != NULL) {
        vector_ptr = vector_ptr_copy;
        vector_ptr[length].function_ptr = function;
        vector_ptr[length].counter_reset = period;
        vector_ptr[length].counter = period;
        length++;
    }
    else {
        free(vector_ptr_copy);
    }
}

/*******************************************************************************
 *******************************************************************************
                        LOCAL FUNCTION DEFINITIONS
 *******************************************************************************
 ******************************************************************************/


#pragma vector = WDT_VECTOR
__interrupt void WDT_ISR(void) {

    unsigned int i;
    for(i = 0; i <= length; i++) {
        vector_ptr[i].counter--;
        if (!vector_ptr[i].counter) {
            vector_ptr[i].function_ptr();
            vector_ptr[i].counter = vector_ptr[i].counter_reset;
        }
    }
}


