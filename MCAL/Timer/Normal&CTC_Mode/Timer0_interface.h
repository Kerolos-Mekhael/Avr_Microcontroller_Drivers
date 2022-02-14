#ifndef TIMER0_INTERFACE_H
#define TIMER0_INTERFACE_H

/* Enum for Timer Mode Selection */
typedef enum{
	Overflow ,
	CTC
}Timer_Mode;

#define PRESCALER    256
#define CLOCK		 8000000

/* Callback Function */
void Callback_function(void(* ptr)());

/* Delay Timer in msec */
void Timer0_CTC_us(u32 cop_us);

/* Delay Timer in usec */
void Timer0_us(u32 cop_us);

/* Timer0 Initialization */
void Timer0_vidInit(Timer_Mode cop_TimerMode);

#endif
