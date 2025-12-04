/*
 * RAM_LITE_DB_MAIN.h
 *
 *  Created on: Nov 24, 2025
 *      Author: lanjithkumar
 */

// standar c files
#include <stdio.h>
#include <string.h>
#include <inttypes.h>

// Freertos Files
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "portmacro.h"


#ifndef MAIN_RAM_LITE_DB_MAIN_H_
#define MAIN_RAM_LITE_DB_MAIN_H_

#include "Main_Shell.h"

// externing the Hnadler 
extern TaskHandle_t RAMlitehandler;
extern TaskHandle_t RamLiteDb_Shell_hanlder;


#define basic_Config  8192
#define Ramlite_Shell 20480

#define SHELL_TASK_PRIORITY   24
#define RamLiteDb_Shell_PRIORITY 23


#if defined(RAM_LITE_CONSOLE)
    #define DEBUG_PRINT(fmt, ...)  printf(fmt, ##__VA_ARGS__)
#else
    #define DEBUG_PRINT(fmt, ...)  do {} while(0)
#endif

void app_main(void);
void Basic_Config(void* pargs);


#endif /* MAIN_RAM_LITE_DB_MAIN_H_ */
