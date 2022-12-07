//
// Created by bakatrouble on 20/10/22.
//

#include "device_random.h"

uint16_t Random_Seed;

void Random_Init() {
    Accelerometer_Start();
    uint16_t x, y, z;
    Accelerometer_GetRawAccel(&x, &y, &z);
    Random_Seed = x * y + z;
    Accelerometer_Stop();
}

uint16_t Random_Get() {
    Random_Seed = Random_Seed * 2053ul + 13849;
    return Random_Seed;
}

uint16_t Random_GetMax(uint16_t max) {
    return ((uint32_t)max * Random_Get()) >> 16;
}

uint16_t Random_GetRange(uint16_t min, uint16_t max) {
    return Random_GetMax(max - min) + min;
}

