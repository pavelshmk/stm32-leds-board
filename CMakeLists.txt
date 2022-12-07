cmake_minimum_required(VERSION 3.16)
#set(CMAKE_MODULE_PATH ${CMAKE_CURRENT_SOURCE_DIR}/cmake)
set(STM32_CMAKE_PATH ${CMAKE_CURRENT_SOURCE_DIR})
set(STM32_CUBE_F1_PATH ${CMAKE_CURRENT_SOURCE_DIR}/STM32Cube_FW_F1_V1.8.4)
#set(FREERTOS_PATH ${CMAKE_CURRENT_SOURCE_DIR}/STM32Cube_FW_F1_V1.8.4/Middlewares/Third_Party/FreeRTOS)

set(PROJECT_NAME leds_board)

project(${PROJECT_NAME} C CXX ASM)
set(CMAKE_CXX_STANDARD 20)
set(MAIN_SOURCE_FILE src/main.cpp)

set(CMAKE_INCLUDE_CURRENT_DIR TRUE)

set(HAL_COMP_LIST RCC GPIO CORTEX FLASH PWR DMA EXTI USB UART TIM SPI I2C ADC PCD)
set(CMSIS_COMP_LIST "")
#set(FREERTOS_COMP_LIST "")
#set(FREERTOS_NAMESPACE FreeRTOS)

list(APPEND CMSIS_COMP_LIST STM32F1)
list(APPEND HAL_COMP_LIST STM32F1)
#list(APPEND FREERTOS_COMP_LIST ARM_CM3)
#set(FREERTOS_F1_NAMESPACE ${FREERTOS_NAMESPACE})

find_package(CMSIS COMPONENTS "${CMSIS_COMP_LIST}" REQUIRED)
find_package(HAL COMPONENTS "${HAL_COMP_LIST}" REQUIRED)
#find_package(FreeRTOS COMPONENTS ${FREERTOS_COMP_LIST} REQUIRED)

# Find all device specific drivers:
#find_package(HAL COMPONENTS STM32L0 STM32F1 STM32F4 REQUIRED)
# Find drivers for all families:
#find_package(HAL COMPONENTS RCC GPIO CORTEX REQUIRED)
# Find LL driver:
#find_package(HAL COMPONENTS LL_GPIO REQUIRED)
# Find everything:
#find_package(HAL REQUIRED)

add_subdirectory(lib)
add_subdirectory(device)

add_executable(
        ${PROJECT_NAME}

        ${MAIN_SOURCE_FILE}
        src/retarget.c
#        src/spi_diskio.c
        src/font.c
        src/u8g2_fonts.c
        src/u8x8_fonts.c
        src/fatfs_sd.c
        src/apps/cellular_automaton/cellular_automaton.cpp
        src/apps/cellular_automaton/sand_simulation.cpp
        src/apps/cellular_automaton/game_of_life.cpp
        src/apps/cellular_automaton/elements/element.cpp
        src/apps/cellular_automaton/elements/game_of_life_cell.cpp
        src/apps/cellular_automaton/elements/sand.cpp
        src/apps/cellular_automaton/elements/wall.cpp
        src/apps/balls/physics.cpp
        )
include_directories(
        src
        gfx
)
target_link_libraries(${PROJECT_NAME}
        HAL::STM32::F1::RCC
        HAL::STM32::F1::RCCEx
        HAL::STM32::F1::GPIO
        HAL::STM32::F1::CORTEX
        HAL::STM32::F1::FLASH
        HAL::STM32::F1::PWR
        HAL::STM32::F1::DMA
        HAL::STM32::F1::EXTI
        HAL::STM32::F1::UART
        HAL::STM32::F1::TIM
        HAL::STM32::F1::TIMEx
        HAL::STM32::F1::SPI
        HAL::STM32::F1::I2C
        HAL::STM32::F1::ADC
        HAL::STM32::F1::ADCEx
        HAL::STM32::F1::PCD
        HAL::STM32::F1::LL_USB
        CMSIS::STM32::F103CB
#        CMSIS::STM32::F1::RTOS_V2
        STM32::Nano::FloatPrint
        device::leds_board
        ringbuffer
        FatFs
#        ${FREERTOS_F1_NAMESPACE}::Timers
#        ${FREERTOS_F1_NAMESPACE}::Heap::1
#        ${FREERTOS_F1_NAMESPACE}::ARM_CM3
        )

target_compile_definitions(
        ${PROJECT_NAME}
        PRIVATE

#        USE_CMSIS_RTOS_V2
#        CMSIS_RTOS_V2_DEVICE_HEADER="stm32f1xx_hal.h"
)

add_compile_options(-Wtypename-missing)

stm32_print_size_of_target(${PROJECT_NAME})
