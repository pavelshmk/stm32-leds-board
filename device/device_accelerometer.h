//
// Created by bakatrouble on 20/10/22.
//

#ifndef LEDS_BOARD_DEVICE_ACCELEROMETER_H
#define LEDS_BOARD_DEVICE_ACCELEROMETER_H

#include <stm32f1xx_hal.h>

#ifdef __cplusplus
extern "C" {
#endif

void Accelerometer_Start();
void Accelerometer_Stop();
uint8_t Accelerometer_GetDevId();
void Accelerometer_GetRawAccel(int16_t *x, int16_t *y, int16_t *z);
void Accelerometer_GetAccel(float *gx, float *gy, float *gz);

#ifdef __cplusplus
}

struct Accelerometer {
    static void start() {
        Accelerometer_Start();
    }

    static void stop() {
        Accelerometer_Stop();
    }

    static void getAccel(float &gx, float &gy, float &gz) {
        Accelerometer_GetAccel(&gx, &gy, &gz);
    }
};
#endif

#endif //LEDS_BOARD_DEVICE_ACCELEROMETER_H
