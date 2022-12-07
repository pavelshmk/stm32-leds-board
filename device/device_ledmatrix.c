//
// Created by bakatrouble on 20/10/22.
//

#include <memory.h>
#include "device_ledmatrix.h"

#define ISSI_ADDR1 (0x74 << 1)
#define ISSI_ADDR2 (0x76 << 1)
#define STATE_Pos 0x00
#define BLINK_Pos 0x12
#define PWM_Pos 0x24
#define CONFIG_PAGE (0x0B)
#define TOGGLE_FRAME (nextFrame = nextFrame == 0 ? 1 : 0)

typedef enum {
    ISSI_REG_CONFIG = 0x00,
    ISSI_REG_PICTUREFRAME,
    ISSI_REG_AUTOPLAY1,
    ISSI_REG_AUTOPLAY2,
    // 0x04 reserved
    ISSI_REG_DISPLAYOPTION = 0x05,
    ISSI_REG_AUDIOSYNC,
    ISSI_REG_FRAMESTATE,
    ISSI_REG_BREATH1,
    ISSI_REG_BREATH2,
    ISSI_REG_SHUTDOWN,
    ISSI_REG_AGC,
    ISSI_REG_AUDIOADC,
    ISSI_REG_PAGE = 0xFD,
} ISSI_registers;

typedef enum {
    ISSI_CONFIG_PICTUREMODE = 0x00,
    ISSI_CONFIG_AUTOFRAMEMODE = 0x04,
    ISSI_CONFIG_AUDIOMODE = 0x08
};

extern I2C_HandleTypeDef hi2c1;
uint8_t frameBuf[144 * 2];
uint8_t nextFrame = 1;

void LedMatrix_SelectPage(uint8_t devAddr, uint8_t page) {
    HAL_I2C_Mem_Write(&hi2c1, devAddr, ISSI_REG_PAGE, 1, &page, 1, HAL_MAX_DELAY);
}

void LedMatrix_SetConfigReg(uint8_t devAddr, uint8_t reg, uint8_t value) {
    LedMatrix_SelectPage(devAddr, CONFIG_PAGE);
    HAL_I2C_Mem_Write(&hi2c1, devAddr, reg, 1, &value, 1, HAL_MAX_DELAY);
}

void LedMatrix_SetPower(uint8_t devAddr, bool value) {
    LedMatrix_SetConfigReg(devAddr, ISSI_REG_SHUTDOWN, value);
}

void LedMatrix_SetConfig(uint8_t devAddr, uint8_t value) {
    LedMatrix_SetConfigReg(devAddr, ISSI_REG_CONFIG, value);
}

void LedMatrix_SetAudioSync(uint8_t devAddr, bool value) {
    LedMatrix_SetConfigReg(devAddr, ISSI_REG_AUDIOSYNC, value);
}

void LedMatrix_EnableLEDs(uint8_t devAddr, uint8_t frame) {
    LedMatrix_SelectPage(devAddr, frame);
    const uint8_t data[] = { 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF };
    HAL_I2C_Mem_Write(&hi2c1, devAddr, STATE_Pos, 1, data, sizeof(data), HAL_MAX_DELAY);
}

void LedMatrix_SendFrame(uint8_t devAddr, uint8_t frame) {
    LedMatrix_SelectPage(devAddr, frame);
    HAL_I2C_Mem_Write(&hi2c1, devAddr, PWM_Pos, 1, frameBuf + (devAddr == ISSI_ADDR1 ? 0 : 144), 144, HAL_MAX_DELAY);
}

void LedMatrix_LowLevelClear(uint8_t devAddr, uint8_t frame) {
    uint8_t *f = frameBuf + (devAddr == ISSI_ADDR1 ? 0 : 144);
    memset((void *)f, 0, 144);

    LedMatrix_EnableLEDs(devAddr, frame);
    LedMatrix_SendFrame(devAddr, frame);
}

void LedMatrix_SelectFrame(uint8_t devAddr, uint8_t frame) {
    LedMatrix_SetConfigReg(devAddr, ISSI_REG_PICTUREFRAME, frame);
}

void LedMatrix_InitSingle(uint8_t devAddr) {
    HAL_Delay(100);
    LedMatrix_SetPower(devAddr, false);
    HAL_Delay(10);
    LedMatrix_SetConfig(devAddr, ISSI_CONFIG_PICTUREMODE);
    LedMatrix_SetAudioSync(devAddr, false);
    LedMatrix_LowLevelClear(devAddr, 1);
    LedMatrix_SelectFrame(devAddr, 1);
    LedMatrix_LowLevelClear(devAddr, 0);
    LedMatrix_SelectFrame(devAddr, 0);
}

void LedMatrix_Init() {
    LedMatrix_InitSingle(ISSI_ADDR1);
    LedMatrix_InitSingle(ISSI_ADDR2);
    LedMatrix_SetPower(ISSI_ADDR1, true);
    LedMatrix_SetPower(ISSI_ADDR2, true);
}

void LedMatrix_Fill(uint8_t value) {
    memset(frameBuf, value, sizeof(frameBuf));
}

void LedMatrix_Display() {
    LedMatrix_SendFrame(ISSI_ADDR1, nextFrame);
    LedMatrix_SendFrame(ISSI_ADDR2, nextFrame);
    LedMatrix_SelectFrame(ISSI_ADDR1, nextFrame);
    LedMatrix_SelectFrame(ISSI_ADDR2, nextFrame);
    TOGGLE_FRAME;
}

void LedMatrix_SetPixel(uint8_t x, uint8_t y, uint8_t value) {
    if (x >= 16 || y >= 18)
        return;

    x = 15 - x;
    y = 17 - y;
    if (x >= 8) {
        x = 23 - x;
        if (y <= 8) {
            y = 8 - y;
        } else {
            y = 26 - y;
        }
    }
    uint16_t idx = x + y * 16;
    frameBuf[idx] = value;
}

void LedMatrix_DrawBitmap1(uint8_t pos_x, uint8_t pos_y, uint8_t width, uint8_t height, const uint8_t *bitmap, uint8_t fgColor, uint8_t bgColor) {
    uint8_t *byte = bitmap;
    uint8_t bit = 0;
    for (uint8_t y=0; y < height; y++) {
        for (uint8_t x=0; x < width; x++) {
            if (((*byte >> (7 - bit)) & 1) == 0) {
                LedMatrix_SetPixel(pos_x + x, pos_y + y, fgColor);
            } else {
                LedMatrix_SetPixel(pos_x + x, pos_y + y, bgColor);
            }
            if (++bit == 8) {
                byte++;
                bit = 0;
            }
        }
        if (bit != 0) {
            byte++;
            bit = 0;
        }
    }
}

void LedMatrix_DrawBitmap8(uint8_t pos_x, uint8_t pos_y, uint8_t width, uint8_t height, const uint8_t *bitmap) {
    uint8_t *byte = bitmap;
    for (uint8_t y=0; y < height; y++) {
        for (uint8_t x=0; x < width; x++) {
            LedMatrix_SetPixel(pos_x + x, pos_y + y, *byte++);
        }
    }
}
