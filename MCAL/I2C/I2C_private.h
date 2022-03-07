#ifndef I2C_PRIVATE_H
#define I2C_PRIVATE_H

#define STATUS_VAL									(TWSR & 0b11111100)

/* Status Codes for Master Receiver Mode */
#define	 START_CONDITION_TRANSMITTED 					0x08
#define	 REPEATED_START_CONDITION_TRANSMITTED 			0x10
#define	 ARBITRATION_LOST_SLA 							0x38
#define	 SLA_R_TRANSMITTED_ACK				  			0x40
#define	 SLA_R_TRANSMITTED_NACK  						0x48
#define	 DATA_RECIVED_ACK  								0x50
#define	 DATA_RECIVED_NACK 								0x58
/*******************************************************************/
/* Status Codes for Master Transmitter Mode */
#define	 SLA_W_TRANSMITTED_ACK				  			0x18
#define	 SLA_W_TRANSMITTED_NACK  						0x20
#define	 DATA_TRANSMITTED_ACK  							0x28
#define	 DATA_TRANSMITTED_NACK 							0x30
/*******************************************************************/
 /* Status Codes for Slave Receiver Mode */
#define	 SLA_W_RECEIVED 							 	0x60
#define	 OWN_SLA_R_W_RECEIVED_MASTER  					0x68
#define	 GENERAL_CALL_ADDRESS_RECEIVED  				0x70
#define	 GENERAL_CALL_ADDRESS_RECIVED_MASTER  			0x78
#define	 OWN_SLA_DATA_RECIVED_ACK  						0x80
#define	 OWN_SLA_DATA_RECIVED_NACK  					0x88
#define	 GENERAL_CALL_DATA_RECIVED_ACK 					0x90
#define	 GENERAL_CALL_DATA_RECIVED_NACK  				0x98
#define	 STOP_CONDITION_OR_REPEATED_START_CONDITION 	0xA0
/*******************************************************************/
 /* Status Codes for Slave Transmitter Mode */
#define	 OWN_SLA_R_W_RECIVED 							0xA8
#define	 OWN_SLA_R_W_RECIVED_MASTER  					0xB0
#define	 DATA_BYTE_TRANSMITTED_ACK 						0xB8
#define	 DATA_BYTE_TRANSMITTED_NACK  					0xC0
#define	 LAST_DATA_BYTE_TRANSMITTED_ACK  				0xC8

#endif
