/*
 * Ram_Lite_Eng.c
 *
 *  Created on: Nov 30, 2025
 *      Author: lanjithkumar
 */

#include "Ram_Lite_Engine.h"

void RamLite_Engine_Task(void* pvParmeters){
	while(1){
		ulTaskNotifyTake(pdTRUE, portMAX_DELAY);
		DEBUG_PRINT("SQL Task: Received Notify!\n");
	}
}
