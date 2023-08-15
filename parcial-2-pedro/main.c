#include "timer.h"
#include <msp430.h>  

int main(void)
{
 
 WDTCTL = WDTPW | WDTHOLD; // Stop watch dog timer.
 
 timerInitialization(20000, 1500); // PWM 20 ms period, 1.5 ms ON time (7.5% duty cycle).
 
 timerStart();  // Start PWM.

 while(1)
 {
    // Empty main
 }

 
}