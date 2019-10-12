# Simple Blink
One of the on-board LED's is blinked at a particular rate. 

# Implementaion
Used the example code found in TI resources file msp430fr69xx_1.c. Using this code, I was able to blink the led at a particular rate with delays. In my code, instead of using delay cycle to change the rate for blink I used an if statement in a while loop with count+++. In each loop the count variable would increment. Each time it reaches 1000. the LED would be toggled by xor'ing the BIT0 in P1OUT. After it reaches 1000 the count would reset. 
There is a line of code that is necessary as the first step: WDTCTL = WDTPW + WDTHOLD; as this will disable the watchdog timer. The next step is disabling the default GPIO high-impedance mode. To do this, use this line of code: PM5CTL0 &= ~LOCKLPM5. This is only in the FR6989 though. 
