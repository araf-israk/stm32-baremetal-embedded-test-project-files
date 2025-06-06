
#include "gy521.h"

char data;

uint8_t data_rec[6];

void adxl_read_address(uint8_t reg){
	I2C1_byteRead(DEVICE_ADDR, reg, &data);

}

void adxl_write(uint8_t reg, char value){
	char data[1];
	data[0] = value;

	I2C1_burstWrite(DEVICE_ADDR, reg, 1, data);
}

void adxl_read_values(uint8_t reg){
	I2C1_burstRead(DEVICE_ADDR, reg, 6, (char*)data_rec);
}


void adxl_init(void){
	adxl_read_address(0x75);
}
