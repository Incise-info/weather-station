/*
 * messagetype.h
 *
 * Created: 09-Mar-17 6:56:12 PM
 *  Author: Lokesh
 */ 


#ifndef MESSAGETYPE_H_
#define MESSAGETYPE_H_

enum bmp{
	MSG_BMP_START=0,MSG_BMP_STOP,MSG_GET_BMP_TEMP,MSG_BMP_PRESSURE
	};
enum soil{
	MSG_SOIL_START=0,MSG_SOIL_STOP,MSG_READ_SOIL_DATA
	};
enum most{
	MSG_MOST_START=0,MSG_MOST_STOP,MSG_READ_MOST_DATA
};




#endif /* MESSAGETYPE_H_ */