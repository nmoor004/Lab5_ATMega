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


enum Inc_States { Inc_init, Inc_Idle, Inc_Debounce} Inc_State;

void Tick_Inc(unsigned char temp_val) {

	unsigned char sum = PORTC; 
	unsigned char A0 = temp_val & 0x01;         // Get 0th bit
	unsigned char A1 = (temp_val & 0x02) >> 1; // Get 1st bit and right shift
	switch(Inc_State) {     		  // Transitions, changed to Mealy Machine
		case Inc_init: 			 // The switches on my board are backwards,  							// therefore 0x00 is input, 0x01 is release.
			Inc_State = Inc_Idle;
			break;
		
		case Inc_Idle:
			if ((A0 == 0x00) && (A1 == 0x00)) { //Reset
				Inc_State = Inc_Debounce;
				PORTC = 0x00;
			}
			else if ((A0 == 0x00) && (A1 == 0x01)) { //Add
				Inc_State = Inc_Debounce;
				if (sum != 0x09) {
					sum++;
					PORTC = sum;
				}
			}
			else if ((A0 == 0x01) && (A1 == 0x00)) { //Subtract
				Inc_State = Inc_Debounce;
				if (sum != 0x00) {
					sum--;
					PORTC = sum;
				}
			}
			
			break; 

		case Inc_Debounce:
			if ((A0 == 0x01) && (A1 == 0x01)) {
				Inc_State = Inc_Idle;
			} 
			else if ((A0 == 0x00) && (A1 == 0x00)) { //Reset
				Inc_State = Inc_Idle;
				PORTC = 0x00;
			}
			break;

	}

	switch(Inc_State) {
		case Inc_init:
			break;
		case Inc_Idle:
			break;
		case Inc_Debounce:
			break;

	}

}

int main(void) {
    /* Insert DDR and PORT initializations */
	DDRA = 0x00; PORTA = 0xFF;  //input
	DDRC = 0xFF; PORTC = 0x00; //output
    /* Insert your solution below */
	Inc_State = Inc_init;
	unsigned char temp_val = PINA;
	PORTB = 0x07;

    while (1) {
	
		Tick_Inc(temp_val);
		temp_val = PINA; 
	}
    return 1;
}
