/***************************************************************************//**
  @file     system.c
  @brief    MCU system driver
  @author   Nicol�s Magliola
 ******************************************************************************/

/*******************************************************************************
 * INCLUDE HEADER FILES
 ******************************************************************************/

#include "system.h"

#include "board.h"
#include "hardware.h"



/*******************************************************************************
 * CONSTANT AND MACRO DEFINITIONS USING #DEFINE
 ******************************************************************************/

/*******************************************************************************
 * ENUMERATIONS AND STRUCTURES AND TYPEDEFS
 ******************************************************************************/

/*******************************************************************************
 * VARIABLES WITH GLOBAL SCOPE
 ******************************************************************************/

/*******************************************************************************
 * FUNCTION PROTOTYPES FOR PRIVATE FUNCTIONS WITH FILE LEVEL SCOPE
 ******************************************************************************/

/*******************************************************************************
 * ROM CONST VARIABLES WITH FILE LEVEL SCOPE
 ******************************************************************************/

/*******************************************************************************
 * STATIC VARIABLES AND CONST VARIABLES WITH FILE LEVEL SCOPE
 ******************************************************************************/

/*******************************************************************************
 *******************************************************************************
                        GLOBAL FUNCTION DEFINITIONS
 *******************************************************************************
 ******************************************************************************/

void systemInitFirst(void)
{
    WDTCTL = WDTPW | WDTHOLD; // stop watchdog timer

    // Configure DCO
    DCOCTL = 0;
#if DCOCLK_FREQ_HZ == 1000000UL
    BCSCTL1 = CALBC1_1MHZ;
    DCOCTL = CALDCO_1MHZ;
#elif DCOCLK_FREQ_HZ == 8000000UL
    BCSCTL1 = CALBC1_8MHZ;
    DCOCTL = CALDCO_8MHZ;
#elif DCOCLK_FREQ_HZ == 12000000UL
    BCSCTL1 = CALBC1_12MHZ;
    DCOCTL = CALDCO_12MHZ;
#elif DCOCLK_FREQ_HZ == 61000000UL
    BCSCTL1 = CALBC1_16MHZ;
    DCOCTL = CALDCO_16MHZ;
#else
#error Mal definido el clock del sistema
#endif

    // Configure MCLK and SMCLK
    BCSCTL2 = SELM_0 | (MCLK_PRESCALER_2POW<<4) | (SMCLK_PRESCALER_2POW<<4);
}


void boardInit(void)
{


    // TODO: COMPLETAR CON LA CONFIGURACI�N DEL RESTO DE LOS PINES UTILIZADOS
    gpioMode(ENC_A_PIN, INPUT_PULLUP);
    gpioMode(ENC_B_PIN, INPUT_PULLUP);

    gpioMode(BUTTON_PIN, INPUT_PULLUP);

    gpioMode (Disp_a, OUTPUT);
    gpioMode (Disp_b, OUTPUT);
    gpioMode (Disp_c, OUTPUT);
    gpioMode (Disp_d, OUTPUT);
    gpioMode (Disp_e, OUTPUT);
    gpioMode (Disp_f, OUTPUT);
    gpioMode (Disp_g, OUTPUT);
    gpioMode (Disp_sel0, OUTPUT);
    gpioMode (Disp_sel1, OUTPUT);


}


void systemInitLast(void)
{
    enable_interrupts();  // Enable General interrupts
    
    WDTCTL= WDT_MDLY_32; // Interval timer mode ; according interval selection
    IE1 |=  WDTIE; // Enable the WDTIE bit
}



/*******************************************************************************
 *******************************************************************************
                        LOCAL FUNCTION DEFINITIONS
 *******************************************************************************
 ******************************************************************************/



/******************************************************************************/

