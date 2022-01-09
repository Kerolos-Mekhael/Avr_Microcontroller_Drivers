#include "../../lib/BIT_MATH.h"
#include "../../lib/STD_TYPES.h"
#include "DIO_registers.h"
#include "DIO_interface.h"


/* set direction of any pin at any port */
void DIO_u8SetPinDirection(enum_port cop_enumport ,enum_pin cop_enumpin ,enum_direction cop_enumdirection){

	/*input*/
	if(cop_enumdirection == input){
		switch(cop_enumport){

			case portA: CLR_BIT(DDRA ,cop_enumpin);break;
			case portB: CLR_BIT(DDRB ,cop_enumpin);break;
			case portC: CLR_BIT(DDRC ,cop_enumpin);break;
			case portD: CLR_BIT(DDRD ,cop_enumpin);break;
		}
	}
	else if(cop_enumdirection == output){
		switch(cop_enumport){

				case portA: SET_BIT(DDRA ,cop_enumpin);break;
				case portB: SET_BIT(DDRB ,cop_enumpin);break;
				case portC: SET_BIT(DDRC ,cop_enumpin);break;
				case portD: SET_BIT(DDRD ,cop_enumpin);break;
				}
	}

}

/* set any pin value at any port */
void DIO_u8SetPinValue(enum_port cop_enumport ,enum_pin cop_enumpin ,enum_value cop_enumValue){

	if(cop_enumValue == PinHigh){
		switch(cop_enumport){

						case portA: SET_BIT(PORTA ,cop_enumpin);break;
						case portB: SET_BIT(PORTB ,cop_enumpin);break;
						case portC: SET_BIT(PORTC ,cop_enumpin);break;
						case portD: SET_BIT(PORTD ,cop_enumpin);break;
						}
	}
	else if(cop_enumValue == PinLow){
		switch(cop_enumport){

						case portA: CLR_BIT(PORTA ,cop_enumpin);break;
						case portB: CLR_BIT(PORTB ,cop_enumpin);break;
						case portC: CLR_BIT(PORTC ,cop_enumpin);break;
						case portD: CLR_BIT(PORTD ,cop_enumpin);break;
				}
	}
}

/* read any pin value at any port */
void DIO_u8GetPinValue(enum_port cop_enumport ,enum_pin cop_enumpin ,u8 *pu8Value){
	switch(cop_enumport){
							case portA: *pu8Value = GET_BIT(PINA ,cop_enumpin);break;
							case portB:*pu8Value = GET_BIT(PINB ,cop_enumpin);break;
							case portC:*pu8Value = GET_BIT(PINC ,cop_enumpin);break;
							case portD: *pu8Value = GET_BIT(PIND ,cop_enumpin);break;
							}
}

/* set direction of any port */
void DIO_u8SetPortDirection(enum_port cop_enumport ,u8 cop_enumValue){

		switch(cop_enumport){

			case portA:DDRA = cop_enumValue;break;
			case portB:DDRB = cop_enumValue;break;
			case portC:DDRC = cop_enumValue;break;
			case portD:DDRD = cop_enumValue;break;
		}

}

/* set value of any port */
void DIO_u8SetPortValue(enum_port cop_enumport ,u8 cop_enumValue){
			switch(cop_enumport){

				case portA:PORTA = cop_enumValue;break;
				case portB:PORTB = cop_enumValue;break;
				case portC:PORTC = cop_enumValue;break;
				case portD:PORTD = cop_enumValue;break;
			}
}

/* read any port value */
void DIO_u8GetPortValue(enum_port cop_enumport ,u8 *pu8Value){
	switch(cop_enumport){

		case portA:*pu8Value = GET_PORT(PINA);break;
		case portB:*pu8Value = GET_PORT(PINB);break;
		case portC:*pu8Value = GET_PORT(PINC);break;
		case portD:*pu8Value = GET_PORT(PIND);break;

	}
}

