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

#ifndef MESSAGETYPE_H_
#define MESSAGETYPE_H_

enum MESSAGE_ID {
	/* */
	MSG_BMP_START=0,
	MSG_BMP_STOP,
	MSG_GET_BMP_TEMP,
	MSG_BMP_PRESSURE,

	/* */
	MSG_SOIL_START,
	MSG_SOIL_STOP,
	MSG_READ_SOIL_DATA,
	
	/* */
	MSG_MOST_START,
	MSG_MOST_STOP,
	MSG_READ_MOST_DATA
};
enum led{
	MSG_LED_START=0,MSG_LED_BLINK,MSG_LED_DBL_BLINK,MSG_LED_CNT_BLINK
	};




#endif /* MESSAGETYPE_H_ */