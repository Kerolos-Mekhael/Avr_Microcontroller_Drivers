#include "../../lib/BIT_MATH.h"
#include "../../lib/STD_TYPES.h"
#include "WDT_interface.h"
#include "WDT_registers.h"

void WDT_Enable(void){

	/* Enable WDE Pin */
	SET_BIT(WDTCR, WDTCR_WDE);
}

void WDT_OFF(void){

	/* Enable WDE & WDTOE */
	WDTCR = (1 << WDTCR_WDE) | (1 << WDTCR_WDTOE);

	/* Clear Watchdog Timer Register */
	WDTCR = 0;
}

void WDT_SetTime(u8 timeout){

	WDTCR &= 0b11111000;
	WDTCR |= timeout;
}
