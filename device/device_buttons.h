//
// Created by bakatrouble on 23/10/22.
//

#ifndef LEDS_BOARD_DEVICE_BUTTONS_H
#define LEDS_BOARD_DEVICE_BUTTONS_H

#include <stm32f1xx_hal.h>

#ifdef __cplusplus
extern "C" {
#endif

void Buttons_Init();
bool Buttons_PUSH1Pressed();
bool Buttons_PUSH2Pressed();
bool Buttons_PUSH1LongPressed();
bool Buttons_PUSH2LongPressed();
void Buttons_ClearFlags();

#ifdef __cplusplus
}
#endif

#endif //LEDS_BOARD_DEVICE_BUTTONS_H
