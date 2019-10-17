/*	Author: nmoor004
 *  Partner(s) Name: 
 *	Lab Section:
 *	Assignment: Lab # 5  Exercise # 1
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
	DDRA = 0x00; PORTA = 0x0F;  //input
	DDRC = 0xFF; PORTC = 0x00; //output

    /* Insert your solution below */
	unsigned char temp_val;

	while (1) {
		temp_val = PINA;

		
		if (temp_val < 0x03) { //LVL1-2
			PORTC = 0x60; //PC5 +pc6 low level light
		}
		else if (temp_val < 0x05) { //LVL3-4
			PORTC = 0x70; //PC5-PC4 +pc6 low level light
		}
		else if (temp_val < 0x07) { //LVL5-6
			PORTC = 0x38; //PC5-PC3
		}
		else if (temp_val < 0x0A) { //LVL7-9
			PORTC = 0x3C; //PC5-PC2
		}
		else if (temp_val < 0x0D) { //LVL10-12
			PORTC = 0x3E; //PC5-PC1
		}
		else if (temp_val <= 0x0F) { //LVL13-15
			PORTC = 0x3F;
		}
		
	}
	return 1;
}
