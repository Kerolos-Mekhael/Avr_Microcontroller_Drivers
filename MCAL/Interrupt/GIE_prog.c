#include "../../lib/BIT_MATH.h"
#include "../../lib/STD_TYPES.h"
#include "GIE_register.h"
#include "GIE_interface.h"

void GIE_vidSetBit(void){
	SET_BIT(SREG, SREG_I_BIT);
}