#pragma once

/**
 * This module holds the interfaces to all data logging (either through Wifi or flash).
 * Author(s): Elaine
 */

#include "Common.h"

/***********************************************************************************************************************
 * Definitions
 **********************************************************************************************************************/


typedef struct
{
    float t1;
    float t2;
    float t3;
    float t4;
    float t5;
}TempData_t;

typedef struct
{
    int fan;          // either FAN_ON or FAN_OFF (all other values illegal)
    int compressor;   // either COMPRESSOR_ON or COMPRESSOR_OFF (all other values illegal)

}ActuatorData_t;

/***********************************************************************************************************************
 * Prototypes
 **********************************************************************************************************************/

/**
* Initializes internal parameters.
* Should be called exactly once before anything is attempted to be done with this module.
* Failing to call this function, or calling it more than once, voids all guarantees made by this module.
*/
void Logs_Init(void);

/**
* Logs data from sensors, passes to control module.
* @param[in]        TempData          struct containing the average, min and max temperature
* @return           LOG_SUCCEEDED or LOG_FAILED
*/
int Logs_LogLCD(const TempData_t *TempData);
int Logs_LogWifi(const TempData_t * TempData, const ActuatorData_t * ActuatorData);
//int Logs_LogWifi(const TempData_t * TempData, const ActuatorData_t * ActuatorData)

int Logs_LogFlash(const TempData_t *TempData);
