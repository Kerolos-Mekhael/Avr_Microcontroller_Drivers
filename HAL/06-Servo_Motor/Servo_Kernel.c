#include "../../lib/BIT_MATH.h"
#include "../../lib/STD_TYPES.h"
#include "../../MCAL/DIO/DIO_interface.h"
#include "util/delay.h"
#include "Servo_interface.h"
#include "Servo_Kernel.h"


void Servo_Init(void){
	DIO_u8SetPortDirection(SERVO_PORT,0xff);
	Timer1_vidInit();
	Timer1_vidSetFrequency(50);
}

void Servo_pulseControl(u8 cop_u8ServoAngle){
	f32 AbsoluteCounts;
	u16 PeriodCounts=0;
	AbsoluteCounts = ((f32)cop_u8ServoAngle / 180) * 1000;
	PeriodCounts = AbsoluteCounts + 1000;
	Timer1_vidSetONPeriod(PeriodCounts);
}

