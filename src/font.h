//
// Created by bakatrouble on 20/10/22.
//

#ifndef LEDS_BOARD_FONT_H
#define LEDS_BOARD_FONT_H

#include <stm32f1xx_hal.h>

#ifdef __cplusplus
extern "C" {
#endif

extern uint8_t font[];

uint8_t RenderChar(uint8_t ch, uint8_t x, uint8_t y, uint8_t fgValue, uint8_t bgValue);
void RenderStr(const uint8_t *s, uint8_t x, uint8_t y, uint8_t fgValue, uint8_t bgValue);

#ifdef __cplusplus
}
#endif

#endif //LEDS_BOARD_FONT_H
