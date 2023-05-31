/***************************************************************************//**
  @file     board.h
  @brief    Board management
  @author   Nicol�s Magliola
 ******************************************************************************/

#ifndef _BOARD_H_
#define _BOARD_H_

/*******************************************************************************
 * INCLUDE HEADER FILES
 ******************************************************************************/

#include "gpio.h"


/*******************************************************************************
 * CONSTANT AND MACRO DEFINITIONS USING #DEFINE
 ******************************************************************************/

// Display
#define Disp_a PORTNUM2PIN(1,0)
#define Disp_b PORTNUM2PIN(1,1)
#define Disp_c PORTNUM2PIN(1,2)
#define Disp_d PORTNUM2PIN(1,3)
#define Disp_e PORTNUM2PIN(1,4)
#define Disp_f PORTNUM2PIN(1,5)
#define Disp_g PORTNUM2PIN(1,6)

// selector display
#define Disp_sel0 PORTNUM2PIN(2,0)
#define Disp_sel1 PORTNUM2PIN(2,1)

// Encoder
#define ENC_A_PIN PORTNUM2PIN(2, 2)
#define ENC_B_PIN PORTNUM2PIN(2, 3)

// Selector leds
#define Status0 PORTNUM2PIN(2, 4)
#define Status1 PORTNUM2PIN(2, 5)

// Switch
#define BUTTON_PIN PORTNUM2PIN(1, 7)

#define SWITCH_INPUT        INPUT_PULLUP
#define SWITCH_ACTIVE       LOW


/*******************************************************************************
 * ENUMERATIONS AND STRUCTURES AND TYPEDEFS
 ******************************************************************************/

/*******************************************************************************
 * VARIABLE PROTOTYPES WITH GLOBAL SCOPE
 ******************************************************************************/

/*******************************************************************************
 * FUNCTION PROTOTYPES WITH GLOBAL SCOPE
 ******************************************************************************/



/*******************************************************************************
 ******************************************************************************/

#endif // _BOARD_H_
