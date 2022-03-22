#ifndef UART_CONF_H
#define UART_CONF_H

#define fOSC			8000000
#define	BaudRate		9600
#define UBRR		((fOSC / (16*BaudRate))-1)

#endif
