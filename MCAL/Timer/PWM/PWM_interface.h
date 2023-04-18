#ifndef PWM_INTERFACE_H
#define PWM_INTERFACE_H

#define PRESCALER		64
#define CLOCK			8000000

/* Initialization of Timer1 */
void Timer1_vidInit(void);

/* Set the period counts & DutyCycle */
void Timer1_vidSetFrequency(u16 cop_u16Frequency, u8 cop_DutyCycle);

/* Set the DutyCycle */
void Timer1_vidSetONPeriod(u16 cop_u16PeriodCounts, u8 cop_DutyCycle);

#endif
