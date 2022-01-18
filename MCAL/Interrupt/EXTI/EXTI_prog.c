#include "../../../lib/BIT_MATH.h"
#include "../../../lib/STD_TYPES.h"
#include "EXTI_register.h"
#include "EXTI_interface.h"

/* Enable external interrupt_0 */
void EXTI0_vidEnable(void){
	
	/* Set Control */

	SET_BIT(MCUCR,MCUCR_ISC01);
	CLR_BIT(MCUCR,MCUCR_ISC00);

   /* Enable interrupt */
	SET_BIT(GICR,GICR_INT0);
}

/* Enable external interrupt_1 */
void EXTI1_vidEnable(void){

	/* Set Control */

	SET_BIT(MCUCR,MCUCR_ISC11);
	CLR_BIT(MCUCR,MCUCR_ISC10);

	/* Enable interrupt */
	SET_BIT(GICR,GICR_INT1);
}

/* Enable external interrupt_2 */
void EXTI2_vidEnable(void){

	/* Set Control */

	CLR_BIT(MCUCSR,MCUSR_ISC2);

	/* Enable interrupt */
	SET_BIT(GICR,GICR_INT2);
}

