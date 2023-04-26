#include <msp430.h> 

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



    WDTCTL = WDTPW | WDTHOLD; // stop watchdog timer
    P1DIR |= LED_GREEN_MSK; // configure Pin as output
    P1OUT =  LED_GREEN_MSK; // initial state

    volatile unsigned int i;

    while(1)
    {
	        P1OUT ^= LED_GREEN_MSK; // Toggle PIN
	        for(i=20000; i>0; i--) {} //  Some delay
    }


	// return 0;
}
