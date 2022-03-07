#include "../../lib/BIT_MATH.h"
#include "../../lib/STD_TYPES.h"
#include "../DIO/DIO_interface.h"
#include "I2C_configuration.h"
#include "I2C_registers.h"
#include "I2C_private.h"
#include "I2C_interface.h"

void I2C_vidMasterInit(){

	/* Set Address as a Slave */
	TWAR = (SLAVE_ADDRESS << 1);

	/* Enable Acknowledgment */
	SET_BIT(TWCR, TWCR_TWEA);

	/* Set Prescaler */
	CLR_BIT(TWSR, TWSR_TWPS0);
	CLR_BIT(TWSR, TWSR_TWPS1);

	/* Generate Bit Rate */
	TWBR = (BIT_RATE << 3) & 0xf8;

	/* Enable TWI */
	SET_BIT(TWCR, TWCR_TWEN);

}

void I2C_vidSlaveInit(){

	/* Enable Acknowledgment */
	SET_BIT(TWCR, TWCR_TWEA);

	/* Set Address as a Slave */
	TWAR = (SLAVE_ADDRESS << 1);

	/* Enable TWI */
	SET_BIT(TWCR, TWCR_TWEN);
}

Error_Status I2C_MasterStart(operation cop_operation, u8 cop_SlaveAddress){

	u8 Error_Status=0;
	SET_BIT(TWCR, TWCR_TWSTA);				/* Generate start condition */
	SET_BIT(TWCR, TWCR_TWINT);				/* Clear TWI Interrupt Flag */

	while(GET_BIT(TWCR, TWCR_TWINT) == 0);	/* Wait until task finish */

	if(STATUS_VAL == START_CONDITION_TRANSMITTED)		/* Check status code */
	{
		Error_Status = No_Error;
	}else
	{
		Error_Status = StartCondition_Error;
	}

	TWDR = (cop_SlaveAddress << 1) & cop_operation;			/* SLW + RW */
	CLR_BIT(TWCR, TWCR_TWSTA);				/* Clear start condition */
	SET_BIT(TWCR, TWCR_TWINT);				/* Clear TWI Interrupt Flag */

	while(GET_BIT(TWCR, TWCR_TWINT) == 0);	/* Wait until task finish */

	if(STATUS_VAL == SLA_W_TRANSMITTED_ACK ||STATUS_VAL == SLA_R_TRANSMITTED_ACK)		/* Check status code */
	{
		Error_Status = No_Error;
	}else
	{
		Error_Status = SlaveAddress_Error;
	}
	return Error_Status;
}

Error_Status I2C_MasterRepeatedStart(operation cop_operation, u8 cop_SlaveAddress){
	u8 Error_Status=0;
	SET_BIT(TWCR, TWCR_TWSTA);				/* Generate start condition */
	SET_BIT(TWCR, TWCR_TWINT);				/* Clear TWI Interrupt Flag */

	while(GET_BIT(TWCR, TWCR_TWINT) == 0);	/* Wait until task finish */

	if(STATUS_VAL == REPEATED_START_CONDITION_TRANSMITTED)		/* Check status code */
	{
		Error_Status = No_Error;
	}else
	{
		Error_Status = RepeatedStartCondition_Error;
	}

	TWDR = (cop_SlaveAddress << 1) | cop_operation;			/* SLW + RW */
	CLR_BIT(TWCR, TWCR_TWSTA);								/* Clear start condition */
	SET_BIT(TWCR, TWCR_TWINT);								/* Clear TWI Interrupt Flag */

	while(GET_BIT(TWCR, TWCR_TWINT) == 0);					/* Wait until task finish */

	if((STATUS_VAL == SLA_W_TRANSMITTED_ACK) || (STATUS_VAL == SLA_R_TRANSMITTED_ACK))	/* Check status code */
	{
		Error_Status = No_Error;
	}else
	{
		Error_Status = SlaveAddress_Error;
	}
	return Error_Status;
}

void I2C_MasterStop(){

	SET_BIT(TWCR, TWCR_TWSTO);				/* Generate stop condition */
	SET_BIT(TWCR, TWCR_TWINT);				/* Clear TWI Interrupt Flag */
	while(GET_BIT(TWCR, TWCR_TWINT) == 0);	/* Wait until task finish */
}

Error_Status I2C_MasterWrite(u8 cop_Data){

	TWDR = cop_Data;
	SET_BIT(TWCR, TWCR_TWINT);				/* Clear TWI Interrupt Flag */
	while(GET_BIT(TWCR, TWCR_TWINT) == 0);	/* Wait until task finish */

	if(STATUS_VAL == DATA_TRANSMITTED_ACK)		/* Check status code */
	{
		return No_Error;
	}else
	{
		return DataTransmitted_Error;
	}
}

Error_Status I2C_MasterRead(u8 *pdata){

	SET_BIT(TWCR, TWCR_TWINT);				/* Clear TWI Interrupt Flag */
	CLR_BIT(TWCR, TWCR_TWEA);				/* Disable Acknowledgment */
	SET_BIT(TWCR, TWCR_TWEN);				/* Enable TWI */
	while(GET_BIT(TWCR, TWCR_TWINT) == 0);	/* Wait until task finish */
	*pdata = TWDR;
	if(STATUS_VAL == DATA_RECIVED_ACK )		/* Check status code */
	{
		return No_Error;
	}else
	{
		return MasterDataReceived_Error;
	}
}

Error_Status I2C_MasterLastRead(u8 *pdata){

	SET_BIT(TWCR, TWCR_TWINT);				/* Clear TWI Interrupt Flag */
	while(GET_BIT(TWCR, TWCR_TWINT) == 0);	/* Wait until task finish */
	*pdata = TWDR;
	if(STATUS_VAL == DATA_RECIVED_NACK)		/* Check status code */
	{
		return No_Error;
	}else
	{
		return MasterDataReceived_Error;
	}
}


Error_Status I2C_SlaveReceive(u8 *pdata){

	SET_BIT(TWCR, TWCR_TWINT);				/* Clear TWI Interrupt Flag */
	while(GET_BIT(TWCR, TWCR_TWINT) == 0);	/* Wait until task finish */
	*pdata = TWDR;
	if(STATUS_VAL == OWN_SLA_DATA_RECIVED_ACK)		/* Check status code */
	{
		return No_Error;
	}else
	{
		return SlaveDataReceived_Error;
	}
}
