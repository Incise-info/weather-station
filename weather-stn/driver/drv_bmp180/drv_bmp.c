#include "drv_bmp.h"

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

/****************************************************************************************************************************************/
/*  BMP180  Pressure and Temperature Sensor 																							*/
/*	Works on I2C Protocol																												*/
/*	BMP180 Connection																													*/
/*	SCL - A5;																															*/
/*	SDA - A4;																															*/
/*	These pins should be connected with pullup register ( 2 to 10 KOhm)																	*/
/*	Supply voltage: 1.8 ... 3.6V (VDD)																									*/
/*	Temperature range:	-40 to +85																										*/
/*	Pressure range:	300 ... 1100 hPa																									*/
/*	Algorithm :																															*/
/*		1. Start -> Module ADD -> Register Address -> Restart ->Measurnment Control ->Restart											*/
/* 		Module Address: 0xEE																											*/
/* 		Register Address:																												*/
/* 																																		*/
/* 		Register Name  | Register Adress	|	bit7	|	bit6  | 	bit5  |	bit4  |	bit3  |	bit2  |	bit1  |	bit0  |	Reset state		*/
/* 		out_xlsb	   |	F8h				|					    	adc_out_xlsb<7:3>	  |	 0	  |	  0	  |	  0	  |		00h			*/
/* 	 	out_lsb		   |	F7h				|						 	adc_out_lsb<7:0>							  |		00h			*/
/* 		out_msb		   |	F6h				|			|		  |    adc_out_msb<7:0>								  |		80h			*/
/* 		ctrl_meas	   | 	F4h				|		oss<1:0> 	  |  	sco	  |			measurement control			  |		00h			*/
/* 		soft reset	   |	E0h				|			|		  |				reset								  |		00h			*/
/* 		id			   |	D0h				|							id<7:0>										  |		55h			*/
/* 	 	calib21	calib0 | BFh downto AAh		|			calib21<7:0> downto calib0<7:0>								  |		n/a			*/
/* 	 																																	*/
/*	 	Measurement 	  Register	Max Time (ms)																						*/
/* 	 	Temperature 		0x2E		4.5																								*/
/*	 	Pressure (oss = 0) 	0x34		4.5																								*/
/*	 	Pressure (oss = 1) 	0x74		7.5																								*/
/*	 	Pressure (oss = 2) 	0xB4		13.5																							*/
/* 	 	Pressure (oss = 3) 	0xF4		25.5																							*/
/*																																		*/
/*		2. After restart ( See step 1 ) -> Module Address(0xEE write) -> Register Address (i.e F6-MSB, F7-LSB ) -> Restart				*/
/*		3. After restart ( See step 2) -> Module Add (0xEF read) -> Read ( MSB) -> Read (LSB)											*/
/*																																		*/
/*																																		*/
/****************************************************************************************************************************************/



int init_bmp(void)
{
	/* Write code for init the BMP180 sensor */
}

int start_bmp()
{
	/*   write code for start the BMP180, write address of BMP   */
}

int stop_bmp()
{
	/*   write code for stop the BMP180   */
}
int read_data_bmp()
{
	/*  write code for read data from BMP180, first write reg add then read data  */
}
