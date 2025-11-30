/*
 * SPDX-FileCopyrightText: 2010-2022 Espressif Systems (Shanghai) CO LTD
 *
 * SPDX-License-Identifier: CC0-1.0
 */

// Our custom Headers
#include "RAM_LITE_DB_MAIN.h"
#include "freertos/idf_additions.h"

// extern this hanlder
TaskHandle_t RAMlitehandler;
TaskHandle_t RamLiteDb_Shell_hanlder;
BaseType_t RamTaskBasetype;


// Debug printer
void DEBUG_PRINT_CONSOLE(const char *fmt, ...)
{
    va_list args;
    va_start(args, fmt);

    vprintf(fmt, args);
    fflush(stdout);

    va_end(args);
}


// System info
void RAM_LITE_DB_SYSTEM_INFO(void)
{
    DEBUG_PRINT("\n--- RAMLiteDB System Info ---\n");
    DEBUG_PRINT("Free Heap: %u bytes\n", heap_caps_get_free_size(MALLOC_CAP_8BIT));

    UBaseType_t watermark = uxTaskGetStackHighWaterMark(NULL);
    DEBUG_PRINT("Free Stack: %u bytes\n", watermark * sizeof(StackType_t));

    DEBUG_PRINT("----------------------------\n");
}


// Create Shell Task (20 KB stack for safety)
void Config_Custom_Tasks(void)
{
    RamTaskBasetype = xTaskCreate(
        RamLiteDb_Shell_Task,
        "RamLiteDB_Shell",
        Ramlite_Shell,                     // 20KB stack (SAFE for fgets, printf)
        NULL,
        RamLiteDb_Shell_PRIORITY,
        &RamLiteDb_Shell_hanlder
    );

    if(RamTaskBasetype == pdPASS)
        DEBUG_PRINT("RamLiteDb Shell Task Configured Successfully \n");
    else
        DEBUG_PRINT("RamLiteDb Shell Task Creation Failed \n");
}


// Basic Config Task (8 KB stack)
void Basic_Config(void* pargs)
{
    RAM_LITE_DB_SYSTEM_INFO();
    Config_Custom_Tasks();
    vTaskDelete(NULL);
}


// app_main (scheduler already running)
void app_main(void)
{
    DEBUG_PRINT("RAM_LITE_DATABASE=V0.1 \n");
    DEBUG_PRINT("RAM LITE DATABASE \n");

    RamTaskBasetype = xTaskCreate(
        Basic_Config,
        "RAM_LITE_CONFIG",
        basic_Config,                 // 8 KB safe stack
        NULL,
        SHELL_TASK_PRIORITY,
        &RAMlitehandler
    );

    if (RamTaskBasetype != pdPASS)
    {
        DEBUG_PRINT("RAM LITE DB CONFIG TASK FAILED\n");
    }
}

