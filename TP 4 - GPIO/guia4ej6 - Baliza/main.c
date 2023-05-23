#include <msp430.h> 

#define RED_MSK (1<<0)
#define BUTTON_MSK (1<<3)

/**
 * El programa tiene problemas con los tiempos en que se mantiene apretado el boton
 * porque el cpu queda ocupado mientras hace el delay para el led.
 */
int main(void)
{

	WDTCTL = WDTPW | WDTHOLD;	// stop watchdog timer
	P1OUT = 0;
	
	P1DIR |= RED_MSK; // red led as output
	P1DIR &= (~BUTTON_MSK); // button as input
	P1REN |= BUTTON_MSK; // button resistance enabled
	P1OUT |= BUTTON_MSK; // button input with pull up resistor (button connects to ground)
	volatile unsigned int actual, anterior, loop, i;
	anterior = 1;
	loop = 0;
	while (1)
	{
	    actual = (P1IN & BUTTON_MSK);
	    if ((actual == 0) & (anterior == BUTTON_MSK)){ loop = 1; }

	    while (loop) {

	        for (i=40000; i>1; i--){} // toggle delay
	        actual = (P1IN & BUTTON_MSK);
	        if ((actual == 0) & (anterior == BUTTON_MSK)){ loop = 0; }
	        P1OUT ^= RED_MSK; // led toggle
	        anterior = actual;

	    }
	    for (i=2000; i>1; i--){} // delay due to button bouncing
	    anterior = actual;
	}

	return 0;
}




