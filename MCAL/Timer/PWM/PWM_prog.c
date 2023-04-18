#include "BIT_MATH.h"
#include "STD_TYPES.h"
#include "PWM_interface.h"
#include "PWM_registers.h"

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

	/* choose Prescaler (64) */
	SET_BIT(TCCR1B, TCCR1B_CS10);
	SET_BIT(TCCR1B, TCCR1B_CS11);
	CLR_BIT(TCCR1B, TCCR1B_CS12);
}

void Timer1_vidSetONPeriod(u16 cop_u16PeriodCounts, u8 cop_DutyCycle){
	OCR1A = cop_DutyCycle * cop_u16PeriodCounts / 100;
}

void Timer1_vidSetFrequency(u16 cop_u16Frequency, u8 cop_DutyCycle){

	u16 PeriodCounts = (CLOCK / PRESCALER) / cop_u16Frequency;
	ICR1 = PeriodCounts;
	Timer1_vidSetONPeriod(PeriodCounts, cop_DutyCycle);
}



