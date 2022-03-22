#ifndef UART_INTERFACE_H
#define UART_INTERFACE_H

/* Initialization of UART */
void UART_Init(void);

/* Receive UART Data */
void UART_Receive(u8 *pReceive);

/* Transmit UART Data */
void UART_Transmit(u8 cop_u8Transmit);

#endif
