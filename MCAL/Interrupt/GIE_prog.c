#include "../../lib/BIT_MATH.h"
#include "../../lib/STD_TYPES.h"
#include "GIE_register.h"
#include "GIE_interface.h"

/* Enable global interrupt */
void GIE_vidSetBit(void){
	SET_BIT(SREG, SREG_I_BIT);
}

/* Disable global interrupt */
void GIE_vidCLRBit(void){
	CLR_BIT(SREG, SREG_I_BIT);
}
