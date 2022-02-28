#include "../../lib/STD_TYPES.h"
#include "../../lib/BIT_MATH.h"
#include "../../MCAL/DIO/DIO_interface.h"
#include "LCD_configuration.h"
#include "LCD_interface.h"
#include <avr/delay.h>



/* Send Data to LCD */
void LCD_vidSendData(u8 cop_u8Data){
	u8 Data = 0;
	DIO_u8SetPinValue(LCD_CONTROLPORT, LCD_RS_PIN, PinHigh); 	/* RS is ON */
	DIO_u8SetPinValue(LCD_CONTROLPORT, LCD_RW_PIN, PinLow);		/* RW is OFF */
	/* send 4-MSB of Data */
	Data = cop_u8Data & 0xf0;
	DIO_u8SetPortValue(LCD_DATAPORT, Data);
	DIO_u8SetPinValue(LCD_CONTROLPORT, LCD_E_PIN, PinHigh);		/* Enable is ON */
	_delay_ms(2);		/* Delay for 2 ms */
	DIO_u8SetPinValue(LCD_CONTROLPORT, LCD_E_PIN, PinLow);		/* Enable is OFF */

	_delay_ms(2);

	/* send 4-LSB of Data */
	Data = (cop_u8Data << 4) & 0xf0;
	DIO_u8SetPortValue(LCD_DATAPORT, Data);
	DIO_u8SetPinValue(LCD_CONTROLPORT, LCD_E_PIN, PinHigh);		/* Enable is ON */
	_delay_ms(2);		/* Delay for 2 ms */
	DIO_u8SetPinValue(LCD_CONTROLPORT, LCD_E_PIN, PinLow);		/* Enable is OFF */
}

/* Send Command to LCD */
void LCD_vidSendCommand(u8 cop_u8Command){
	u8 Command = 0;
	DIO_u8SetPinValue(LCD_CONTROLPORT, LCD_RS_PIN, PinLow); 	/* RS is OFF */
	DIO_u8SetPinValue(LCD_CONTROLPORT, LCD_RW_PIN, PinLow);		/* RW is OFF */
	/* send 4-MSB of Data */
	Command = cop_u8Command & 0xf0;
	DIO_u8SetPortValue(LCD_DATAPORT, Command);
	DIO_u8SetPinValue(LCD_CONTROLPORT, LCD_E_PIN, PinHigh);		/* Enable is ON */
	_delay_ms(2);		/* Delay for 2 ms */
	DIO_u8SetPinValue(LCD_CONTROLPORT, LCD_E_PIN, PinLow);		/* Enable is OFF */

	_delay_ms(2);

	/* send 4-LSB of Data */
	Command = (cop_u8Command << 4) & 0xf0;
	DIO_u8SetPortValue(LCD_DATAPORT, Command);
	DIO_u8SetPinValue(LCD_CONTROLPORT, LCD_E_PIN, PinHigh);		/* Enable is ON */
	_delay_ms(2);		/* Delay for 2 ms */
	DIO_u8SetPinValue(LCD_CONTROLPORT, LCD_E_PIN, PinLow);		/* Enable is OFF */
}

/* LCD Initializiation */
void LCD_vidInit (){
	_delay_ms(40);
	LCD_vidSendCommand(0b00000010);		/* 4-bit mode */
	LCD_vidSendCommand(0b00101100);		/* Function set: 4-bit mode, 2-line display, 5x10 font */
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

/* Send integer number to LCD */
void LCD_vidSendIntNumber(u32 cop_u32Number, enum_row cop_enumrowNumber, enum_column cop_enumcolumnNumber){

	u32 NumberArray[10] = {0};
	u8 NumberString[10] ={0};
	u8 NumberCounter = 0;

	/* Store the number in array */
	while(cop_u32Number != 0 || NumberCounter == 0){
		NumberArray[NumberCounter] = cop_u32Number % 10;
		cop_u32Number /= 10;
		NumberCounter ++;
	}
	/* Convert Integer number into string */
	for(u8 i=0;i<NumberCounter;i++){
		NumberString[i] = NumberArray[NumberCounter-1-i] + '0';
	}
	LCD_vidSendSentence(NumberString, cop_enumrowNumber, cop_enumcolumnNumber);
}

/* Send floating_point number to LCD */
void LCD_vidSendrealNumber(f32 cop_f32Number, u8 precision, enum_row cop_enumrowNumber, enum_column cop_enumcolumnNumber){

	u32 NumberArray[10] = {0};
	u8 NumberString[10] ={0};
	u8 NumberCounter = 0;
	u32 IntPart = 0, AfterPoint = 0;

	/* Get number before point */
	IntPart = (u32) cop_f32Number ;
	while(IntPart != 0 || NumberCounter == 0){
		NumberArray[NumberCounter] = IntPart % 10;
		IntPart /= 10;
		NumberCounter ++;
	}
	for(u8 i=0;i<NumberCounter;i++){
			NumberString[i] = NumberArray[NumberCounter-1-i] + '0';
		}
	/* add point to the string */
	NumberString[NumberCounter]= '.';
	NumberCounter ++;

	/* Get number after point */
	IntPart = (u32) cop_f32Number ;
	cop_f32Number -= IntPart;
	for(u8 i=0;i<precision;i++){
		cop_f32Number *= 10;
		AfterPoint = cop_f32Number ;
		NumberString[NumberCounter+i] =  AfterPoint + '0';
		cop_f32Number -= AfterPoint;
	}

	LCD_vidSendSentence(NumberString, cop_enumrowNumber, cop_enumcolumnNumber);
}



