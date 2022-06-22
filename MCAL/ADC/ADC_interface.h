#ifndef ADC_INTERFACE_H
#define ADC_INTERFACE_H

/* ADC Channels */
typedef enum{
	ADC0 ,
	ADC1 ,
	ADC2 ,
	ADC3 ,
	ADC4 ,
	ADC5 ,
	ADC6 ,
	ADC7 
}adc_channel;

/* Initialization of ADC */
void ADC_vidInit(void);

/* Reading of ADC */
u32 ADC_GetChannelReading(adc_channel cop_adcchannel);

#endif