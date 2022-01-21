#ifndef LCD_INTERFACE_H
#define LCD_INTERFACE_H
/* 16x2 Character LCD */

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

/* Send Data to LCD
 * Input : Character to display
 */
void LCD_vidSendData(u8 cop_u8Data);

/* Send Command to LCD
 * Input : Command byte
 */
void LCD_vidSendCommand(u8 cop_u8Command);

/* Set DDRAM Address
 * Input : Number of position row
 * 		   Number of position column
 */
void LCD_vidSetDDRAMAddress(enum_row cop_enumrowNumber, enum_column cop_enumcolumnNumber);

/* Send Sentence at specific position
 * Input : String to display
 * 		   Number of position row
 * 		   Number of position column
 */
void LCD_vidSendSentence(u8 *pSentence, enum_row cop_enumrowNumber, enum_column cop_enumcolumnNumber);

/* Send integer number to LCD
 * Input : Integer number to display
 * 		   Number of position row
 * 		   Number of position column
 */
void LCD_vidSendIntNumber(u32 cop_u32Number, enum_row cop_enumrowNumber, enum_column cop_enumcolumnNumber);

/* Send floating_point number to LCD
 * Input : float number to display
 * 		   Precison (Number of after-point numbers)
 * 		   Number of position row
 * 		   Number of position column
 */
void LCD_vidSendrealNumber(f32 cop_f32Number, u8 precision, enum_row cop_enumrowNumber, enum_column cop_enumcolumnNumber);
 
#endif
