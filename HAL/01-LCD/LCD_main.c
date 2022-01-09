#include "../../lib/STD_TYPES.h"
#include "../../MCAL/DIO/DIO_interface.h"
#include "LCD_interface.h"
#include <avr/delay.h>

int main(){

	 DIO_u8SetPortDirection(portB ,output);
	 DIO_u8SetPortDirection(portD ,output);
	 LCD_vidInit ();

	 LCD_vidSendSentence("Kero", row1, column4);
	 _delay_ms(100);
	 LCD_vidSendSentence("Mekhael", row2, column8);
	 while(1){

	 }

}
