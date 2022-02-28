#ifndef WDT_INTERFACE_H
#define WDT_INTERFACE_H

/* Enum for Time-out Periods */
typedef enum {
	_16ms	,
	_32ms	,
	_65ms	,
	_130ms	,
	_260ms	,
	_52ms	,
	_1s		,
	_2s
}Time_out;

/* Enable watchdog Timer */
void WDT_Enable(void);

/* Reset watchdog Timer */
void WDT_OFF(void);

/* Set timeout for watchdog Timer */
void WDT_SetTime(u8 timeout);

#endif
