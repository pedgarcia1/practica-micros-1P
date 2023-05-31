/***************************************************************************//**
  @file     system.h
  @brief    MCU system driver
  @author   Nicol�s Magliola
 ******************************************************************************/

#ifndef _SYSTEM_H_
#define _SYSTEM_H_

/*******************************************************************************
 * INCLUDE HEADER FILES
 ******************************************************************************/

#include "common.h"


/*******************************************************************************
 * CONSTANT AND MACRO DEFINITIONS USING #DEFINE
 ******************************************************************************/

/*******************************************************************************
 * ENUMERATIONS AND STRUCTURES AND TYPEDEFS
 ******************************************************************************/

/*******************************************************************************
 * VARIABLE PROTOTYPES WITH GLOBAL SCOPE
 ******************************************************************************/

/*******************************************************************************
 * FUNCTION PROTOTYPES WITH GLOBAL SCOPE
 ******************************************************************************/

/**
 * @brief Initialize system first: internal MCU stuffs (clock, watchdog, etc.)
 */
void systemInitFirst(void);


/**
 * @brief Initialize board: MCU - board interface stuffs (pinout, etc.)
 */
void boardInit(void);


/**
 * @brief Initialize system last: internal MCU stuffs (ISR, etc.)
 */
void systemInitLast(void);



/*******************************************************************************
 ******************************************************************************/

#endif // _SYSTEM_H_
