//
// Created by bakatrouble on 20/10/22.
//

#include <stm32f1xx_hal.h>
#include "device_battery.h"

#define BATTERY_VOLTAGE_HISTORY_SIZE 16

ADC_HandleTypeDef hadc1;
TIM_HandleTypeDef htim3;

float batteryVoltageHistory[BATTERY_VOLTAGE_HISTORY_SIZE];
uint8_t batteryVoltageHistoryPtr;

void Battery_Init() {
    __HAL_RCC_GPIOA_CLK_ENABLE();

    GPIO_InitTypeDef GPIO_InitStruct = {0};
    ADC_ChannelConfTypeDef sConfig = {0};
    TIM_ClockConfigTypeDef sClockSourceConfig = {0};
    TIM_MasterConfigTypeDef sMasterConfig = {0};

    GPIO_InitStruct.Pin = BATT_SENS_Pin;
    GPIO_InitStruct.Mode = GPIO_MODE_ANALOG;
    HAL_GPIO_Init(BATT_SENS_GPIO_Port, &GPIO_InitStruct);

    GPIO_InitStruct.Pin = CHRG_NCE_Pin;
    GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
    GPIO_InitStruct.Pull = GPIO_NOPULL;
    GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
    HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

    __HAL_RCC_ADC1_CLK_ENABLE();
    __HAL_RCC_TIM3_CLK_ENABLE();

    hadc1.Instance = ADC1;
    hadc1.Init.ScanConvMode = ADC_SCAN_DISABLE;
    hadc1.Init.ContinuousConvMode = DISABLE;
    hadc1.Init.DiscontinuousConvMode = DISABLE;
    hadc1.Init.ExternalTrigConv = ADC_EXTERNALTRIGCONV_T3_TRGO;
    hadc1.Init.DataAlign = ADC_DATAALIGN_RIGHT;
    hadc1.Init.NbrOfConversion = 1;
    HAL_ADC_Init(&hadc1);

    /** Configure Regular Channel
    */
    sConfig.Channel = ADC_CHANNEL_1;
    sConfig.Rank = ADC_REGULAR_RANK_1;
    sConfig.SamplingTime = ADC_SAMPLETIME_1CYCLE_5;
    HAL_ADC_ConfigChannel(&hadc1, &sConfig);

    htim3.Instance = TIM3;
    htim3.Init.Prescaler = 48-1;
    htim3.Init.CounterMode = TIM_COUNTERMODE_UP;
    htim3.Init.Period = 100-1;
    htim3.Init.ClockDivision = TIM_CLOCKDIVISION_DIV1;
    htim3.Init.AutoReloadPreload = TIM_AUTORELOAD_PRELOAD_DISABLE;
    HAL_TIM_Base_Init(&htim3);

    sClockSourceConfig.ClockSource = TIM_CLOCKSOURCE_INTERNAL;
    HAL_TIM_ConfigClockSource(&htim3, &sClockSourceConfig);

    sMasterConfig.MasterOutputTrigger = TIM_TRGO_UPDATE;
    sMasterConfig.MasterSlaveMode = TIM_MASTERSLAVEMODE_DISABLE;
    HAL_TIMEx_MasterConfigSynchronization(&htim3, &sMasterConfig);

    HAL_NVIC_SetPriority(ADC1_2_IRQn, 5, 0);
    HAL_NVIC_EnableIRQ(ADC1_2_IRQn);

    HAL_ADC_Start_IT(&hadc1);
    HAL_TIM_Base_Start(&htim3);
}

float Battery_GetVoltage() {
    float val = 0.f;
    for (int i = 0; i < BATTERY_VOLTAGE_HISTORY_SIZE; ++i) {
        val += batteryVoltageHistory[i];
    }
    val /= (float)BATTERY_VOLTAGE_HISTORY_SIZE;
    return val;
}

void HAL_ADC_ConvCpltCallback(ADC_HandleTypeDef *hadc) {
    UNUSED(hadc);
    batteryVoltageHistory[batteryVoltageHistoryPtr] = (float)HAL_ADC_GetValue(&hadc1) / 620.5f;  // / 1023.f * 3300.f / 1000.f * 2.f;
    batteryVoltageHistoryPtr = (batteryVoltageHistoryPtr + 1) % BATTERY_VOLTAGE_HISTORY_SIZE;
}

void ADC1_2_IRQHandler() {
    HAL_ADC_IRQHandler(&hadc1);
}
