//******************************************************************************
//  MSP430G2553 - Toggle P1.0 and P1.6  Multiple Blinks
//
//   Kyle Limbaga
//   Rowan University
//   Date Started: September 12, 2019
//   Date Updated: September 19, 2019
//******************************************************************************

#include <msp430.h>

unsigned int count = 0;

int main(void)
{
    WDTCTL = WDTPW | WDTHOLD;               // Stop WDT

    // Configure GPIO
    P1DIR |= BIT0;                          // Clear P1.0 output latch for a defined power-on state
    P1OUT |= BIT0;                          // Set P1.0 to output direction

    P1DIR |= BIT6;                          // Clear P9.7 output latch for a defined power-on state
    P1OUT |= BIT6;                          // Set P9.7 to output direction


    while(1)
    {
        if (count % 1000 == 0){             // counts up to 1000, blinks slower
        P1OUT ^= BIT0;                      // Toggle LED Red
        }

        if (count % 500 == 0){              // counts up to 500, blinks faster
        P1OUT ^= BIT6;                      // Toggle LED Green
        }
        count++;
    }
}
