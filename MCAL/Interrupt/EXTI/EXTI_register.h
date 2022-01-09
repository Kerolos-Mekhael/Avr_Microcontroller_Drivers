#ifndef	EXTI_REGISTER_H
#define EXTI_REGISTER_H

#define MCUCR		((volatile *) 0x55 )

#define MCUSR_ISC11		3
#define MCUSR_ISC10		2
#define MCUSR_ISC01		1
#define MCUSR_ISC00		0

#define MCUCSR		((volatile *) 0x54)
#define MCUSR_ISC2		6

#define GICR		((volatile *) 0x5B)
#define GICR_INT1		7
#define GICR_INT0		6
#define GICR_INT2		5

#define GIFR		((volatile *) 0x5A)


#endif