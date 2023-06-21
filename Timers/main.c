// #include <msp430.h>
#include "msp430g2553.h" 

/* Timer overflow interrupt example
 * Timer counter is in UP continuous mode i.e. (0-0xFFFF)
 * Red led is toggled on overflow every 0.5 seg
 * Simultaneously CCRO interrupt toggles Green LED
 *
 *
 */

// MSP-EXP430FR2433 Board definitions

#define B0 0
#define B1 1
#define B2 2
#define B3 3
#define B4 4
#define B5 5
#define B6 6
#define B7 7

// On Board User Leds
#define RED_LED    B0       //P1.0
#define GREEN_LED  B1       //P1.1

// On Board User Switches

#define SW1  B3       //P2.3
#define SW2  B7       //P2.7

// Usefull Defs

#define LED_PORT P1OUT
#define LED_PORT_DIR P1DIR

#define LED_PORT_FUNCTION_SELECT_0   P1SEL0
#define LED_PORT_FUNCTION_SELECT_1   P1SEL1


#define SW_PORT P2OUT
#define SW_PORT_IN P2IN
#define SW_PORT_DIR P2DIR
#define SW_PORT_PULL_ENABLE P2REN
#define SW_PORT_PULL_TYPE   P2OUT

#define PULL_UP     0x01
#define PULL_DOWN   0x00

#define PULL_ENABLE    0x01
#define PULL_DISABLE   0x00

#define mask(x)     (1<<(x))


/*Timer Useful definitions*/

/* Timer Counter Modes */
#define TIMER_STOP       MC_0   // Stop
#define TIMER_UP         MC_1   // Up to CCR0
#define TIMER_CONTINUOUS MC_2   // Up to 0xFFFF
#define TIMER_UPDOWM     MC_3   // Up to CCR0 Down to 0

/**
 * main.c
 */
int main(void)
{
    WDTCTL = WDTPW | WDTHOLD;   // stop watchdog timer
    PM5CTL0 &= ~LOCKLPM5;       // Disable the GPIO power-on default high-impedance mode
                                // to activate previously configured port settings

    LED_PORT &=  ~((1<<GREEN_LED) | (1<<RED_LED) );     //Turn off all leds
    LED_PORT_DIR |= ((1<<GREEN_LED) | (1<<RED_LED) );   //Set Led's Pins as output


    TA0CCTL0=CCIE;          // CCR0 interrupt enable
    TA0CCR0=5000;           // CCR0, limite de contador TA0CCTL0

//  Clk Source: SMCLK , Timer Counter: Up Continuous - divide by 8 - overflow interrupt enable

    TA0CTL = TASSEL__SMCLK  | TIMER_CONTINUOUS | TAIE | ID__8 ;
    TA0CTL = OUTMOD_0;
    TA0CTL ^= OUT;



 _BIS_SR(GIE);         // Enable General interrupts

    while(1){


    }


    return 0;
}



#pragma vector=TIMER0_A1_VECTOR        //Interrupt Service Routine (ISR) for overflow and CCR<1-n> TimerA0
__interrupt void isr_myoverflow(void)
{

    volatile int dummy;
              dummy=(TA0IV);            // Clear Interrupt flag

           LED_PORT^=(1<<RED_LED);      // Toggle led State 1/(2^20/(8*65535))=0.4999 seg

}


#pragma vector=TIMER0_A0_VECTOR        //Interrupt Service Routine (ISR) for CCR0 (only)
__interrupt void isr_myccr(void)
{
           TA0CCR0+=1000;              // Update next match
           LED_PORT^=(1<<GREEN_LED);   // Toggle led State 1/(2^20/(8*1000))=7.629ms

}

