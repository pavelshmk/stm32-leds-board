//
// Created by bakatrouble on 19/10/22.
//

#include <stm32f1xx_hal.h>
#include "device_led.h"

void LED_Init() {
    __HAL_RCC_GPIOA_CLK_ENABLE();
    HAL_GPIO_WritePin(USR_LED_GPIO_Port, USR_LED_Pin, GPIO_PIN_RESET);

    GPIO_InitTypeDef GPIO_InitStruct = {0};
    GPIO_InitStruct.Pin = USR_LED_Pin;
    GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
    GPIO_InitStruct.Pull = GPIO_NOPULL;
    GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
    HAL_GPIO_Init(USR_LED_GPIO_Port, &GPIO_InitStruct);
}

void LED_On() {
    HAL_GPIO_WritePin(USR_LED_GPIO_Port, USR_LED_Pin, GPIO_PIN_SET);
}

void LED_Off() {
    HAL_GPIO_WritePin(USR_LED_GPIO_Port, USR_LED_Pin, GPIO_PIN_RESET);

}
void LED_Set(bool value) {
    HAL_GPIO_WritePin(USR_LED_GPIO_Port, USR_LED_Pin, value);

}
void LED_Toggle() {
    HAL_GPIO_TogglePin(USR_LED_GPIO_Port, USR_LED_Pin);
}
