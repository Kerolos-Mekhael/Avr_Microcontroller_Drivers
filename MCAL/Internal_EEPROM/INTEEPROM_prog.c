#include "../../lib/BIT_MATH.h"
#include "../../lib/STD_TYPES.h"
#include <util/delay.h>
#include "INTEEPROM_registers.h"
#include "INTEEPROM_interface.h"

void IntEEPROM_WriteByte(u8 cop_Data, u16 cop_Address){

	while(GET_BIT(EECR, EECR_EEWE) == 1);		/* Wait until EEWE becomes zero */
	EEAR = cop_Address;							/* Write new EEPROM address */
	EEDR = cop_Data;							/* Write new EEPROM data */
	SET_BIT(EECR, EECR_EEMWE);
	SET_BIT(EECR, EECR_EEWE);
}
void IntEEPROM_ReadByte(u8 *pdata, u16 cop_Address){
	while(GET_BIT(EECR, EECR_EEWE) == 1);		/* Wait until EEWE becomes zero */
	EEAR = cop_Address;							/* Write new EEPROM address */
	SET_BIT(EECR, EECR_EERE);
	*pdata = EEDR;
}



void IntEEPROMWriteSentence(u8 *pSentence, u16 cop_Address){

	/* Send char by char */
	u8 i=0;
	while(pSentence[i] != '\0'){
		IntEEPROM_WriteByte(pSentence[i], cop_Address+i);
		 i++;
		 _delay_ms(5);
	}
	IntEEPROM_WriteByte('\0', cop_Address+i);
}


void  IntEEPROMWriteIntNumber(u32 cop_u32Number,  u16 cop_Address){

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
	IntEEPROMWriteSentence(NumberString, cop_Address);
}


void IntEEPROMWriterealNumber(f32 cop_f32Number, u8 precision, u16 cop_Address){

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

	IntEEPROMWriteSentence(NumberString, cop_Address);
}

void IntEEPROMReadNumber(u8 *pNumber, u16 cop_Address){

	u8 i=-1;
	do{
		i++;
		IntEEPROM_ReadByte(pNumber+i, cop_Address+i);
	}while(pNumber[i] != '\0');
}

void IntEEPROMReadSentence(u8 *pstr, u16 cop_Address){

	u8 i=-1;
	do{
		i++;
		IntEEPROM_ReadByte(pstr+i, cop_Address+i);
	}while(pstr[i] != '\0');
}

