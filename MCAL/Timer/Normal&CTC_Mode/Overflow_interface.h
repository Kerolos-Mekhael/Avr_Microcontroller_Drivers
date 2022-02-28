#ifndef TIMER0_INTERFACE_H
#define TIMER0_INTERFACE_H

/* Enum for Timer Mode Selection */
typedef enum{
	Overflow ,
	CTC
}Timer_Mode;

/* Enum for Timer Selection */
typedef enum{
	Timer0	,
	Timer1
}Timer;

#define PRESCALER    256
#define CLOCK		 8000000

/* Callback Function */
void Callback_function(void(* ptr)());

/* Delay Timer in msec */
void  Timer_Overflow_ms(Timer cop_Timer, u32 cop_ms);

/* Delay Timer in usec */
void Timer_CTC_us(Timer cop_Timer, u32 cop_us);

/* Timer0 Initialization */
void Timer_vidInit(Timer cop_Timer, Timer_Mode cop_TimerMode);

#endif
