//
// Created by bakatrouble on 20/10/22.
//

#ifndef LEDS_BOARD_DEVICE_BATTERY_H
#define LEDS_BOARD_DEVICE_BATTERY_H

#include <stm32f1xx_hal.h>

#ifdef __cplusplus
extern "C" {
#endif

void Battery_Init();
float Battery_GetVoltage();

#ifdef __cplusplus
}
#endif

#endif //LEDS_BOARD_DEVICE_BATTERY_H
