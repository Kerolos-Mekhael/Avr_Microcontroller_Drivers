#ifndef DIO_INTERFACE_H
#define DIO_INTERFACE_H

/* PORT enum */
typedef enum{
	portA,
	portB,
	portC,
	portD
	
}enum_port;

/* PIN enum */
typedef enum{
	pin0__,
	pin1__,
	pin2__,
	pin3__,
	pin4__,
	pin5__,
	pin6__,
	pin7__
	
}enum_pin;

/* Values */
typedef enum{
	PinLow ,
	PinHigh ,
	PortLow =0x00 ,
	PortHigh= 0xff
	
}enum_value;

/* Direction enum */
typedef enum{
	input ,
	output
}enum_direction;

/* set direction of any pin at any port */
void DIO_u8SetPinDirection(enum_port cop_enumport ,enum_pin cop_enumpin ,enum_direction cop_enumdirection);

/* set any pin value at any port */
void DIO_u8SetPinValue(enum_port cop_enumport ,enum_pin cop_enumpin ,enum_value cop_enumValue);

/* read any pin value at any port */
void DIO_u8GetPinValue(enum_port cop_enumport ,enum_pin cop_enumpin ,u8 *pu8Value);

/* set direction of any port */
void DIO_u8SetPortDirection(enum_port cop_enumport ,u8 cop_enumValue);

/* set any port value */
void DIO_u8SetPortValue(enum_port cop_enumport ,u8 cop_enumValue);

/* read any port */
void DIO_u8GetPortValue(enum_port cop_enumport ,u8 *pu8Value);

#endif
