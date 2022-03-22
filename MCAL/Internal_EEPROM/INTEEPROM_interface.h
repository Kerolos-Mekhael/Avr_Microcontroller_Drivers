#ifndef INTEEPROM_INTERFACE_H
#define INTEEPROM_INTERFACE_H

/* Write byte to EEPROM */
void IntEEPROM_WriteByte(u8 cop_Data, u16 cop_Address);

/* Read byte from EEPROM */
void IntEEPROM_ReadByte(u8 *pdata, u16 cop_Address);

/* Write sentence to EEPROM */
void IntEEPROMWriteSentence(u8 *pSentence, u16 cop_Address);

/* Write integer number to EEPROM */
void  IntEEPROMWriteIntNumber(u32 cop_u32Number,  u16 cop_Address);

/* Write floating-point number to EEPROM */
void IntEEPROMWriterealNumber(f32 cop_f32Number, u8 precision, u16 cop_Address);

/* Read number from EEPROM */
void IntEEPROMReadNumber(u8 *pNumber, u16 cop_Address);

/* Read Sentence from EEPROM */
void IntEEPROMReadSentence(u8 *pstr, u16 cop_Address);

#endif
