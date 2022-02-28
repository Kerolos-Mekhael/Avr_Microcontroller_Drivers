#ifndef SPI_INTERFACE_H
#define SPI_INTERFACE_H


/* Initialize Master */
void SPI_vidMasterInit(void);

/*Initialize Slave */
void SPI_vidSlaveInit(void);

/* Transmit Data */
void SPI_u8Transmit(u8 cop_u8Data);

/* Receive Data */
u8 SPI_u8Receive(void);

/* Send Sentence over SPI */
void SPI_vidSendSentence(u8 *pSentence);

/* Send integer number over SPI */
void SPI_vidSendIntNumber(u32 cop_u32Number);

/* Send floating_point number over SPI */
void SPI_vidSendrealNumber(f32 cop_f32Number, u8 precision);

#endif
