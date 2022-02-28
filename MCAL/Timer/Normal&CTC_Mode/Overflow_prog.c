#include "../../../lib/BIT_MATH.h"
#include "../../../lib/STD_TYPES.h"
#include "../../DIO/DIO_interface.h"
#include "../../Interrupt/GIE_interface.h"
#include "Overflow_registers.h"
#include "Overflow_interface.h"


u32 Global_Counts;
u8  TCNT0_Register;
u8 	TCNT1_Register;
u8 	Mode;
void (* Callback_Ptr)(void) = '\0';

/* Callback Function */
void Callback_function(void(* ptr)()){

	if(ptr != '\0'){
		Callback_Ptr = ptr;
	}
}

/* Delay Timer in msec using Overflow mode */
void  Timer_Overflow_ms(Timer cop_Timer, u32 cop_ms){

	f64 OverflowTime=0;
	f64 OverflowCounts=0, checkInt;
	u32 OverflowReg=0;
	if(cop_Timer == Timer0){
		OverflowReg = 256;
	}else if(cop_Timer == Timer1){
		OverflowReg = 65536;
	}
	/* Calculating number of overflows */
	OverflowTime = (f64)OverflowReg * ((f64)PRESCALER / CLOCK);
	OverflowCounts = (f64)cop_ms  / (OverflowTime * 1000);

	/* check if the number of overflows contains floating part */
	checkInt = OverflowCounts - (u32)OverflowCounts;
	if(checkInt == 0){
		Global_Counts = (u32)OverflowCounts;
		if(cop_Timer == Timer0){
			TCNT0_Register = 0;
		}
		else if(cop_Timer == Timer1){
			TCNT1_Register = 0;
		}

	}else{
		Global_Counts =  (u32)OverflowCounts + 1;
		if(cop_Timer == Timer0){
			TCNT0_Register = 256 - (checkInt * 256);
			TCNT0 = TCNT0_Register;
		}
		else if(cop_Timer == Timer1){
			TCNT1_Register = 256 - (checkInt * 256);
			TCNT1L = TCNT1_Register;
		}
	}
}

/* Delay Timer in usec using CTC Mode */
void Timer_CTC_us(Timer cop_Timer, u32 cop_us){
	u32 TickTime=0;
	TickTime = PRESCALER / CLOCK;

	if(cop_Timer == Timer0){
		OCR0 = cop_us / TickTime  ;
	}
	else if(cop_Timer == Timer1){
		OCR1AL = cop_us / TickTime  ;
	}
}

/* Timer0 Initialization */
void Timer_vidInit(Timer cop_Timer, Timer_Mode cop_TimerMode){

	/*********** TIMER0 ***********/
	if(cop_Timer == Timer0){
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

	/*********** TIMER1 ***********/
	else if(cop_Timer == Timer1){

		/* Mode Selection */
		if(cop_TimerMode == Overflow){

			/* Waveform generation Mode(Normal Mode) */
			CLR_BIT(TCCR1A, TCCR1A_WGM10);
			CLR_BIT(TCCR1A, TCCR1A_WGM11);
			CLR_BIT(TCCR1B, TCCR1B_WGM12);
			CLR_BIT(TCCR1B, TCCR1B_WGM13);

			/* Enable Interrupt Overflow */
			SET_BIT(TIMSK, TIMSK_TOIE1);
		}
		else if(cop_TimerMode == CTC){
			/* Waveform generation Mode(CTC) */
			CLR_BIT(TCCR1A, TCCR1A_WGM10);
			CLR_BIT(TCCR1A, TCCR1A_WGM11);
			SET_BIT(TCCR1B, TCCR1B_WGM12);
			CLR_BIT(TCCR1B, TCCR1B_WGM13);

			/* Enable Interrupt CTC */
			SET_BIT(TIMSK, TIMSK_OCIE1A);
			}

		/* Enable Global Interrupt */
		GIE_vidSetBit();

		/* Clock Selection Prescaler(256) */
		CLR_BIT(TCCR1B, TCCR1B_CS10);
		CLR_BIT(TCCR1B, TCCR1B_CS11);
		SET_BIT(TCCR1B, TCCR1B_CS12);

	}

}

/*********** TIMER0 ***********/
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

/*********** TIMER1 ***********/
/* Interrupt Service Routine  for Overflow Mode */
void __vector_9(void) __attribute__ ((signal));
void __vector_9(void){

		TCNT1L = TCNT1_Register;
		Callback_Ptr();
}

/* Interrupt Service Routine  for CTC Mode */
void __vector_7(void) __attribute__ ((signal));
void __vector_7(void){

	Callback_Ptr();
}

