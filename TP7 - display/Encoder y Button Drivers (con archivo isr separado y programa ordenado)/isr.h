/**
 * @file     isr.h
 * @brief    header file for isr. Extern flags declaration.
 * @author   Teo Nicoletti
 */

#ifndef _ISR_H_
#define _ISR_H_

/* INCLUDE HEADER FILES */

#include "common.h"

/* CONSTANT AND MACRO DEFINITIONS USING #DEFINE */



/* ENUMERATIONS AND STRUCTURES AND TYPEDEFS */



/* VARIABLES WITH GLOBAL SCOPE 
 * +ej: unsigned int anio_actual;*/


extern volatile uint8_t buttonPressedFlag, CWTurnFlag, CCWTurnFlag;

/* FUNCTION PROTOTYPES WITH GLOBAL SCOPE */

void isrInit(void);

/**
 * @brief TODO: completar descripcion
 * @param param1 Descripcion parametro 1
 * @param param2 Descripcion parametro 2
 * @return Descripcion valor que devuelve
*/
// +ej: char lcd_goto (int fil, int col);+

#endif // _ISR_H_
