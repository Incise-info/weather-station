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


uint8_t rtos_TaskCreate(TaskHandle_t pvTaskCode, const char * const pcName, uint16_t usStackDepth, void *pvParameters, UBaseType_t uxPriority, TaskHandle_t *pxCreatedTask);
{
	uint8_t Status_Task;
	Status_Task =xTaskCreate( pvTaskCode, pcName, usStackDepth, pvParameters, uxPriority, pxCreatedTask);
    return Status_Task;
}
void rtos_Scheduler()
{
	vTaskStartScheduler();
	return PASS;
}
uint8_t rtos_CreateQueue(QueueHandle_t Create_Queue, uint16_t Length, uint16_t Size )
{
	Create_Queue = xQueueCreate( Length , Size );
	return Create_Queue;
}
void rtos_Delay(uint16_t x)
{
	vTaskDelay(x);
}

void rtos_DeleteTask(TaskHandle_t pvParameter)
{
	vTaskDelete(pvParameter);
}

uint8_t rtos_QueueSendIntData(QueueHandle_t xQueue, uint8_t *pvItemToQueue,TickType_t xTicksToWait)
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
	return Queue_Status
}

uint8_t rtos_QueueRecieveCharData(QueueHandle_t xQueue, UBaseType_t *pvBuffer, TickType_t xTicksToWait)
{
	UBaseType_t Queue_Status;
	Queue_Status =  xQueueReceive(xQueue, pvBuffer, xTicksToWait);
	return Queue_Status;
}

uint8_t rtos_SemaphoreBinary(SemaphoreHandle_t Semaphore)
{
	UBaseType_t Status_Binary = vSemaphoreCreateBinary(Semaphore);
	return Status_Binary;
}

BaseType_t rtos_SemaphorTake(SemaphoreHandle_t Handle , TickType_t Wait_Time)
{
	BaseType_t Status_Take;
	Status_Take = xSemaphoreTake(Handle);
	return Status;
}

BaseType_t rtos_SemaphorGive(SemaphoreHandle_t Handle)
{
	uint8_t Status_Give;
	Status_Give = xSemaphoreGive(Handle);
	return Status_Give;
}
