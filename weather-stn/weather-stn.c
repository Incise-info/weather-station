/*
 * weather_stn.c
 *
 * Created: 12/28/2016 11:59:51 AM
 *  Author: ROHIT
 */ 


#include <avr/io.h>
#include "libs/uart/uart.h"


int main(void)
{ 
	initUART();
    while(1)
    {
       writeString("Hello");
       putByte('\r');
       putByte('\n');
    }
	return 0;
}





