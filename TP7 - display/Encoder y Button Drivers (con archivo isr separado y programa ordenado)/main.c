/***************************************************************************//**
  @file     main.c
  @brief    Main file
  @author   Nicol�s Magliola
 ******************************************************************************/

/*******************************************************************************
 * INCLUDE HEADER FILES
 ******************************************************************************/

#include "system.h"
#include "button.h"
#include "gpio.h"
#include "encoder.h"
#include "board.h"
#include "isr.h"
#include "SSDisp.h"

/*******************************************************************************
 * ENUMERATIONS AND STRUCTURES AND TYPEDEFS
 ******************************************************************************/

/*******************************************************************************
 * VARIABLES WITH GLOBAL SCOPE
 ******************************************************************************/

/*******************************************************************************
 * FUNCTION PROTOTYPES FOR PRIVATE FUNCTIONS WITH FILE LEVEL SCOPE
 ******************************************************************************/

void AppInit (void);
void AppRun (void);


/*******************************************************************************
 * STATIC VARIABLES AND CONST VARIABLES WITH FILE LEVEL SCOPE
 ******************************************************************************/


/*******************************************************************************
 *******************************************************************************
                        GLOBAL FUNCTION DEFINITIONS
 *******************************************************************************
 ******************************************************************************/
static int pass[]={1,2,3,4};

int count=0;
int disp=0;
void main (void)
{ // NO TOCAR
    systemInitFirst();
    boardInit();
    AppInit();
    systemInitLast();

    for(;;)
        AppRun();
} // NO TOCAR


void AppInit (void)
{
    // setup (se ejecuta 1 sola vez al comienzo)
    // TODO: COMPLETAR CON LA INICIALIZACI�N DE DRIVERS Y APLICACI�N
    printDigit(count,0);

}


void AppRun (void)
{
    // loop (se ejecuta constantemente en un ciclo infinito)
    // TODO: COMPLETAR CON EL FUNCIONAMIENTO DEL PROGRAMA

    if(buttonPressedFlag) {
        buttonPressedFlag = LOW;
        count=0;
        disp++;
        printDigit(count,disp);
    }
    if(CWTurnFlag) {
        CWTurnFlag = LOW;
        count++;
        count %= 10;
        printDigit(count,disp);
    }
    if (CCWTurnFlag) {
        CCWTurnFlag = LOW;
        count--;
        if (count<0)
            count=9;
        count %= 10;
        printDigit(count,disp);

    }


}




/*******************************************************************************
 *******************************************************************************
                        LOCAL FUNCTION DEFINITIONS
 *******************************************************************************
 ******************************************************************************/


/******************************************************************************/
