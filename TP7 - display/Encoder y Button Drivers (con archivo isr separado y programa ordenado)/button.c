
/**
 * @file     button.c
 * @brief    Driver para control de un boton conectado a un pin digital
 * @author   Teo Nicoletti
 */


/** INCLUDE HEADER FILES **/
#include "button.h"
#include "gpio.h"
#include "board.h"




/* CONSTANT AND MACRO DEFINITIONS USING #DEFINE */



/* ENUMERATIONS AND STRUCTURES AND TYPEDEFS */



/* VARIABLES WITH GLOBAL SCOPE 
 * +ej: unsigned int anio_actual;*/


/* FUNCTION PROTOTYPES FOR PRIVATE FUNCTIONS WITH FILE LEVEL SCOPE
 * +ej: static void falta_envido (int);+ */


/** ROM CONST VARIABLES WITH FILE LEVEL SCOPE
 * +ej: static const int temperaturas_medias[4] = {23, 26, 24, 29};+ */


/** STATIC VARIABLES AND CONST VARIABLES WITH FILE LEVEL SCOPE
// +ej: static int temperaturas_actuales[4];+ */

volatile uint8_t button_now, button_pressed_flank, button_before;

/* GLOBAL FUNCTION DEFINITIONS */

void buttonInit(void){

}

uint8_t buttonGetStatus(void){
    button_now = gpioRead(BUTTON_PIN);
    button_pressed_flank = (button_now ^ 1) && button_before;
    button_before = button_now;
    return button_pressed_flank;

}


/* LOCAL FUNCTION DEFINITIONS */


