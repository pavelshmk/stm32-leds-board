//
// Created by bakatrouble on 20/10/22.
//

#ifndef LEDS_BOARD_DEVICE_LEDMATRIX_H
#define LEDS_BOARD_DEVICE_LEDMATRIX_H

#include <stm32f1xx_hal.h>

#define BITMAP(name) name ## _w, name ## _h, name

#ifdef __cplusplus
extern "C" {
#endif

void LedMatrix_Init();
void LedMatrix_Fill(uint8_t value);
void LedMatrix_Display();
void LedMatrix_SetPixel(uint8_t x, uint8_t y, uint8_t value);
void LedMatrix_DrawBitmap1(uint8_t pos_x, uint8_t pos_y, uint8_t width, uint8_t height, const uint8_t *bitmap, uint8_t fgColor, uint8_t bgColor);
void LedMatrix_DrawBitmap8(uint8_t pos_x, uint8_t pos_y, uint8_t width, uint8_t height, const uint8_t *bitmap);

#ifdef __cplusplus
}
#endif

#endif //LEDS_BOARD_DEVICE_LEDMATRIX_H
