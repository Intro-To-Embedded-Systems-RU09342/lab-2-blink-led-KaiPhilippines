# Button Blink
A button is used as a switch and the LED will blink if the button is pressed. 

# Implementation
Similar to the other labs, the watchdog timer needs to be disabled again with the line WDTCTL = WDTPW | WDTHOLD. The default high impedence need to be disabled by using the line PM5CTL0 &= ~LOCKLPM5; for the FR6989. This high impedance serves to get rid of any cross currents. While(1) keeps the program in the loop forever. if (PXIN & BITX) is the if condition which will check if a button is not pressed. The line else if (~(P1IN & BIT3)) will check if the button is pressed and will Blink the LED at rate of 1 MHz.
