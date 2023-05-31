
/**
 * @file     isr.c
 * @brief    Interrupt Service Routine handle
 * @author   Teo Nicoletti
 */


/** INCLUDE HEADER FILES
 * +Incluir el header propio (ej: #include "template.h")+ */
#include "isr.h"
#include "button.h"
#include "encoder.h"
#include "hardware.h"

/* CONSTANT AND MACRO DEFINITIONS USING #DEFINE */



/* ENUMERATIONS AND STRUCTURES AND TYPEDEFS */



/* VARIABLES WITH GLOBAL SCOPE 
 * +ej: unsigned int anio_actual;*/

volatile uint8_t buttonPressedFlag, CWTurnFlag, CCWTurnFlag;

/* FUNCTION PROTOTYPES FOR PRIVATE FUNCTIONS WITH FILE LEVEL SCOPE
 * +ej: static void falta_envido (int);+ */


/** ROM CONST VARIABLES WITH FILE LEVEL SCOPE
 * +ej: static const int temperaturas_medias[4] = {23, 26, 24, 29};+ */


/** STATIC VARIABLES AND CONST VARIABLES WITH FILE LEVEL SCOPE
// +ej: static int temperaturas_actuales[4];+ */


/* GLOBAL FUNCTION DEFINITIONS */
void isrInit(void){

}

/* LOCAL FUNCTION DEFINITIONS */

#pragma vector = WDT_VECTOR
__interrupt void general_isr(void){

    buttonPressedFlag = buttonGetStatus();
    
    switch(encoderGetStatus()){
             case CW:
                 CWTurnFlag = 1;
                 break;
             case CCW:
                 CCWTurnFlag = 1;
                 break;

}
}
 
