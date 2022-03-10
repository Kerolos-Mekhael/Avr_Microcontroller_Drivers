#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "DIO_interface.h"
#include "DCMOTOR_configuration.h"
#include "DCMOTOR_interface.h"


void DcMotor_vidON(){

	DIO_u8SetPinValue(DCMOTOR_PORT, DCMOTOR_DRIVER_PIN, PinHigh);
}

void DcMotor_vidOFF(){

	DIO_u8SetPinValue(DCMOTOR_PORT, DCMOTOR_DRIVER_PIN, PinLow);
}

void DCMotor_vidH_Bridge(motor_direction cop_motordirection){
	
	if(cop_motordirection == clockwise){

		DIO_u8SetPinValue(DCMOTOR_PORT, DCMOTOR_DRIVER_1, PinHigh);
		DIO_u8SetPinValue(DCMOTOR_PORT, DCMOTOR_DRIVER_3, PinHigh);

		DIO_u8SetPinValue(DCMOTOR_PORT, DCMOTOR_DRIVER_2, PinLow);
		DIO_u8SetPinValue(DCMOTOR_PORT, DCMOTOR_DRIVER_4, PinLow);
	}
	else if(cop_motordirection == anti_clockwise){

		DIO_u8SetPinValue(DCMOTOR_PORT, DCMOTOR_DRIVER_1, PinLow);
		DIO_u8SetPinValue(DCMOTOR_PORT, DCMOTOR_DRIVER_3, PinLow);

		DIO_u8SetPinValue(DCMOTOR_PORT, DCMOTOR_DRIVER_2, PinHigh);
		DIO_u8SetPinValue(DCMOTOR_PORT, DCMOTOR_DRIVER_4, PinHigh);
	}
}
