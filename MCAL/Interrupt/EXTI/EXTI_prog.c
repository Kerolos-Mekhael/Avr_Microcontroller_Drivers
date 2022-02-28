#include "../../../lib/BIT_MATH.h"
#include "../../../lib/STD_TYPES.h"
#include "EXTI_register.h"
#include "EXTI_interface.h"

void (* Callback_IntPtr)(void) = '\0';

/* Callback Function */
void Callback_Intfunction(void(* ptr)()){

	if(ptr != '\0'){
		 Callback_IntPtr = ptr;
	}
}

/* Set the required edge for external interrupt */
void Set_IntEdge(EXT_Int cop_EXTI, edge cop_edge){

	if(cop_edge == falling){
		switch(cop_EXTI){
			case EXTI_0:SET_BIT(MCUCR,MCUCR_ISC01);
						CLR_BIT(MCUCR,MCUCR_ISC00); break;

			case EXTI_1:SET_BIT(MCUCR,MCUCR_ISC11);
						CLR_BIT(MCUCR,MCUCR_ISC10); break;

			case EXTI_2:CLR_BIT(MCUCSR,MCUCSR_ISC2);break;
		}
	}
	else if(cop_edge == rising){
		switch(cop_EXTI){
			case EXTI_0:SET_BIT(MCUCR,MCUCR_ISC01);
						SET_BIT(MCUCR,MCUCR_ISC00); break;

			case EXTI_1:SET_BIT(MCUCR,MCUCR_ISC11);
						SET_BIT(MCUCR,MCUCR_ISC10); break;

			case EXTI_2:SET_BIT(MCUCSR,MCUCSR_ISC2);break;
		}
	}
}

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
	CLR_BIT(MCUCSR,MCUCSR_ISC2);

	/* Enable interrupt */
	SET_BIT(GICR,GICR_INT2);
}

/* Interrupt Service Routine for EXTI_0 */
void __vector_1(void) __attribute__ ((signal));
void __vector_1(void){
	 Callback_IntPtr();
}

/* Interrupt Service Routine for EXTI_1 */
void __vector_2(void) __attribute__ ((signal));
void __vector_2(void){
	 Callback_IntPtr();
}

/* Interrupt Service Routine for EXTI_2 */
void __vector_3(void) __attribute__ ((signal));
void __vector_3(void){
	 Callback_IntPtr();
}
