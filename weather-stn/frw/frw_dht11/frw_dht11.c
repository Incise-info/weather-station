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

#include <avr/io.h>
#include <stdlib.h>
#include <stdio.h>
#include <util/delay.h>
#include "frw_dht11.h"
#include "app_dht11.h"


void Request()  /* Microcontroller send start pulse or request */
{
	DDRD |= (1<<DHT11_PIN);
	PORTD &= ~(1<<DHT11_PIN);  /* set to low pin */
	_delay_ms(20);  /* wait for 20ms */
	PORTD |= (1<<DHT11_PIN);  /* set to high pin */
}

void Response()  /* receive response from DHT11 */
{
	DDRD &= ~(1<<DHT11_PIN);
	while(PIND & (1<<DHT11_PIN));
	while((PIND & (1<<DHT11_PIN))==0);
	while(PIND & (1<<DHT11_PIN));
}

uint8_t Receive_data()  /* receive data */
{
	for (int q=0; q<8; q++)
	{
		while((PIND & (1<<DHT11_PIN)) == 0);  /* check received bit 0 or 1 */
		_delay_us(30);
		if(PIND & (1<<DHT11_PIN))  /* if high pulse is greater than 30ms */
		c = (c<<1)|(0x01);  /* then its logic HIGH */
		else                       /* otherwise its logic LOW */
		c = (c<<1);
		while(PIND & (1<<DHT11_PIN));
	}
	return c;
}

void Get_data()
{
	
		Request();  /* send start pulse */
		Response();	 /* receive response */
		I_RH=Receive_data();  /* store first eight bit in I_RH */
		D_RH=Receive_data();  /* store next eight bit in D_RH */
		I_Temp=Receive_data();  /* store next eight bit in I_Temp */
		D_Temp=Receive_data();  /* store next eight bit in D_Temp */
		CheckSum=Receive_data();  /* store next eight bit in CheckSum */
		
		if ((I_RH + D_RH + I_Temp + D_Temp) != CheckSum)
		{
			writeString("Error");
		}
		
	/*	else
		{
			itoa(I_RH,data,10);
			writeString(data);
			writeString(".");
			
			itoa(D_RH,data,10);
			writeString(data);
			writeString("%");

			itoa(I_Temp,data,10);
			writeString(data);
			writeString(".");
			
			itoa(D_Temp,data,10);
			writeString(data);
			writeString("*C");
			
			itoa(CheckSum,data,10);
			writeString(data);
		}*/
				
		else
		{
			void fun_ptr(int,int) = rec_data;
			push_data(fun_ptr,I_RH,I_Temp);
		}
}

int push_data(void (*fun_ptr)(int, int), uint8_t Hd,uint8_t Tp)
{
	fun_ptr(Hd,Tp);
	return 1;
}