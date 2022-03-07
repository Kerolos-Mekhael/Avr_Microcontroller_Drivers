#ifndef I2C_INTERFACE_H
#define I2C_INTERFACE_H

#define CLOCK							8000000
#define	SCL_FREQUENCY					400000
#define	SLAVE_ADDRESS					1

typedef enum{
	Write 	,
	Read
}operation;

typedef enum {
	No_Error					,
	StartCondition_Error		,
	RepeatedStartCondition_Error,
	SlaveAddress_Error			,
	DataTransmitted_Error		,
	MasterDataReceived_Error	,
	SlaveDataReceived_Error
}Error_Status;

/* Initialize MCU as a Master */
void I2C_vidMasterInit(void);

/* Initialize MCU as a Slave */
void I2C_vidSlaveInit(void);

/* Start Condition as a Master */
Error_Status I2C_MasterStart(operation cop_operation, u8 cop_SlaveAddress);

/* Repeat Start Condition as a Master */
Error_Status I2C_MasterRepeatedStart(operation cop_operation, u8 cop_SlaveAddress);

/* Stop Condition as a Master */
void I2C_MasterStop(void);

/* Write Data as a Master */
Error_Status I2C_MasterWrite(u8 cop_Data);

/* Read Data as a Master */
Error_Status I2C_MasterRead(u8 *pdata);

/* Read Last Data as a Master */
Error_Status I2C_MasterLastRead(u8 *pdata);

/* Transmit Data as a Slave */
void I2C_SlaveTransmit(void);

/* Receive Data as a Slave */
Error_Status I2C_SlaveReceive(u8 *pdata);

#endif
