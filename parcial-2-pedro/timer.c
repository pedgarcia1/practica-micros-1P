#include "timer.h"
#include <msp430.h>

#define BITSET(d,b) ((d) |= 1U << (b))
#define BITCLR(d,b) ((d) &= ~(1U << (b)))

void timerStop(void)
{
 TA0CTL = TASSEL_2; // Stop timer.
}
void timerStart(void)
{
 TA0CTL = TASSEL_2 | MC_1; // Start timer.
}

void timerInitialization(uint32_t period, uint32_t cycleTime)
{
 
 DCOCTL = CALDCO_1MHZ; // Clock 1 MHz.
 BCSCTL1 = CALBC1_1MHZ;
 BCSCTL2 = 0; // DCO as source for MCLK and SMCLK.

 // Select function TA0.1 at pin P1.6 (TA0CCR1).
 BITSET(P1DIR, 6); // Set pin as output.
 BITSET(P1SEL, 6); // Select timer function.
 BITCLR(P1SEL2,6);

 // Configure Timer_A0.
 TA0CTL = TASSEL_2; // SMCLK source, no divs, stop mode, no interrupt
 
 TA0CCR0 = period; // PWM Period.
 TA0CCTL0 = 0; 
 
 TA0CCR1 = cycleTime; // Time ON
 TA0CCTL1 = OUTMOD_7; // Reset/set mode
}



