#ifndef SERVO_KERNEL_H
#define SERVO_KERNEL_H

#define SERVO_PORT		portD

/* Initialization of all required drivers
 * for Servo motor to be ready for signal
 */
void Servo_Init(void);

/* Generation of PWM to control Servo angle (0 - 180) */
void Servo_pulseControl(u8 cop_u8ServoAngle);


#endif
