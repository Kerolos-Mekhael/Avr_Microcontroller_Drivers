#include "../../../lib/BIT_MATH.h"
#include "../../../lib/STD_TYPES.h"
#include "../../DIO/DIO_interface.h"
#include "../../Interrupt/GIE_interface.h"
#include "Timer0_registers.h"
#include "Timer0_interface.h"
#include "../../../HAL/01-LCD/LCD_interface.h"

u32 Global_Counts;
u8  TCNT0_Register;
u8 Mode;
void (* Callback_Ptr)(void) = '\0';

/* Callback Function */
void Callback_function(void(* ptr)()){

	if(ptr != '\0'){
		Callback_Ptr = ptr;
	}
}

/* Delay Timer in msec using Overflow mode */
void  Timer0_Overflow_ms(u32 cop_ms){

	f64 OverflowTime=0;
	f64 OverflowCounts=0, checkInt;

	/* Calculating number of overflows */
	OverflowTime = (f64)256 * ((f64)PRESCALER / CLOCK);
	OverflowCounts = (f64)cop_ms  / (OverflowTime * 1000);

	/* check if the number of overflows contains floating part */
	checkInt = OverflowCounts - (u32)OverflowCounts;
	if(checkInt == 0){
		Global_Counts = (u32)OverflowCounts;
		TCNT0_Register = 0;
	}else{
		Global_Counts =  (u32)OverflowCounts + 1;
		TCNT0_Register = 256 - (checkInt * 256);
		TCNT0 = TCNT0_Register;
	}
}

/* Delay Timer in usec using CTC Mode */
void Timer0_CTC_us(u32 cop_us){
	u32 TickTime=0;
	TickTime = PRESCALER / CLOCK;
	OCR0 = cop_us / TickTime  ;
}

/* Timer0 Initialization */
void Timer0_vidInit(Timer_Mode cop_TimerMode){

	/* Mode Selection */
	if(cop_TimerMode == Overflow){

		/* Waveform generation Mode(Normal Mode) */
			CLR_BIT(TCCR0, TCCR0_WGM00);
			CLR_BIT(TCCR0, TCCR0_WGM01);

		/* Enable Interrupt Overflow */
			SET_BIT(TIMSK, TIMSK_TOIE0);
	}
	else if(cop_TimerMode == CTC){
		/* Waveform generation Mode(CTC) */
			CLR_BIT(TCCR0, TCCR0_WGM00);
			SET_BIT(TCCR0, TCCR0_WGM01);

		/* Enable Interrupt CTC */
			SET_BIT(TIMSK, TIMSK_OCIE0);
	}

	/* Enable Global Interrupt */
	GIE_vidSetBit();

	/* Clock Selection Prescaler(256) */
	CLR_BIT(TCCR0, TCCR0_CS00);
	CLR_BIT(TCCR0, TCCR0_CS01);
	SET_BIT(TCCR0, TCCR0_CS02);

}

/* Interrupt Service Routine  for Overflow Mode */
void __vector_11(void) __attribute__ ((signal));
void __vector_11(void){
	static u8 counts=0;
	counts ++;
	if(counts == Global_Counts){
		counts = 0;
		TCNT0 = TCNT0_Register;
		Callback_Ptr();
	}
}

/* Interrupt Service Routine  for CTC Mode */
void __vector_10(void) __attribute__ ((signal));
void __vector_10(void){

	Callback_Ptr();
}

