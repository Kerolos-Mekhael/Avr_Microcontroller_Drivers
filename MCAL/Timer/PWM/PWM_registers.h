#ifndef PWM_REGISTERS_H
#define PWM_REGISTERS_H

#define TCCR1A			*((volatile u8*) 0X4F)
#define TCCR1A_WGM10		0
#define TCCR1A_WGM11		1
#define TCCR1A_COM1A0		6
#define TCCR1A_COM1A1		7


#define TCCR1B			*((volatile u8*) 0X4E)
#define TCCR1B_WGM12		3
#define TCCR1B_WGM13		4
#define TCCR1B_CS10			0
#define TCCR1B_CS11			1
#define TCCR1B_CS12			2


#define ICR1			*((volatile u16*) 0X46)

#define OCR1A			*((volatile u16*) 0X4A)

#endif
