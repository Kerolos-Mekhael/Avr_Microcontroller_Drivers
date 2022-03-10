#include "BIT_MATH.h"
#include "STD_TYPES.h"
#include "DIO_interface.h"
#include "ADC_registers.h"
#include "ADC_configuration.h"
#include "ADC_interface.h"

/* Initialization of ADC */
void ADC_vidInit(){

	/* Select Voltage Reference VCC */
	CLR_BIT(ADMUX, ADMUX_REFS1);
	SET_BIT(ADMUX, ADMUX_REFS0);

	/* Select Left Shift */
	SET_BIT(ADMUX, ADMUX_ADLAR);

	/* Select Prescaler 64 */
	CLR_BIT(ADCSRA, ADCSRA_ADPS0);
	SET_BIT(ADCSRA, ADCSRA_ADPS1);
	SET_BIT(ADCSRA, ADCSRA_ADPS2);

	/* Enable ADC */
	SET_BIT(ADCSRA, ADCSRA_ADEN);

}

/* Reading of ADC */
u16 ADC_GetChannelReading(adc_channel cop_adcchannel){

	u16 ADC_u16Value=0;

	/* Select Channel */
	ADMUX = (ADMUX & 0xE0) | (cop_adcchannel);

	/* Start Conversion */
	SET_BIT(ADCSRA, ADCSRA_ADSC);

	/* Wait for conversion complete */
	while(GET_BIT(ADCSRA,ADCSRA_ADIF)==0);

	/* Clear ADC Flag */
	CLR_BIT(ADCSRA, ADCSRA_ADIF);

	/* Read ADC Value */
	ADC_u16Value  = ((u16)ADCL >> 6) & 0x03;
	ADC_u16Value |= ((u16)ADCH << 2) & 0x03ff;

	return ADC_u16Value;
}

f32 ADC_GetVoltageInput(adc_channel cop_adcchannel){

	u16 Result=0;
	f32 Vout = 0.0;
	Result = ADC_GetChannelReading(cop_adcchannel);
	Vout = Result * ((f32)VOLTAGE_REF / RESOLUTION);
	return Vout ;
}
