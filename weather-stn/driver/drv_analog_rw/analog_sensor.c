/*
 * analog_sensor.c
 *
 * Created: 02-Mar-17 11:30:14 AM
 *  Author: Lokesh
 */ 

#include "analog_sensor.h"
#include <avr/io.h>
#include <util/delay.h>
int adc_start()
{
	ADCSRA |= ADC_START << 7;
	if ((ADCSRA & 0x80) == 1))
	{
		return PASS;
	}
	else
	{
		return FAIL;
	}
}
int adc_read(char channel)
{
	ADCSRA |= ACD_CONV | ADC_INT_EN | ADC_FRQN;
	ADMUX |= ADC_EXT_REF | channel;
	while ((ADCSRA & 0x10)==0);
	_delay_us(5);
	return ADC;	
}
int adc_stop(void)
{
	ADCSRA &= ADCSTOP;
	if ((ADCSRA & 0x80) == 0))
	{
		return PASS;
	}
	else
	{
		return FAIL;
	}
}