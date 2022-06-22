#include "../../lib/BIT_MATH.h"
#include "../../lib/STD_TYPES.h"
#include "../DIO/DIO_interface.h"
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
u32 ADC_GetChannelReading(adc_channel cop_adcchannel){

	u32 ADC_u32Value=0;
	u8 ADC_Low , ADC_High;
	/* Select Channel */
	ADMUX = (ADMUX & 0xE0) | (cop_adcchannel);

	/* Start Conversion */
	SET_BIT(ADCSRA, ADCSRA_ADSC);

	/* Wait for conversion complete */
	while(GET_BIT(ADCSRA,ADCSRA_ADIF)==0);

	/* Clear ADC Flag */
	CLR_BIT(ADCSRA, ADCSRA_ADIF);

	/* Read ADC Value */
	ADC_u32Value  = ((u32)ADCH << 2) & 0x03ff;
	ADC_u32Value |= ((u32)ADCL >> 6) & 0x03;

	return ADC_u32Value;
}
