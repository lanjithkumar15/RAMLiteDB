/*
 * Main_Shell.c
 *
 *  Created on: Nov 25, 2025
 *      Author: lanjithkumar
 */



#include "Main_Shell.h"

char inputfromcli[256];

void RamLiteDb_Shell_Task(void* pvParameters){
	
	while (1) {
        if (fgets(inputfromcli, sizeof(inputfromcli), stdin) != NULL)
        {
            char *newline = strchr(inputfromcli, '\n');
            if (newline) *newline = '\0';
            
            newline = strchr(inputfromcli, '\r');
            if (newline) *newline = '\0';
            
            DEBUG_PRINT("You entered: %s\n", inputfromcli);
        }
	}
}