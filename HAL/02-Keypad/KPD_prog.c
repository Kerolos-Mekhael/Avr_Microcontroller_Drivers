#include "../../lib/BIT_MATH.h"
#include "../../lib/STD_TYPES.h"
#include "../../MCAL/DIO/DIO_interface.h"
#include "KPD_configuration.h"
#include "KPD_interface.h"
#include <avr/delay.h>
#include "../01-LCD/LCD_interface.h"

u8 KPD_u8GetPressedKey(void){
	u8 Local_PressedKey = KEY_NOT_PRESSED;
	u8 KPAD_u8ButtonState=0;
	u8 KPAD_u8ColumnArray[]= {KPAD_C0_PIN, KPAD_C1_PIN, KPAD_C2_PIN, KPAD_C3_PIN};
	u8 KPAD_u8RowArray[]= {KPAD_R0_PIN, KPAD_R1_PIN, KPAD_R2_PIN, KPAD_R3_PIN};
	u8 KPAD_Array[4][4]= KPAD_NUMBERS;

	for(u8 col=0; col<4; col++){
		DIO_u8SetPinValue(KPAD_PORT, KPAD_u8ColumnArray[col], PinLow);
		for(u8 row=0; row<4; row++){
			DIO_u8GetPinValue(KPAD_PORT,KPAD_u8RowArray[row], &KPAD_u8ButtonState);

			if(KPAD_u8ButtonState == 0 ){
				Local_PressedKey = KPAD_Array[row][col];
				while(KPAD_u8ButtonState == 0 ){
					DIO_u8GetPinValue(KPAD_PORT,KPAD_u8RowArray[row], &KPAD_u8ButtonState);
				}
				_delay_ms(10);
				break;
			}
		}
		DIO_u8SetPinValue(KPAD_PORT, KPAD_u8ColumnArray[col], PinHigh);
		if(Local_PressedKey != KEY_NOT_PRESSED){
			break;
		}
	}
	return Local_PressedKey;
}
