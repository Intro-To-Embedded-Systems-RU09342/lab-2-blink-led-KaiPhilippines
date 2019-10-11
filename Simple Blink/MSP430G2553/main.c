//******************************************************************************
//  MSP430G2553 - Toggle P1.0 Simple Blink
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

       P1DIR |= BIT0;       // Clear P1.0 output latch for a defined power-on state
       P1OUT |= BIT0;       // Set P1.0 to output direction

       while(1)
       {
           if (count % 1000 == 0){  // if count reaches 1000...
           P1OUT ^= BIT0;       // Toggle LED by masking with BIT0 and xoring P1OUT
           count = 0;   //Reset the counter
       }
           count++;   //Increments
   }

}
