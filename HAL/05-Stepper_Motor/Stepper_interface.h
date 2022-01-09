#ifndef STEPPER_INTERFACE_H
#define STEPPER_INTERFACE_H

/* enum for stepper direction */
typedef enum {
	clockwise ,
	anti_clockwise
}stepper_direction;

/* rotate unipolar stepper motor in the required direction */
void Stepper_vid_ON(stepper_direction cop_stepperdirection);

/* turn stepper motor off */
void Stepper_vid_OFF(void);

#endif