/*
 * analog_sensor.h
 *
 * Created: 02-Mar-17 11:28:58 AM
 *  Author: Lokesh
 */ 


#ifndef ANALOG_SENSOR_H_
#define ANALOG_SENSOR_H_
#define ADC_START 1;
#define ADC_STOP 0;
#define PASS 1;
#define FAIL 0;
#define ACD_CONV 64;
#define ADC_EXT_REF 64;
#define ADC_INT_REF 192;
#define ADC_FRQN 7;
#define ADC_INT_EN 16;
int adc_start(void);
int adc_read(void);
int adc_stop(void);


#endif /* ANALOG_SENSOR_H_ */