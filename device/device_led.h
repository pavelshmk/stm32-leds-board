//
// Created by bakatrouble on 19/10/22.
//

#ifndef LEDS_BOARD_DEVICE_LED_H
#define LEDS_BOARD_DEVICE_LED_H

#include <stdbool.h>

#ifdef __cplusplus
extern "C" {
#endif

void LED_Init();
void LED_On();
void LED_Off();
void LED_Set(bool value);
void LED_Toggle();

#ifdef __cplusplus
}
#endif

#endif //LEDS_BOARD_DEVICE_LED_H
