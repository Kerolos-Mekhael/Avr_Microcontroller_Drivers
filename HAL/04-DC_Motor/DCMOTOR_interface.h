#ifndef DCMOTOR_INTERFACE_H
#define DCMOTOR_INTERFACE_H

/* enum for motor direction */
typedef enum {
	clockwise ,
	anti_clockwise
}motor_direction;

/* Turn on Dc Motor */
void DcMotor_vidON(void);

/* Turn off Dc Motor */
void DcMotor_vidOFF(void);

/* Control H_bridge direction of motor */
void DCMotor_vidH_Bridge(motor_direction cop_motordirection);

#endif
