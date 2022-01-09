#include "../../lib/BIT_MATH.h"
#include "../../lib/STD_TYPES.h"
#include "../../MCAL/DIO/DIO_interface.h"
#include "Segment_configuration.h"
#include "Segment_interface.h"


/* Display Numbers on 7-Segment */
void Display_7SegmentNumber(enum_port cop_enumport, u8 cop_u8number, segment_type cop_segmenttype){
	u8 Arr_Numbers[10] = SEGMENT_NUMBERS;

		if(cop_segmenttype == CommonCathode){
			DIO_u8SetPortValue(SEGMENT_PORT ,Arr_Numbers[cop_u8number]);
		}

		else if(cop_segmenttype == CommonAnode){
			DIO_u8SetPortValue(SEGMENT_PORT , ~ Arr_Numbers[cop_u8number]);
			}
}
