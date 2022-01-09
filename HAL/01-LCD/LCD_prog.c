#include "../../lib/STD_TYPES.h"
#include "../../lib/BIT_MATH.h"
#include "../../MCAL/DIO/DIO_interface.h"
#include "LCD_configuration.h"
#include "LCD_interface.h"
#include <avr/delay.h>



/* Write Data to LCD */
void LCD_vidSendData(u8 cop_u8Data){

	DIO_u8SetPinValue(LCD_CONTROLPORT, LCD_RS_PIN, PinHigh); 	/* RS is ON */
	DIO_u8SetPinValue(LCD_CONTROLPORT, LCD_RW_PIN, PinLow);	/* RW is OFF */
	DIO_u8SetPortValue(LCD_DATAPORT, cop_u8Data);				/* send Data */
	DIO_u8SetPinValue(LCD_CONTROLPORT, LCD_E_PIN, PinHigh);		/* Enable is ON */
	_delay_ms(2);		/* Delay for 2 ms */
	DIO_u8SetPinValue(LCD_CONTROLPORT, LCD_E_PIN, PinLow);		/* Enable is OFF */
}

/* write Command to LCD */
void LCD_vidSendCommand(u8 cop_u8Command){
	
	DIO_u8SetPinValue(LCD_CONTROLPORT, LCD_RS_PIN, PinLow); 	/* RS is OFF */
	DIO_u8SetPinValue(LCD_CONTROLPORT, LCD_RW_PIN, PinLow);		/* RW is OFF */
	DIO_u8SetPortValue(LCD_DATAPORT, cop_u8Command);			/* send Data */
	DIO_u8SetPinValue(LCD_CONTROLPORT, LCD_E_PIN, PinHigh);		/* Enable is ON */
	_delay_ms(2);		/* Delay for 1 ms */
	DIO_u8SetPinValue(LCD_CONTROLPORT, LCD_E_PIN, PinLow);		/* Enable is OFF */
}

/* LCD Initializiation */
void LCD_vidInit (){
	_delay_ms(40);
	LCD_vidSendCommand(0b00111100);		/* Function set: 8-bit mode, 2-line display, 5x10 font */
	_delay_ms(1);
	LCD_vidSendCommand(0b00001100);		/* Display ON, No Cursor */
	_delay_ms(1);
	LCD_vidSendCommand(0b00000001);		/* Clear Display */
	_delay_ms(2);
	LCD_vidSendCommand(0b00000110);		/* Entry Mode */

}

/* Set DDRAM Address */
void LCD_vidSetDDRAMAddress(enum_row cop_enumrowNumber, enum_column cop_enumcolumnNumber){
	u8 DDRAM_address=0;
	/* Line_1 */
	if(cop_enumrowNumber == row1){
		 DDRAM_address =(0x00 | cop_enumcolumnNumber) | 0b10000000 ;
	}
	/* Line_2 */
	else if(cop_enumrowNumber == row2){
		 DDRAM_address =(0x40 | cop_enumcolumnNumber) | 0b10000000 ;
	}
	LCD_vidSendCommand(DDRAM_address);
}

/* Send Sentence at specific position */
void LCD_vidSendSentence(u8 *pSentence, enum_row cop_enumrowNumber, enum_column cop_enumcolumnNumber){
	/* Set address */
	LCD_vidSetDDRAMAddress(cop_enumrowNumber, cop_enumcolumnNumber);
	/* Send char by char */
	u8 i=0;
	while(pSentence[i] != '\0'){
		 LCD_vidSendData(pSentence[i]);
		 i++;
		 _delay_ms(5);
	}
}
