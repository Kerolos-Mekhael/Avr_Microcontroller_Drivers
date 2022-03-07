#include "../../lib/BIT_MATH.h"
#include "../../lib/STD_TYPES.h"
#include "INTEEPROM_registers.h"
#include "INTEEPROM_interface.h"

void IntEEPROM_WriteByte(u8 cop_Data, u8 cop_Address){

	while(GET_BIT(EECR, EECR_EEWE) == 1);		/* Wait until EEWE becomes zero */
	EEAR = cop_Address;							/* Write new EEPROM address */
	EEDR = cop_Data;							/* Write new EEPROM data */
	SET_BIT(EECR, EECR_EEMWE);
	SET_BIT(EECR, EECR_EEWE);
}
void IntEEPROM_ReadByte(u8 *pdata, u8 cop_Address){
	while(GET_BIT(EECR, EECR_EEWE) == 1);		/* Wait until EEWE becomes zero */
	EEAR = cop_Address;							/* Write new EEPROM address */
	SET_BIT(EECR, EECR_EERE);
	*pdata = EEDR;
}

