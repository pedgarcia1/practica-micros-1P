#include <msp430.h>

// MSP430G2553 Board definitions
#define B0 0
#define B1 1
#define B2 2
#define B3 3
#define B4 4
#define B5 5
#define B6 6
#define B7 7
#define PIN0 0x01
#define PIN1 0x02
#define PIN2 0x04
#define PIN3 0x08
#define PIN4 0x10
#define PIN5 0x20
#define PIN6 0x40
#define PIN7 0x80
// On Board User Leds
#define RED_LED B0 //P1.0
#define GREEN_LED B6 //P1.6
// On Board User Switches
#define SW1 B3 //P1.3
// Usefull Defs
#define LED_PORT P1OUT
#define LED_PORT_DIR P1DIR
#define LED_PORT_FUNCTION_SELECT_0 P1SEL0
#define LED_PORT_FUNCTION_SELECT_1 P1SEL1 
#define SW_PORT P1OUT
#define SW_PORT_IN P1IN
#define SW_PORT_DIR P1DIR
#define SW_PORT_PULL_ENABLE P1REN
#define SW_PORT_PULL_TYPE P1OUT
#define PULL_UP 0x01
#define PULL_DOWN 0x00
#define PULL_ENABLE 0x01
#define PULL_DISABLE 0x00
#define mask(x) (1<<(x))
#define set_alternate_pin_function_port1(function,pin) { P1SEL|=((!!(function & 0x01))<<pin);\
                                                         P1SEL2|=((!!(function & 0x02))<<pin);}

#define ALT0 0
#define ALT1 1
#define ALT2 2
#define ALT3 3
/*Timer Useful definitions*/
/* Timer Counter Modes */
#define TIMER_STOP MC_0 // Stop
#define TIMER_UP MC_1 // Up to CCR0
#define TIMER_CONTINUOUS MC_2 // Up to 0xFFFF
#define TIMER_UPDOWN MC_3 // Up to CCR0 Down to 0
#define TASSEL__SMCLK TASSEL_2
#define ID__8 ID_3
/**
 * main.c
 */
int main(void)
{
 WDTCTL = WDTPW | WDTHOLD; // stop watchdog timer
 /* Use Calibration values for 1MHz Clock DCO*/
 DCOCTL = 0;
 BCSCTL1 = CALBC1_8MHZ;
 DCOCTL = CALDCO_8MHZ;

 set_alternate_pin_function_port1(ALT1,6); // Selecting TA0.1 on P1.6
 P1DIR|=PIN6;

 LED_PORT &= ~(1<<RED_LED); //Turn off red led
 LED_PORT_DIR |= (1<<RED_LED); //Set red led Pin as output (Not Used in this example)

 TA0CCTL1=OUTMOD_7 | CCIE;
 TA0CCR0=1000;
 TA0CCR1=300; // Set Duty Cycle to 30% (300 micro seconds)

 TA0CTL=TASSEL__SMCLK | TIMER_UP | ID__8 ; // ID__8 sets ID_3 (clock divider 8 --> 1MHz)
 _BIS_SR(GIE);

 while(1){
 // Empty main
 }

}