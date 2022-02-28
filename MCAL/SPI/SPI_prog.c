#include "BIT_MATH.h"
#include "STD_TYPES.h"
#include "DIO_interface.h"
#include "SPI_registers.h"
#include "SPI_interface.h"
#include "util/delay.h"

void SPI_vidMasterInit(void){

	/* Enable Master */
	SET_BIT(SPCR, SPCR_MSTR);

	/* Select Clock Polarity and Clock Phase */
	CLR_BIT(SPCR, SPCR_CPOL);
	CLR_BIT(SPCR, SPCR_CPHA);

	/* Select Data Order (MSB) */
	CLR_BIT(SPCR, SPCR_DORD);

	/* Select Clock Rate (16) */
	SET_BIT(SPCR, SPCR_SPR0);
	CLR_BIT(SPCR, SPCR_SPR1);

	/* Enable SPI */
	SET_BIT(SPCR,SPCR_SPE);

}

void SPI_vidSlaveInit(void){

	/* Enable Master */
	CLR_BIT(SPCR, SPCR_MSTR);

	/* Enable SPI */
	SET_BIT(SPCR,SPCR_SPE);
}

void SPI_u8Transmit(u8 cop_u8Data){

	SPDR = cop_u8Data;
	while(GET_BIT(SPSR,SPSR_SPIF) == 0);

}

u8 SPI_u8Receive(){

	while(GET_BIT(SPSR,SPSR_SPIF) == 0);
	return SPDR;
}


void SPI_vidSendSentence(u8 *pSentence){

	/* Send char by char */
	u8 i=0;
	while(pSentence[i] != '\0'){
		SPI_u8Transmit(pSentence[i]);
		 i++;
		 _delay_ms(5);
	}
}


void SPI_vidSendIntNumber(u32 cop_u32Number){

	u32 NumberArray[10] = {0};
	u8 NumberCounter = 0;

	/* Store the number in array */
	while(cop_u32Number != 0 || NumberCounter == 0){
		NumberArray[NumberCounter] = cop_u32Number % 10;
		cop_u32Number /= 10;
		NumberCounter ++;
	}
	/* Convert Integer number into string */
	for(u8 i=0;i<NumberCounter;i++){
		SPI_vidSendSentence(NumberArray[NumberCounter-1-i]) ;
	}
}

/* Send floating_point number to LCD */
void SPI_vidSendrealNumber(f32 cop_f32Number, u8 precision){

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

	SPI_vidSendSentence(NumberString);
}
