TaskFunction pvTaskCode(void *pvParameters){
	uint8_t Data;
	adc_start();
	Data = adc_read(0);
	adc_stop();
	
}