#include <msp430.h> 
#include <time.h>
/**
 * main.c
 */
void main(void)
{
	/**
	 * Simple blink
	 * For MSP-EXP430G2 LaunchPad boards to run on a MSP430G2553 MCU
	 */

	// On Board User Leds
	#define LED_GREEN_MSK    (1<<6) // P1.6
    #define PIN_MSK    (1<<5) // P1.5
    #define RED_GREEN_MSK (1<<0)

    // srand(time(NULL)); // inicio semilla rand

    WDTCTL = WDTPW | WDTHOLD; // stop watchdog timer
    P1DIR |= LED_GREEN_MSK ^ RED_GREEN_MSK ^ PIN_MSK; // configure Pin as output
    P1OUT =  LED_GREEN_MSK ^ RED_GREEN_MSK ^ PIN_MSK; // initial state


    volatile unsigned int i;
    volatile unsigned int iter;
    volatile unsigned int frecuencia = 100;
    iter = 20000*2.59/frecuencia;


    while(1)
    {
        if(1)
        {
	        P1OUT ^= LED_GREEN_MSK; // Toggle PIN
        }
        if(1)
        {
            P1OUT ^= RED_GREEN_MSK;
            // P1OUT ^= PIN_MSK;
        }
	        for(i=iter; i>0; i--) {} //  Some delay
    }


	// return 0;
}