#include "device_uart.h"
#include <ringbuffer.h>

ring_buffer_t tx_fifo, rx_fifo;

static inline void UART_EnableTXEInterrupt(void) {
    SET_BIT(USART1->CR1, USART_CR1_TXEIE);
}

static inline void UART_DisableTXEInterrupt(void) {
    CLEAR_BIT(USART1->CR1, USART_CR1_TXEIE);
}

static inline void UART_EnableRXNEInterrupt(void) {
    SET_BIT(USART1->CR1, USART_CR1_RXNEIE);
}

UART_HandleTypeDef huart1;

void UART_Init(void) {
    GPIO_InitTypeDef GPIO_InitStruct = {0};

    __HAL_RCC_GPIOA_CLK_ENABLE();
    /**USART1 GPIO Configuration
    PA9     ------> USART1_TX
    PA10     ------> USART1_RX
    */
    GPIO_InitStruct.Pin = GPIO_PIN_9;
    GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
    GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_HIGH;
    HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

    GPIO_InitStruct.Pin = GPIO_PIN_10;
    GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
    GPIO_InitStruct.Pull = GPIO_NOPULL;
    HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

    __HAL_RCC_USART1_CLK_ENABLE();

    huart1.Instance = USART1;
    huart1.Init.BaudRate = 921600;
    huart1.Init.WordLength = UART_WORDLENGTH_8B;
    huart1.Init.StopBits = UART_STOPBITS_1;
    huart1.Init.Parity = UART_PARITY_NONE;
    huart1.Init.Mode = UART_MODE_TX_RX;
    huart1.Init.HwFlowCtl = UART_HWCONTROL_NONE;
    huart1.Init.OverSampling = UART_OVERSAMPLING_16;
    HAL_UART_Init(&huart1);

    // init ring buffers
    ring_buffer_init(&tx_fifo);
    ring_buffer_init(&rx_fifo);

    UART_EnableRXNEInterrupt();

    NVIC_EnableIRQ(USART1_IRQn);
}

void UART_RingPut(uint8_t c) {
    while (RING_BUFFER_SIZE - ring_buffer_num_items(&tx_fifo) < 5);  // wait for ring buf to free up
    NVIC_DisableIRQ(USART1_IRQn);
    ring_buffer_queue(&tx_fifo, c);
    UART_EnableTXEInterrupt();
    NVIC_EnableIRQ(USART1_IRQn);
}

uint8_t UART_RingGet(void) {
    char ret;
    NVIC_DisableIRQ(USART1_IRQn);
    ring_buffer_dequeue(&rx_fifo, &ret);
    NVIC_EnableIRQ(USART1_IRQn);
    return ret;
}

void UART_Transmit(const uint8_t *buf, size_t n) {
    while (n) {
        UART_RingPut(*buf);
        buf++;
        n--;
    }
}

uint16_t UART_Available(void) {
    return ring_buffer_num_items(&rx_fifo);
}

void USART1_IRQHandler(void) {
    // rx enabled and rx not empty
    if((USART1->SR & USART_SR_RXNE) && (USART1->CR1 & USART_CR1_RXNEIE)) {
        char b = (char)USART1->DR;
        ring_buffer_queue(&rx_fifo, b);
    }

    // tx enabled and tx empty
    if ((USART1->SR & USART_SR_TXE) && (USART1->CR1 & USART_CR1_TXEIE)) {
        if (ring_buffer_is_empty(&tx_fifo)) {
            UART_DisableTXEInterrupt();
        } else {
            char data;
            ring_buffer_dequeue(&tx_fifo, &data);
            USART1->SR;
            USART1->DR = data;  // send
        }
    }
}
