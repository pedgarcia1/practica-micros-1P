/***************************************************************************//**
  @file     gol.h
  @brief    Header for Game of Life back-end
  @author   Nicolás Magliola
 ******************************************************************************/

#ifndef _BACK_H_
#define _BACK_H_

/*******************************************************************************
 * INCLUDE HEADER FILES
 ******************************************************************************/

#include<stdio.h>
#include<stdint.h>
#include<stdlib.h>
#include<time.h>

/*******************************************************************************
 * CONSTANT AND MACRO DEFINITIONS USING #DEFINE
 ******************************************************************************/

enum { DEAD, ALIVE };
enum { FALSE, TRUE };


/*******************************************************************************
 * ENUMERATIONS AND STRUCTURES AND TYPEDEFS
 ******************************************************************************/
typedef struct
{
    int *newW;
    int *oldW;
    int fil;
    int col; 
} mundo_t; 

/*******************************************************************************
 * VARIABLE PROTOTYPES WITH GLOBAL SCOPE
 ******************************************************************************/

/*******************************************************************************
 * FUNCTION PROTOTYPES WITH GLOBAL SCOPE
 ******************************************************************************/

/**
 * @brief Creates a world of width (x) and height (y).
 * All cells are set to DEAD or ALIVE
 * @param x World's width
 * @param y World's height
 * @return If creation was success (true / false)
*/
void gol_CreateWorld(mundo_t *ptr_mundo, int n, int m );




/**
 * @brief Updates world state to next generation according to
 * game's rules
*/
void gol_EvolveWorld( mundo_t* ptr );


/**
 * @brief Copys newT (new tablero) to oldT (old tablero)
*/
void gol_CopyWorld(mundo_t* ptr_mundo);


/*******************************************************************************
 ******************************************************************************/

#endif // _BACK_H_





