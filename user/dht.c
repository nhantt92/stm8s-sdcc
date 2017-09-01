#include "dht.h"

static inline float scale_humidity(DHTType sensor_type, int *data){
	if(sensor_type == DHT11){
		return (float) data[2];
	} else {
		float temperature = data[2] & 0x7f;
		temperature *= 256;
		temperature += data[3];
		temperature /= 10;
		if(data[2] & 0x80)
			temperature *= -1;
		return temperature;
	}
}

char* DHTFloat2String(char* buffer, float value){
	
}