#ifndef ICU_REGISTERS_H
#define ICU_REGISTERS_H

/* Timer1 Register */
#define TCNT1			*((volatile u16 *) 0x4C)

/* Control Register B */
#define TCCR1B			*((volatile u8 *) 0x4E)
#define TCCR1B_CS10			0
#define TCCR1B_CS11			1
#define TCCR1B_CS12			2
#define TCCR1B_WGM12		3
#define TCCR1B_WGM113		4
#define TCCR1B_ICES1		6

/* Control Register A */
#define TCCR1A			*((volatile u8 *) 0x4F)
#define TCCR1A_WGM10		0
#define TCCR1A_WGM11		1

/* Interrupt Mask Register */
#define TIMSK			*((volatile u8 *) 0x59)
#define TIMSK_TICIE1		5

/* Input Capture Register */
#define ICR1			*((volatile u16 *) 0x46)

#endif
