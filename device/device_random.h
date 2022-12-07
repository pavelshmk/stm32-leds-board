//
// Created by bakatrouble on 20/10/22.
//

#ifndef LEDS_BOARD_DEVICE_RANDOM_H
#define LEDS_BOARD_DEVICE_RANDOM_H

#include <stm32f1xx_hal.h>

#ifdef __cplusplus
extern "C" {
#endif

void Random_Init();
uint16_t Random_Get();
uint16_t Random_GetMax(uint16_t max);
uint16_t Random_GetRange(uint16_t min, uint16_t max);

#ifdef __cplusplus
}
#endif

#endif //LEDS_BOARD_DEVICE_RANDOM_H
