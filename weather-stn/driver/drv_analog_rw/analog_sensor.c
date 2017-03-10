/************************************************************************************************/
/*	This file is part of Incise Weather Station.												*/
/*																								*/
/*	Incise Weather Station is free software: you can redistribute it and/or modify				*/
/*	it under the terms of the GNU General Public License as published by						*/
/*	the Free Software Foundation, either version 3 of the License, or							*/
/*	(at your option) any later version.															*/
/*																								*/
/*	Foobar is distributed in the hope that it will be useful,									*/
/*	but WITHOUT ANY WARRANTY; without even the implied warranty of								*/
/*	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the								*/
/*	GNU General Public License for more details.												*/
/*																								*/
/*	You should have received a copy of the GNU General Public License							*/
/*	along with Foobar.  If not, see <http://www.gnu.org/licenses/>.                             */
/************************************************************************************************/
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