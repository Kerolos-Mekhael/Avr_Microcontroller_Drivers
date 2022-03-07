#ifndef INTEEPROM_REGISTERS_H
#define INTEEPROM_REGISTERS_H

#define EEAR			*((volatile u16*) 0x3E)	/* EEPROM Address Register */
/*************************************************************************/
#define EEDR			*((volatile u8*) 0x3D)	/* EEPROM Data Register */
/*************************************************************************/
#define EECR			*((volatile u8*) 0x3C)	/* EEPROM Control Register */
#define EECR_EERIE			3				/* EEPROM Ready Interrupt Enable */
#define EECR_EEMWE			2				/* EEPROM Master Write Enable */
#define EECR_EEWE			1				/* EEPROM Write Enable */
#define EECR_EERE			0				/* EEPROM Read Enable */

#endif
