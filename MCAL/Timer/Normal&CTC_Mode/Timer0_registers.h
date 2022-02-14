#ifndef TIMER0_REGISTERS_H
#define TIMER0_REGISTERS_H

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

#endif
