#ifndef DCMOTOR_INTERFACE_H
#define DCMOTOR_INTERFACE_H

/* enum for motor direction */
typedef enum {
	clockwise ,
	anti-clockwise 
}motor_direction;

/* Turn on Dc Motor */
void DcMotor_vidON(enum_port cop_enumport, enum_pin cop_enumpin);

/* Turn off Dc Motor */
void DcMotor_vidOFF(enum_port cop_enumport, enum_pin cop_enumpin);

/* Control H_bridge direction of motor */
void DCMotor_vidH_Bridge(enum_port cop_enumport, motor_direction cop_motordirection);

#endif