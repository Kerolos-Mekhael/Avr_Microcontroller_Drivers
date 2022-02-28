#include "../../../lib/BIT_MATH.h"
#include "../../../lib/STD_TYPES.h"
#include "../Normal&CTC_Mode/Overflow_interface.h"
#include "ICU_registers.h"
#include "ICU_interface.h"

u32 TON, TOFF;
u32 TotalPeriod;

void ICU_Init(){

	/* Enable Timer1 as overflow */
	Timer_vidInit(Timer1, Overflow);

	/* select rising edge for ICU */
	SET_BIT(TCCR1B, TCCR1B_ICES1);

	/* Enable ICU Interrupt */
	SET_BIT(TIMSK, TIMSK_TICIE1);


}

/* Interrupt Service Routine  for ICU */
void __vector_6(void) __attribute__ ((signal));
void __vector_6(void){

	static u8 counter=0;
	counter++;
	if(counter == 1){
		TCNT1 = 0;

		/* select falling edge for ICU */
		CLR_BIT(TCCR1B, TCCR1B_ICES1);
	}
	else if(counter == 2){
		TON = ICR1;
		TCNT1 = 0;

		/* select rising edge for ICU */
		SET_BIT(TCCR1B, TCCR1B_ICES1);
	}
	else if(counter == 3){
		TOFF = ICR1;
		TotalPeriod = TON + TOFF;
		TCNT1 = 0;
		counter = 0;
	}
}
