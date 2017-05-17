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
#include "D:\Projects @ Incise\WS\weather-station\weather-stn\appc\app_bmp180\bmp180_app.h"
 float _data[] = {0,0};
int app_dht ()
{
		_data[0] = temp;
		_data[1] = humid;
		return (int*)_data;
}

void rec_data(int dat1, int dat2)
{
	dat1 = temp;
	dat2 = humid;
}