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
	DDRC = 0xFF; PORTC = 0x00; //output

    /* Insert your solution below */
	unsigned char temp_val = 0x00;
	unsigned char end_level_bits = 0x00;
	while (1) {
		temp_val = 0x0F;
		
		if (temp_val < 0x03) { //LVL1-2
			end_level_bits = 0x30; //PC5 +pc6 low level light
		}
		else if (temp_val < 0x05) { //LVL3-4
			end_level_bits = 0x38; //PC5-PC4 +pc6 low level light
		}
		else if (temp_val < 0x07) { //LVL5-6
			end_level_bits = 0x18; //PC5-PC3
		}
		else if (temp_val < 0x0A) { //LVL7-9
			end_level_bits = 0x1C; //PC5-PC2
		}
		else if (temp_val < 0x0D) { //LVL10-12
			end_level_bits = 0x1E; //PC5-PC1
		}
		else if (temp_val <= 0x0F) { //LVL13-15
			end_level_bits = 0x1F;
		}
		
		PORTC = end_level_bits;
	}
	return 1;
}
