#ifndef __DHT_H
#define __DHT_H

#include "stm8s.h"

typedef enum {
	DHT11,
	DHT22
} DHTType;

typedef struct {
	float temperature;
	float humidity;
} DHT_Sensor_Data;

typedef struct {
	uint8_t pin;
	DHTType type;
} DHT_Sensor;

#define DHT_MAXTIMINGS 10000
#define DHT_BREAKTIME 20
#define DHT_MAXCOUNT 32000
//#define DHT_DEBUG

bool DHTInit(DHT_Sensor *sensor);
bool DHTRead(DHT_Sensor *sensor, DHT_Sensor_Data *output);
char* DHTFloat2String(char* buffer, float value);

#endif