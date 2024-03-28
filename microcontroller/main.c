#ifndef F_CPU
	#define F_CPU 16000000 // clock speed is 16MHz
#endif
#define __AVR_atmega644p__
#define PB1 PORTB

#include <avr/io.h>
#include <util/delay.h>

int main(void) {
	DDRB = 0xFF; // declared port D as output
	
	while (1) { // initialize infinite while loop
		//PORTB = 0b1111101; // turn on all LEDs of PORTD
		PORTB = 0b0000010; // turn on all LEDs of PORTD
		//PORTB = 0x04 // 0x04 = 0b00000100; // turn on all LEDs of PORTD
		_delay_ms(100); // delay of one second

		PORTB = 0b0000000; // turn off all LEDs of PORTD
		_delay_ms(100); // delay of one second
	} // while loop end
} // main end



/*

0b 0000 0000      ingen
0b 0000 0010      2
0b 0000 0011      2 og 1
0b 0000 0100	  3



*/
