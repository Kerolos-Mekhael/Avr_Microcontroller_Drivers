#ifndef OVERFLOW_REGISTERS_H
#define OVERFLOW_REGISTERS_H

/*********** TIMER0 ***********/
#define TCCR0			*((volatile u8*) 0X53)
#define TCCR0_CS00			0
#define TCCR0_CS01			1
#define TCCR0_CS02			2
#define TCCR0_WGM00			6
#define TCCR0_WGM01			3

#define TIMSK			*((volatile u8*) 0X59)
#define TIMSK_TOIE0			0
#define TIMSK_OCIE0			1

#define TCNT0			*((volatile u8*) 0X52)

#define OCR0			*((volatile u8*) 0X5C)

/*********** TIMER1 ***********/
#define TCCR1A			*((volatile u8*) 0X4F)
#define TCCR1A_COM1A1		7
#define TCCR1A_COM1A0		6
#define TCCR1A_COM1B1		5
#define TCCR1A_COM1B0		4
#define TCCR1A_WGM11		1
#define TCCR1A_WGM10		0

#define TCCR1B			*((volatile u8*) 0X4E)
#define TCCR1B_CS10			0
#define TCCR1B_CS11			1
#define TCCR1B_CS12			2
#define TCCR1B_WGM12		3
#define TCCR1B_WGM13		4

#define TIMSK			*((volatile u8*) 0X59)
#define TIMSK_TOIE1			2
#define TIMSK_OCIE1B		3
#define TIMSK_OCIE1A		4

#define TCNT1L			*((volatile u16*) 0X4C)

#define OCR1AL			*((volatile u16*) 0X4A)

#define OCR1BL			*((volatile u16*) 0X48)

#endif
