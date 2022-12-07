//
// Created by bakatrouble on 20/10/22.
//

#include "device_accelerometer.h"

#define ADXL345_ADDRESS (0x53 << 1)
#define SENSORS_GRAVITY_EARTH (9.80665f)

extern I2C_HandleTypeDef hi2c1;
float adxl_accel_multiplier = .004f;

typedef enum {
    ADXL_REG_DEVID = 0x00,
    ADXL_REG_THRESH_TAP = 0x1D,
    ADXL_REG_OFSX,
    ADXL_REG_OFSY,
    ADXL_REG_OFSZ,
    ADXL_REG_DUR,
    ADXL_REG_Latent,
    ADXL_REG_Window,
    ADXL_REG_THRESH_ACT,
    ADXL_REG_THRESH_INACT,
    ADXL_REG_TIME_INACT,
    ADXL_REG_ACT_INACT_CTL,
    ADXL_REG_THRESH_FF,
    ADXL_REG_TIME_FF,
    ADXL_REG_TAP_AXES,
    ADXL_REG_ACT_TAP_STATUS,
    ADXL_REG_BW_RATE,
    ADXL_REG_POWER_CTL,
    ADXL_REG_INT_ENABLE,
    ADXL_REG_INT_MAP,
    ADXL_REG_INT_SOURCE,
    ADXL_REG_DATA_FORMAT,
    ADXL_REG_DATAX0,
    ADXL_REG_DATAX1,
    ADXL_REG_DATAY0,
    ADXL_REG_DATAY1,
    ADXL_REG_DATAZ0,
    ADXL_REG_DATAZ1,
    ADXL_REG_FIFO_CTL,
    ADXL_REG_FIFO_STATUS,
} ADXL345_registers;

void Accelerometer_Start() {
    uint8_t a = 0;
    HAL_I2C_Mem_Write(&hi2c1, ADXL345_ADDRESS, ADXL_REG_POWER_CTL, 1, &a, 1, HAL_MAX_DELAY);
    HAL_Delay(10);
    a = 16;  // AUTO_SLEEP
    HAL_I2C_Mem_Write(&hi2c1, ADXL345_ADDRESS, ADXL_REG_POWER_CTL, 1, &a, 1, HAL_MAX_DELAY);
    HAL_Delay(10);
    a = 8;  // Measure
    HAL_I2C_Mem_Write(&hi2c1, ADXL345_ADDRESS, ADXL_REG_POWER_CTL, 1, &a, 1, HAL_MAX_DELAY);
    HAL_Delay(10);
    a = 0b0000011;  // range 16g
    HAL_I2C_Mem_Write(&hi2c1, ADXL345_ADDRESS, ADXL_REG_DATA_FORMAT, 1, &a, 1, HAL_MAX_DELAY);
}

void Accelerometer_Stop() {
    uint8_t a = 0;
    HAL_I2C_Mem_Write(&hi2c1, ADXL345_ADDRESS, ADXL_REG_POWER_CTL, 1, &a, 1, HAL_MAX_DELAY);
}

uint8_t Accelerometer_GetDevId() {
    uint8_t resp;
    HAL_I2C_Mem_Read(&hi2c1, ADXL345_ADDRESS, ADXL_REG_DEVID, 1, &resp, 1, HAL_MAX_DELAY);
    return resp;
}

void Accelerometer_GetRawAccel(int16_t *x, int16_t *y, int16_t *z) {
    uint8_t buf[6];
    HAL_I2C_Mem_Read(&hi2c1, ADXL345_ADDRESS, ADXL_REG_DATAX0, 1, buf, 6, HAL_MAX_DELAY);
    *x = (buf[1] << 8) | buf[0];
    *y = (buf[3] << 8) | buf[2];
    *z = (buf[5] << 8) | buf[4];
}

void Accelerometer_GetAccel(float *gx, float *gy, float *gz) {
    int16_t x, y, z;
    Accelerometer_GetRawAccel(&x, &y, &z);
    *gx = -((float)y / 32.f);
    *gy = -((float)x / 32.f);
    *gz = -((float)z / 32.f);
}
