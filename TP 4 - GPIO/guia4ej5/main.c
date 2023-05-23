#include <msp430.h> 


/**
 * main.c
 */


#define RED_MSK (1<<0)
#define GREEN_MSK (1<<6)
#define S2_MSK (1<<3)


int main(void)
{
	WDTCTL = WDTPW | WDTHOLD;	// stop watchdog timer

	P1DIR |= RED_MSK | GREEN_MSK; // Defino los leds como output

	P1DIR &= (~S2_MSK); // Defino pulsador S2 como entrada
	P1REN |= S2_MSK; // Habilito que el boton se pueda leer como pull up o pull down.
	P1OUT |= S2_MSK; // Defino que el botton se lea como pull up. (El boton apretado es 0, si ademas le pongo pull up entonces no hace nada, entonces lo tengo que definir si o si como pull up)


	volatile unsigned int i;
	char puls_actual, puls_anterior;

	while(1){
        puls_actual = (P1IN & S2_MSK); // Copio el valor actual del pulsador
        if ((puls_actual == 0) & (puls_anterior == S2_MSK)){ // Si esta apretado y antes no estaba apretado entra
            P1OUT ^= RED_MSK; // toggle
        }
        puls_anterior = puls_actual;
        for(i = 0; i<10000; i++) {} // agrego delay porque sino a veces hace cosas raras.
	}

	return 0;
}
