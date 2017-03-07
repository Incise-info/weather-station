/*
 * rtos.h
 *
 * Created: 03-Mar-17 5:10:28 PM
 *  Author: Agarwal-pc
 */ 


#ifndef RTOS_H_
#define RTOS_H_
#define PASS 1
#define FAIL 0


uint8_t rtos_TaskCreate(TaskHandle_t pvTaskCode, const char * const pcName, uint16_t usStackDepth, void *pvParameters, UBaseType_t uxPriority, TaskHandle_t *pxCreatedTask);
void rtos_Scheduler();
uint8_t rtos_CreateQueue(QueueHandle_t Create_Queue, uint16_t Length, uint16_t Size );
void rtos_Delay(uint16_t x);
void rtos_DeleteTask(TaskHandle_t pvParameter);
uint8_t rtos_QueueSendIntData(QueueHandle_t xQueue, uint8_t *pvItemToQueue,TickType_t xTicksToWait);
uint8_t rtos_QueueSendCharData(QueueHandle_t xQueue, UBaseType_t *pvItemToQueue,TickType_t xTicksToWait);
uint8_t rtos_QueueRecieveIntData(QueueHandle_t xQueue, uint8_t *pvBuffer,TickType_t xTicksToWait);
uint8_t rtos_QueueRecieveCharData(QueueHandle_t xQueue, UBaseType_t *pvBuffer,TickType_t xTicksToWait);
uint8_t rtos_SemaphoreBinary(SemaphoreHandle_t Semaphore);
BaseType_t rtos_SemaphorGive(SemaphoreHandle_t Handle);
BaseType_t rtos_SemaphorTake(SemaphoreHandle_t Handle , TickType_t Wait_Time);

#endif /* RTOS_H_ */