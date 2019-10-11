//******************************************************************************
//  MSP430FR6989 - Toggle P1.0 and P9.7 LED Multiple Blink
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

    // Configure GPIO
    P1DIR |= BIT0;                          // Clear P1.0 output latch for a defined power-on state
    P1OUT |= BIT0;                          // Set P1.0 to output direction

    P9DIR |= BIT7;                          // Clear P9.7 output latch for a defined power-on state
    P9OUT |= BIT7;                          // Set P9.7 to output direction

    PM5CTL0 &= ~LOCKLPM5;                   // Disable the GPIO power-on default high-impedance mode
                                            // to activate previously configured port settings

    while(1)
    {
        if (count % 1000 == 0){             // Once the counter reaches 1000 the LED turns on
        P1OUT ^= BIT0;                      // Toggle LED Red
        }

        if (count % 500 == 0){              // Counter reaches 500, the LED turns on
        P9OUT ^= BIT7;                      // Toggle LED Green
        }
        count++;
    }
}
