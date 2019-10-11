//******************************************************************************
//  MSP430G2553 - Toggle Off Board LED
//
//   Kyle Limbaga
//   Rowan University
//   Date Started: September 12, 2019
//   Date Updated: September 18, 2019
//******************************************************************************

#include <msp430.h>

unsigned int count = 0;

int main(void)
{
    WDTCTL = WDTPW | WDTHOLD;               // Stop WDT

    P2SEL &= ~BIT2; // Select I/O function for P1.0 by masking with LED1 and clearing P2SEL
    P2DIR |= BIT2;  // Change P1.0 to an output by masking with LED1 and setting P2DIR
    P2OUT &= ~BIT2; // Clear P1.0 (turn LED1 off) by masking with LED1 and clearing P2OUT

    P2DIR |= BIT3;  //Change P1.3 to output
    P2OUT &= ~BIT3; //Clears P1.3


    while(1)
    {
        if (count % 1000 == 0){                 // blinks slower
            P2OUT ^= BIT2;                      // Toggle LED1
        }
        if (count % 500 == 0){                  //blinks faster
            P2OUT ^= BIT3;                      //Toggle LED2
        }

        count++;
    }
}
