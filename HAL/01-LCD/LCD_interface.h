#ifndef LCD_INTERFACE_H
#define LCD_INTERFACE_H

/* Enum for Columns */
typedef enum{
		column1  ,
		column2  ,
		column3  ,
		column4  ,
		column5  ,
		column6  ,
		column7  ,
		column8  ,
		column9  ,
		column10  ,
		column11  ,
		column12  ,
		column13  ,
		column14  ,
		column15  ,
		column16
}enum_column;

/* Enum for Rows */
typedef enum{
		row1=1 ,
		row2
}enum_row;

/* LCD Initializiation */
void LCD_vidInit ();

/* Send Data to LCD */
void LCD_vidSendData(u8 cop_u8Data);

/* Send Command to LCD */
void LCD_vidSendCommand(u8 cop_u8Command);

/* Set DDRAM Address */
void LCD_vidSetDDRAMAddress(enum_row cop_enumrowNumber, enum_column cop_enumcolumnNumber);

/* Send Sentence at specific position */
void LCD_vidSendSentence(u8 *pSentence, enum_row cop_enumrowNumber, enum_column cop_enumcolumnNumber);
 
#endif
