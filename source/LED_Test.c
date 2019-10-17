#include <avr/io.h>
#ifdef _SIMULATE_
#include "simAVRHeader.h"
#endif

int main(void) {
    /* Insert DDR and PORT initializations */
	DDRA = 0x00; PORTA = 0xFF;  // input
	DDRC = 0xFF; PORTC = 0x00; // output
	
    /* Insert your solution below */
    while (1) {
	PORTC = ~PINA;
    }
    return 1;
}
