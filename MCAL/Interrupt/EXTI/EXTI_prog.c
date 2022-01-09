#include "../../lib/BIT_MATH.h"
#include "../../lib/STD_TYPES.h"
#include "EXTI_register.h"
#include "EXTI_interface.h"

void EXTI0_vidEnable(void){
	
	/* Set Control */
SET_BIT(MCUSR, MCUSR_ISC01);
CLR_BIT(MCUSR, MCUSR_ISC00);

   /* Enable interrupt */
SET_BIT(GICR, GICR_INT0);
	
}


