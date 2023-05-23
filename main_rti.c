#include <msp430.h>

// Create mask macros
#define pmsk(pin)   (1<<(pin))           // Create pin mask based on pin position
#define vmsk(val,pin) ((val)<<(pin))    // Create value mask based on pin position


#define B0 0
#define B1 1
#define B2 2
#define B3 3
#define B4 4
#define B5 5
#define B6 6
#define B7 7

// Port input resistors
#define PULL_UP     0x01
#define PULL_DOWN   0x00

#define PULL_ENABLE    0x01
#define PULL_DISABLE   0x00


// Port interrupts
#define Rising_Edge 0
#define Falling_Edge 1

// On Board User Leds
#define RED_LED    pmsk(B0)       //P1.0
#define GREEN_LED  pmsk(B6)       //P1.6

// On Board User Switches
#define Switch_1   pmsk(B3)       //P1.3
/**
 * Interrupt example Green led blinks continuously
 * When Switch 1 is pressed Red led toggles
 */


void main(void)
{
   WDTCTL = WDTPW | WDTHOLD;         // stop watchdog timer

   if (CALBC1_1MHZ != 0xFF)  // Calibrate oscilator
   {
           DCOCTL = 0; // Select lowest DCOx and MODx
           BCSCTL1 = CALBC1_1MHZ; // Set range
           DCOCTL = CALDCO_1MHZ; // Set DCO step + modulation
   }



    P1DIR |= (GREEN_LED | RED_LED);   // configure Pins as output
    P1OUT |= GREEN_LED;               // Only Green on
    WDTCTL = WDT_MDLY_32;              // 32ms interval
    IE1   |=  WDTIE;                  // Enable the WDTIE bit;

    _BIS_SR(GIE);         // Enable General interrupts

    volatile unsigned int i;        // volatile to prevent optimization

    while(1)
    {
        P1OUT ^= GREEN_LED;         // Toggle Green
        for(i=20000; i>0; i--);          // some delay
    }
}


#pragma vector = WDT_VECTOR             //Interval timer vector location
__interrupt void IntervalTimer(void)
{

           P1OUT^=RED_LED;              // Toggle led State
}

