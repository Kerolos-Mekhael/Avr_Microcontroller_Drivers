#ifndef SEGMENT_INTERFACE_H
#define SEGMENT_INTERFACE_H

/* Type of seven segment */
typedef enum{
	CommonCathode,
	CommonAnode
}segment_type;

/* Display Numbers on 7-Segment */
void Display_7SegmentNumber(enum_port cop_enumport, u8 cop_u8number, segment_type cop_segmenttype);

#endif
