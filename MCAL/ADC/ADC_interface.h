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
u16 ADC_GetChannelReading(adc_channel cop_adcchannel);

/* Calculate Voltage Input */
f32 ADC_GetVoltageInput(adc_channel cop_adcchannel);

#endif
