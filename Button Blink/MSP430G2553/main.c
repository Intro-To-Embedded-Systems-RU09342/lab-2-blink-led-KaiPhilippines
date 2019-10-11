//******************************************************************************
//  MSP430FR6989 - Toggle P1.0 with Button Blink P1.3
//
//   Kyle Limbaga
//   Rowan University
//   Date Started: September 12, 2019
//   Date Updated: September 19, 2019
//******************************************************************************

#include <msp430.h> 


int main(void)
{
    WDTCTL = WDTPW | WDTHOLD;   // stop watchdog timer

    P1DIR = BIT0;              // P1.0 becomes the output pin. LED1
    P1REN = BIT3;              // The internal resistor is enabled so Button1 can be used
    P1OUT = BIT3;              // Button P1.3 is set as an input pin


    while(1)    //infinite loop
    {
        if (P1IN & BIT3)                // if button is not pressed...
        {
            P1OUT &= ~BIT0;
        }

        else if(~(P1IN & BIT3))         // if button is pressed...
        {
            P1OUT ^= BIT0;
            __delay_cycles(100000);     //delays 1MHz
        }


    }
}
