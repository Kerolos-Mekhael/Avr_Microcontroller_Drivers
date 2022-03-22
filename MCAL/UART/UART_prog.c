#include "../../lib/BIT_MATH.h"
#include "../../lib/STD_TYPES.h"
#include "../DIO/DIO_interface.h"
#include "UART_registers.h"
#include "UART_conf.h"
#include "UART_interface.h"


void UART_Init(){

	/* Select Asynchronous Mode */
	SET_BIT(UCSRC, UCSRC_URSEL);
	CLR_BIT(UCSRC, UCSRC_UMSEL);

	/* Disable Parity Mode */
	CLR_BIT(UCSRC, UCSRC_UPM0);
	CLR_BIT(UCSRC, UCSRC_UPM1);

	/* Select Stop Bit (1 bit) */
	CLR_BIT(UCSRC, UCSRC_USBS);

	/* Select character size (8 bits) */
	SET_BIT(UCSRC, UCSRC_UCSZ0);
	SET_BIT(UCSRC, UCSRC_UCSZ1);
	CLR_BIT(UCSRB, UCSRB_UCSZ2);

	/* Set Baud Rate */
	CLR_BIT(UCSRC, UCSRC_URSEL);
	UBRRL = (u8)UBRR;
	UBRRH |= (UBRR >> 8) & 0x0f;

	/* Enable Receiver & Transmitter */
	SET_BIT(UCSRB, UCSRB_TXEN);
	SET_BIT(UCSRB, UCSRB_RXEN);
}

void UART_Receive(u8 *pReceive){

	while(GET_BIT(UCSRA, UCSRA_RXC) == 0);
	*pReceive = UDR;

}

void UART_Transmit(u8 cop_u8Transmit){

	UDR = cop_u8Transmit;
	while(GET_BIT(UCSRA, UCSRA_UDRE) == 0);


}


