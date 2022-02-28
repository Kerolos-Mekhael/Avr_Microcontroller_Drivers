#include "../../../../lib/BIT_MATH.h"
#include "../../../../lib/STD_TYPES.h"
#include "../../../DIO/DIO_interface.h"
#include "../../Normal&CTC_Mode/Overflow_interface.h"
#include "../../Normal&CTC_Mode/Overflow_registers.h"
#include "../../../Interrupt/EXTI/EXTI_interface.h"
#include "SICU_interface.h"

u32 TON = 0, TOFF = 0, TotalPeriod = 0;

void Interrupt_Function(){
	static u8 counter=0;
	counter++;
	if(counter == 1){
		TCNT1L = 0;
		Set_IntEdge(EXTI_0, falling);
	}
	else if(counter == 2){
		TON = TCNT1L;
		TCNT1L = 0;
		Set_IntEdge(EXTI_0, rising);
	}
	else if(counter == 3){
		TOFF = TCNT1L;
		TotalPeriod = TON + TOFF;
		TCNT1L = 0;
		counter = 0;
	}
}

void Software_ICU_Init(){

	/* Initialization of Timer1 as overflow mode */
	Timer_vidInit(Timer1,Overflow);

	/* Enable External Interrupt 0 */
	EXTI0_vidEnable();

	/* Set rising edge for interrupt */
	Set_IntEdge(EXTI_0, rising);

}
