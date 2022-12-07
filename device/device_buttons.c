//
// Created by bakatrouble on 23/10/22.
//

#include "device_buttons.h"

uint8_t flags;

#define PUSH1_DOWN          (1 << 0)
#define PUSH2_DOWN          (1 << 1)
#define PUSH1_PRESSED       (1 << 2)
#define PUSH2_PRESSED       (1 << 3)
#define PUSH1_LONG_PRESSED  (1 << 4)
#define PUSH2_LONG_PRESSED  (1 << 5)
uint32_t push1Start;
uint32_t push2Start;

void Buttons_Init() {
    GPIO_InitTypeDef GPIO_InitStruct = {0};

    __HAL_RCC_GPIOC_CLK_ENABLE();

    GPIO_InitStruct.Pin = PUSH1_Pin|PUSH2_Pin;
    GPIO_InitStruct.Mode = GPIO_MODE_IT_RISING_FALLING;
    GPIO_InitStruct.Pull = GPIO_PULLUP;
    HAL_GPIO_Init(GPIOC, &GPIO_InitStruct);

    HAL_NVIC_SetPriority(EXTI15_10_IRQn, 0, 0);
    HAL_NVIC_EnableIRQ(EXTI15_10_IRQn);
}

bool Buttons_PUSH1Pressed() {
    bool res = (flags & PUSH1_PRESSED) != 0;
    flags &= ~PUSH1_PRESSED;
    return res;
}

bool Buttons_PUSH2Pressed() {
    bool res = (flags & PUSH2_PRESSED) != 0;
    flags &= ~PUSH2_PRESSED;
    return res;
}

void Buttons_ClearFlags() {
    flags = 0;
}

bool Buttons_PUSH1LongPressed() {
    bool res = (flags & PUSH1_LONG_PRESSED) != 0;
    flags &= ~PUSH1_LONG_PRESSED;
    return res;
}

bool Buttons_PUSH2LongPressed() {
    bool res = (flags & PUSH2_LONG_PRESSED) != 0;
    flags &= ~PUSH2_LONG_PRESSED;
    return res;
}

void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin) {
    switch (GPIO_Pin) {
        case PUSH1_Pin:
            if (!HAL_GPIO_ReadPin(PUSH1_GPIO_Port, PUSH1_Pin)) {
                // pressed
                if ((flags & PUSH1_DOWN) == 0) {
                    flags |= PUSH1_DOWN;
                    push1Start = HAL_GetTick();
                }
            } else {
                if ((flags & PUSH1_DOWN) != 0) {
                    flags &= ~PUSH1_DOWN;
                    flags |= PUSH1_PRESSED;
                }
            }
            break;
        case PUSH2_Pin:
            if (!HAL_GPIO_ReadPin(PUSH2_GPIO_Port, PUSH2_Pin)) {
                // pressed
                if ((flags & PUSH2_DOWN) == 0) {
                    flags |= PUSH2_DOWN;
                    push2Start = HAL_GetTick();
                }
            } else {
                if ((flags & PUSH2_DOWN) != 0) {
                    flags &= ~PUSH2_DOWN;
                    flags |= PUSH2_PRESSED;
                }
            }
            break;
        default:
            break;
    }
}

void Buttons_MsTickHandler() {
    uint32_t currentTick = HAL_GetTick();
    if ((flags & PUSH1_DOWN) != 0 && currentTick - push1Start > 300) {
        flags &= ~PUSH1_DOWN;
        flags |= PUSH1_LONG_PRESSED;
    }
    if ((flags & PUSH2_DOWN) != 0 && currentTick - push2Start > 300) {
        flags &= ~PUSH2_DOWN;
        flags |= PUSH2_LONG_PRESSED;
    }
}

void EXTI15_10_IRQHandler(void) {
    HAL_GPIO_EXTI_IRQHandler(PUSH1_Pin);
    HAL_GPIO_EXTI_IRQHandler(PUSH2_Pin);
}
