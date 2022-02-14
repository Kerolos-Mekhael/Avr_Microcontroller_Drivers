#ifndef SERVO_INTERFACE_H
#define SERVO_INTERFACE_H

#define PRESCALER		8
#define CLOCK			8000000

/* Initialization of Timer1 */
void Timer1_vidInit(void);

/* Set the period counts in input capture register */
void Timer1_vidSetFrequency(u16 cop_u16Frequency);

/* Set the compare match value */
void Timer1_vidSetONPeriod(u16 cop_u16ONPeriod);

#endif
