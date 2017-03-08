/*
 * rtos.h
 *
 * Created: 03-Mar-17 5:10:28 PM
 *  Author: Agarwal-pc
 */ 


#ifndef RTOS_H
#define RTOS_H

#include <stdint.h>
#include "FreeRTOS.h"
#include "queue.h"
#include "semphr.h"
#define PASS 1
#define FAIL 0

#define  rtos_Scheduler() vTaskStartScheduler()
#define  rtos_DeleteTask(pvParameter) vTaskDelete(pvParameter)
//#define  rtos_SemaphoreBinary(Semaphore) vSemaphoreCreateBinary( Semaphore )

//#define rtos_SemaphorTake(Handle ,Wait_Time) xSemaphoreTake(Handle,Wait_Time)
//#define  rtos_SemaphorGive(Handle) xSemaphoreGive(Handle)

uint8_t rtos_TaskCreate(TaskFunction_t pvTaskCode, const char * const pcName, uint16_t usStackDepth, void *pvParameters, UBaseType_t uxPriority, TaskHandle_t *pxCreatedTask);
QueueHandle_t rtos_CreateQueue(QueueHandle_t Create_Queue, uint16_t Length, uint16_t Size );
void rtos_Delay(x);
UBaseType_t rtos_QueueSendIntData(QueueHandle_t xQueue, uint8_t *pvItemToQueue,TickType_t xTicksToWait);
uint8_t rtos_QueueSendCharData(QueueHandle_t xQueue, UBaseType_t *pvItemToQueue,TickType_t xTicksToWait);
uint8_t rtos_QueueRecieveIntData(QueueHandle_t xQueue, uint8_t *pvBuffer,TickType_t xTicksToWait);
uint8_t rtos_QueueRecieveCharData(QueueHandle_t xQueue, UBaseType_t *pvBuffer,TickType_t xTicksToWait);
BaseType_t rtos_SemaphorGive(SemaphoreHandle_t Handle);
BaseType_t rtos_SemaphorTake(SemaphoreHandle_t Handle , TickType_t Wait_Time);
void  rtos_SemaphoreBinary(SemaphoreHandle_t Semaphore);
#endif /* RTOS_H_ */