/**
 * Simple blink
 * For MSP-EXP430G2 LaunchPad boards to run on a MSP430G2553 MCU
 */

#include <msp430.h>

// On Board User Leds
#define LED_GREEN_MSK    (1<<6) // P1.6

#define LED_RED_MSK     (1<<0) // P1.0


void main(void)
{

    WDTCTL = WDTPW | WDTHOLD; // stop watchdog timer
    P1DIR |= LED_GREEN_MSK; // configure Pin as output
    P1OUT =  LED_GREEN_MSK; // initial state

    volatile unsigned int i;

    while(1)
    {
        P1OUT ^= LED_GREEN_MSK; // Toggle PIN
        for(i=10000; i>0; i--) {} //  Some delay
    }
}
