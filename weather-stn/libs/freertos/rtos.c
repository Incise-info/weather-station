/*
 * rtos.c
 *
 * Created: 03-Mar-17 5:11:12 PM
 *  Author: Agarwal-pc
 */ 
#include <avr/io.h>
#include <util/delay.h>
#include "FreeRTOS.h"
#include "FreeRTOSConfig.h"
#include "task.h"
#include "queue.h"
#include "semphr.h"


uint8_t rtos_TaskCreate(TaskFunction_t pvTaskCode, const char * const pcName, uint16_t usStackDepth, void *pvParameters, UBaseType_t uxPriority, TaskHandle_t *pxCreatedTask)
{
	uint8_t Status_Task;
	Status_Task =xTaskCreate( pvTaskCode, pcName, usStackDepth, pvParameters, uxPriority, pxCreatedTask);
    return Status_Task;
}
void rtos_Delay(x)
{
	UBaseType_t time;
	//time = pdMS_TO_TICKS(x);
	vTaskDelay(x);
}

QueueHandle_t rtos_CreateQueue(QueueHandle_t Create_Queue, uint16_t Length, uint16_t Size )
{
	Create_Queue = xQueueCreate( Length , Size );
	return Create_Queue;
}


UBaseType_t rtos_QueueSendIntData(QueueHandle_t xQueue, uint8_t *pvItemToQueue,TickType_t xTicksToWait)
{
		UBaseType_t Queue_Status;
		Queue_Status = xQueueSend(xQueue, pvItemToQueue, xTicksToWait);
		return Queue_Status;
}

uint8_t rtos_QueueSendCharData(QueueHandle_t xQueue, UBaseType_t *pvItemToQueue, TickType_t xTicksToWait)
{
	UBaseType_t Queue_Status;
	Queue_Status = xQueueSend(xQueue, pvItemToQueue, xTicksToWait);
	return Queue_Status;
	
}

uint8_t rtos_QueueRecieveIntData(QueueHandle_t xQueue, uint8_t *pvBuffer,TickType_t xTicksToWait)
{
	UBaseType_t Queue_Status;
	Queue_Status =  xQueueReceive(xQueue, pvBuffer, xTicksToWait);
	return Queue_Status;
}

uint8_t rtos_QueueRecieveCharData(QueueHandle_t xQueue, UBaseType_t *pvBuffer, TickType_t xTicksToWait)
{
	UBaseType_t Queue_Status;
	Queue_Status =  xQueueReceive(xQueue, pvBuffer, xTicksToWait);
	return Queue_Status;
}

BaseType_t rtos_SemaphorGive(SemaphoreHandle_t Handle)
{
	BaseType_t T;
	T = xSemaphoreGive(Handle);
	return T;
}
BaseType_t rtos_SemaphorTake(SemaphoreHandle_t Handle ,TickType_t Wait_Time)
{ 
	BaseType_t T;
	T = xSemaphoreTake(Handle,Wait_Time);
	return T;
}

/*SemaphoreHandle_t  rtos_SemaphoreBinary(SemaphoreHandle_t Semaphore)
{
	SemaphoreHandle_t Test;
	Test = vSemaphoreCreateBinary( Semaphore );
	return Test;	
}*/