//******************************************************************************
//  MSP430FR6989 - Toggle P1.0 with Button Blink P1.1
//
//
//   Kyle Limbaga
//   Rowan University
//   Date Started: September 12, 2019
//   Date Updated: September 19, 2019
//******************************************************************************

#include <msp430.h> 

unsigned int blink = 0;

int main(void)
{
    WDTCTL = WDTPW | WDTHOLD;   // stop watchdog timer

    P1DIR = BIT0;              // P1.0 becomes the output pin. LED1
    P1REN = BIT1;              // The internal resistor is enabled so Button1 can be used
    P1OUT = BIT1;              // Button P1.1 is set as an input pin

    PM5CTL0 &= ~LOCKLPM5;

    while(1)    //loops
    {
        if (P1IN & BIT1)        //if button is not pressed
        {
            P1OUT &= ~BIT0;     //LED is off
        }

        else if(~(P1IN & BIT1)) //if button is pressed
        {
            P1OUT ^= BIT0;      //LED is on

            __delay_cycles(100000);     //delays 1MHz
        }


    }
}
