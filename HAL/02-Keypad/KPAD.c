/*
 * KPAD.c
 *
 *  Created on: Dec 29, 2021
 *      Author: kerol
 */
#include "../../lib/BIT_MATH.h"
#include "../../lib/STD_TYPES.h"
#include "../../MCAL/DIO/DIO_interface.h"
#include "../01-LCD/LCD_interface.h"
#include "KPD_configuration.h"
#include "KPD_interface.h"


int main(){
	u8 Local_u8PressedKey=0;
	 DIO_u8SetPortDirection(portA ,0x0f);
	 DIO_u8SetPortDirection(portB ,0xff);
	 DIO_u8SetPortDirection(portD ,0xff);
	 DIO_u8SetPortValue(portA ,0xff);
	 LCD_vidInit ();

	 while(1){
		 Local_u8PressedKey = KPD_u8GetPressedKey();
		 if(Local_u8PressedKey != KEY_NOT_PRESSED){
			 LCD_vidSendData(Local_u8PressedKey);
		 }
	 }
}
