/*
 * Main_Shell.c
 *
 *  Created on: Nov 25, 2025
 *      Author: lanjithkumar
 */



#include "Main_Shell.h"
#include <stdio.h>

void RamLiteDb_Shell_Task(void *pv)
{
    char line[256];
    int idx = 0;

    setvbuf(stdin, NULL, _IONBF, 0);
    setvbuf(stdout, NULL, _IONBF, 0);

    DEBUG_PRINT("\n\n--- RamLiteDb Shell Started ---\n");
    DEBUG_PRINT("ramlitedb=> ");

    while (1)
    {
        int c = getchar();

        if (c == EOF || c < 0) {
            continue;
        }
        
        if (c == 0x08 || c == 0x7F) 
        {
            if (idx > 0) {
                idx--;              // Back up in the buffer
                line[idx] = '\0';   // Delete char in memory
                
                DEBUG_PRINT("\b \b"); 
            }
            continue;
        }

        if (c == '\n' || c == '\r')
        {
            DEBUG_PRINT("\n"); // Force a visual new line
            
            if (idx > 0) {
                line[idx] = '\0'; // Null-terminate the string
                
                // DEBUG_PRINT("Command received: %s\n", line);
        		size_t  xBytesSent  = xMessageBufferSend(cli_msg_buffer,(void *) line,sizeof(line),portMAX_DELAY);
        		if(xBytesSent != sizeof(line)){
					DEBUG_PRINT("it is Successfull");
				}else{
					DEBUG_PRINT("It is Failed");
				}
                
            }
            idx = 0;
            memset(line, 0, sizeof(line));
            
            // Re-print the prompt
            DEBUG_PRINT("ramlitedb=> ");
            continue;
        }
        
        if (c >= 32 && c <= 126 && idx < sizeof(line) - 1)
        {
            line[idx++] = (char)c;
            DEBUG_PRINT("%c", c);
        }
    }
}