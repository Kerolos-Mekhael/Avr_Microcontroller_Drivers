#ifndef	EXTI_INTERFACE_H
#define EXTI_INTERFACE_H

/* Enum to select edge */
typedef enum{
	falling	,
	rising
}edge;

/* Enum to select external interrupt */
typedef enum{
	EXTI_0	,
	EXTI_1	,
	EXTI_2
}EXT_Int;

void Set_IntEdge(EXT_Int cop_EXTI, edge cop_edge);

void Callback_Intfunction(void(* ptr)());

void EXTI0_vidEnable(void);

void EXTI1_vidEnable(void);

void EXTI2_vidEnable(void);

#endif
