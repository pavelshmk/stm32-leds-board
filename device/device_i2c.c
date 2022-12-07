//
// Created by bakatrouble on 20/10/22.
//

#include "device_i2c.h"
#include <stm32f1xx_hal.h>
#include <stdio.h>

I2C_HandleTypeDef hi2c1;

void I2C_Init() {
    __HAL_RCC_GPIOB_CLK_ENABLE();

    GPIO_InitTypeDef GPIO_InitStruct = {0};
    /**I2C1 GPIO Configuration
    PB6     ------> I2C1_SCL
    PB7     ------> I2C1_SDA
    */
    GPIO_InitStruct.Pin = GPIO_PIN_6|GPIO_PIN_7;
    GPIO_InitStruct.Mode = GPIO_MODE_AF_OD;
    GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_HIGH;
    HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);

    /* Peripheral clock enable */
    __HAL_RCC_I2C1_CLK_ENABLE();
    hi2c1.Instance = I2C1;
    hi2c1.Init.ClockSpeed = 400000;
    hi2c1.Init.DutyCycle = I2C_DUTYCYCLE_2;
    hi2c1.Init.OwnAddress1 = 0;
    hi2c1.Init.AddressingMode = I2C_ADDRESSINGMODE_7BIT;
    hi2c1.Init.DualAddressMode = I2C_DUALADDRESS_DISABLE;
    hi2c1.Init.OwnAddress2 = 0;
    hi2c1.Init.GeneralCallMode = I2C_GENERALCALL_DISABLE;
    hi2c1.Init.NoStretchMode = I2C_NOSTRETCH_DISABLE;
    HAL_I2C_Init(&hi2c1);
}

void I2C_Scan() {
    HAL_Delay(1000);

    /*-[ I2C Bus Scanning ]-*/
    printf("Starting I2C Scanning: \r\n");
    printf("    0  1  2  3  4  5  6  7  8  9  a  b  c  d  e  f\r\n");
    for(uint8_t i = 1; i < 128; i += 16) {
        printf("%02x: ", i);
        for(int j = 0; j < 16; j++) {
            // Skip unwanted addresses
            if (i + j < 0x3 || i + j > 0x77) {
                printf("   ");
                continue;
            }

            int ret = HAL_I2C_IsDeviceReady(&hi2c1, (uint16_t) ((i + j) << 1), 3, 5);
            if (ret != HAL_OK) {
                printf("-- ");
            } else {
                printf("%02x ", i + j);
            }
        }
        printf("\r\n");
    }
    printf("Done! \r\n\r\n");
}
