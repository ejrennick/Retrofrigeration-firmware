#include <esp8266.h>
#include "Logs.h"

/***********************************************************************************************************************
 * Code
 **********************************************************************************************************************/

void Logs_Init(void)
{
}

int Logs_LogLCD(const TempData_t * TempData)
{
    return 1;
}

//int Logs_LogWifi(const LogData_t * LogData)
int Logs_LogWifi(const TempData_t * TempData, const ActuatorData_t * ActuatorData)
{
//	return 0;
	char data[30];
	ESP_Init("Cloudwifi-280-907", "WCRI2013", "10.10.113.162");
	sprintf(data, "\"%f\",\"%f\",\"%f\",\"%f\",\"%f\",\"%d\",\"%d\",", TempData->t1, TempData->t2, TempData->t3, TempData->t4, TempData->t5, ActuatorData->fan, ActuatorData->compressor);
	Server_Send(data, 0);

  // if wifi not connected, return 0
    return 1;
}

int Logs_LogFlash(const TempData_t * TempData)
{
    // SPI to EEPROM
    return 1;
}
