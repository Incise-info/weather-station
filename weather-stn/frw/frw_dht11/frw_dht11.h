#ifndef frw_dht11
#define frw_dht11

#define DHT11_PIN 6
uint8_t c=0,I_RH,D_RH,I_Temp,D_Temp,CheckSum;
uint8_t Receive_data();
void Response();
void Request();
void Get_data();
int push_data(void (*fun_ptr)(int,int), uint8_t, uint8_t );
void *fun_ptr;


#endif