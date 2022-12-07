//
// Created by bakatrouble on 14/10/22.
//

#ifndef STATEOS_NASA_DEVICE_UART_H
#define STATEOS_NASA_DEVICE_UART_H

#include <stddef.h>
#include <stm32f1xx_hal.h>

#ifdef  __cplusplus
extern "C" {
#endif

void UART_Init(void);
void UART_RingPut(uint8_t c);
uint8_t UART_RingGet(void);
void UART_Transmit(const uint8_t *buf, size_t n);
uint16_t UART_Available(void);

#ifdef  __cplusplus
}
#endif

#endif //STATEOS_NASA_DEVICE_UART_H
