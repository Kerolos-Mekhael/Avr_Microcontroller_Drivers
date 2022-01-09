#ifndef  KPD_CONF_H
#define  KPD_CONF_H

/* Keypad connection port */
#define KPAD_PORT		portA

/* Columns pins */
#define KPAD_C0_PIN		pin0__
#define KPAD_C1_PIN		pin1__
#define KPAD_C2_PIN		pin2__
#define KPAD_C3_PIN		pin3__

/* Rows pins */
#define KPAD_R0_PIN		pin4__
#define KPAD_R1_PIN		pin5__
#define KPAD_R2_PIN		pin6__
#define KPAD_R3_PIN		pin7__

/* Return if no key is pressed */
#define KEY_NOT_PRESSED	100

/* Characters to represent each push button */
#define KPAD_NUMBERS  {{'1', '2', '3', 'A'}, \
						{'4', '5', '6', 'B'}, \
						{'7', '8', '9', 'C'}, \
						{'#', '0', '.', 'D'}}

#endif
