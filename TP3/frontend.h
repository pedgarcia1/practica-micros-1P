/**
 * @file     +Nombre del archivo (ej: template.c)+
 * @brief    +Descripcion del archivo+
 * @author   +Nombre del autor (ej: Salvador Allende)+
 */

#ifndef _FRONTEND_H_
#define _FRONTEND_H_

/* INCLUDE HEADER FILES */
#include<stdio.h>
#include<stdlib.h>
#include"backend.h"

/* ENUMERATIONS AND STRUCTURES AND TYPEDEFS */


/* FUNCTION PROTOTYPES WITH GLOBAL SCOPE */
/**
 * @brief TODO: completar descripcion
 * @param param1 Descripcion parametro 1
 * @param param2 Descripcion parametro 2
 * @return Descripcion valor que devuelve
*/

int get_h(void);
int get_w(void);
void gol_printWorld(mundo_t* ptr_mundo);
int gol_iterFlag(void);

#endif // FRONTEND_H_
