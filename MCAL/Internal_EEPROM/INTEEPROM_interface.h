#ifndef INTEEPROM_INTERFACE_H
#define INTEEPROM_INTERFACE_H

/* Write byte to EEPROM */
void IntEEPROM_WriteByte(u8 cop_Data, u8 cop_Address);

/* Read byte from EEPROM */
void IntEEPROM_ReadByte(u8 *pdata, u8 cop_Address);

#endif
