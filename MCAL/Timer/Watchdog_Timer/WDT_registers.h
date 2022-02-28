#ifndef WDT_REGISTERS_H
#define WDT_REGISTERS_H

#define WDTCR			*((volatile *) 0x41)
#define WDTCR_WDP0			0
#define WDTCR_WDP1			1
#define WDTCR_WDP2			2
#define WDTCR_WDE			3
#define WDTCR_WDTOE			4

#endif
