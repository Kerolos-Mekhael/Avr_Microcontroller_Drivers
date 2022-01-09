/*
 * main.c
 *
 *  Created on: Dec 18, 2021
 *      Author: kerol
 */

#include "../../lib/STD_TYPES.h"
#include "../../lib/BIT_MATH.h"
#include "DIO_registers.h"
#include "DIO_interface.h"
#include <avr/delay.h>

/* Type of seven segment */
typedef enum{
	CommonCathode,
	CommonAnode
}segment_type;
void Display_7SegmentNumber(enum_port cop_enumport, u8 cop_u8number, segment_type cop_segmenttype);
int main(){
	DIO_u8SetPortDirection(portA,output);

	while(1){
		/*DIO_u8SetPortValue(portA,PortHigh);
		_delay_ms(1000);
		DIO_u8SetPortValue(portA,PortLow);
		_delay_ms(1000);*/

		for(u8 i=0;i<10;i++){
			Display_7SegmentNumber(portA, i, CommonCathode);
			_delay_ms(1000);
		}
	}
}
void Display_7SegmentNumber(enum_port cop_enumport, u8 cop_u8number, segment_type cop_segmenttype){
	u8 Arr_Numbers[10] = {0x3F, 0x06, 0x5B, 0x4F, 0x66, 0x6D, 0x7D, 0x07, 0x7F, 0x6F};
	if(cop_segmenttype == CommonCathode){
		switch(cop_enumport){
			case portA: PORTA = Arr_Numbers[cop_u8number];break;
			case portB: PORTB = Arr_Numbers[cop_u8number];break;
			case portC: PORTC = Arr_Numbers[cop_u8number];break;
			case portD: PORTD = Arr_Numbers[cop_u8number];break;
			default: break;
		}
	}

	if(cop_segmenttype == CommonAnode){
			switch(cop_enumport){
				case portA: PORTA = ~ Arr_Numbers[cop_u8number];break;
				case portB: PORTB = ~ Arr_Numbers[cop_u8number];break;
				case portC: PORTC = ~ Arr_Numbers[cop_u8number];break;
				case portD: PORTD = ~ Arr_Numbers[cop_u8number];break;
				default: break;
			}
		}
}
