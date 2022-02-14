#include "../../lib/BIT_MATH.h"
#include "../../lib/STD_TYPES.h"
#include "Servo_interface.h"
#include "Servo_registers.h"

/* Initialization of Timer1 */
void Timer1_vidInit(void){

	/* Waveform Generation Mode (Fast PWM) */
	CLR_BIT(TCCR1A, TCCR1A_WGM10);
	SET_BIT(TCCR1A, TCCR1A_WGM11);
	SET_BIT(TCCR1B, TCCR1B_WGM12);
	SET_BIT(TCCR1B, TCCR1B_WGM13);

	/* Choose non-inverting Mode */
	CLR_BIT(TCCR1A, TCCR1A_COM1A0);
	SET_BIT(TCCR1A, TCCR1A_COM1A1);

	/* choose Prescaler (8) */
	CLR_BIT(TCCR1B, TCCR1B_CS10);
	SET_BIT(TCCR1B, TCCR1B_CS11);
	CLR_BIT(TCCR1B, TCCR1B_CS12);
}

/* Set the period counts in input capture register */
void Timer1_vidSetFrequency(u16 cop_u16Frequency){

	u16 PeriodCounts = (CLOCK / PRESCALER) / cop_u16Frequency;
	ICR1 = PeriodCounts;
}

/* Set the compare match value */
void Timer1_vidSetONPeriod(u16 cop_u16ONPeriod){
	OCR1A = cop_u16ONPeriod;
}
