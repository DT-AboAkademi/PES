#include "sensors.h"
#include "BoostSensor/bme280_support.h"
#include "BoostSensor/bme280.h"

void S_Init() {
  bme280_data_readout_template();

}

void S_Pressure() {
  u32 pressure; s32 temp; u32 hum;
  bme280_read_pressure_temperature_humidity(&pressure, &temp, &hum );
}
