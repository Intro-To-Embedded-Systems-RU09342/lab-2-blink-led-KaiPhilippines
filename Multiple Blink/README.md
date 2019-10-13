# Multiple Blink
Blinked two LEDs at two different rates. One of the LED is toggling twice the rate of the other one.


# Implementation
Most of the code is from the simple blink exercise, including stopping the watchdog timer WDTCTL = WDTPW | WDTHOLD; disabling default GPIO mode for FR6989 with the line PM5CTL0 = ~LOCKLPM5, which disables the default high impedence on board. and setting up the registers. All that was changed was the additional P1DIR to BIT6 and additional if statement with different count. This count is up to 500 making it blink twice as the other one.
