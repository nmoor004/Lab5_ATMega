/*	Author: nmoor004
 *  Partner(s) Name: 
 *	Lab Section:
 *	Assignment: Lab #  Exercise #
 *	Exercise Description: [optional - include for your own benefit]
 *
 *	I acknowledge all content contained herein, excluding template or example
 *	code, is my own original work.
 */
#include <avr/io.h>
#ifdef _SIMULATE_
#include "simAVRHeader.h"
#endif

int main(void) {
    /* Insert DDR and PORT initializations */
	// DDRC = 0x00; PORTC = 0xFF;  //input
	DDRB = 0xFF; PORTB = 0x00; //output

    /* Insert your solution below */

	while (1) {
		PORTB = 0x0F;
	}
	return 1;
}
