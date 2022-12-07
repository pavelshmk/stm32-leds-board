#include <stm32f1xx_hal.h>
#include "apps/cellular_automaton/sand_simulation.h"
#include "apps/cellular_automaton/game_of_life.h"
#include "balls_icon.h"
#include "sand_icon.h"
#include "files_icon.h"
#include "life_icon.h"
#include "microsd_err_icon.h"
#include "apps/balls/physics.h"
#include "ff.h"

void start_sand_simulation() {
    auto sim = new SandSimulation();
    sim->run();
    delete sim;
}

void start_game_of_life() {
    auto sim = new GameOfLife();
    sim->run();
    delete sim;
}

typedef struct {
    uint8_t magic[4];
    uint32_t frames;
    uint32_t delay_ms;
} __attribute__((packed, aligned(4))) animation_header_t;

void start_animation_player() {
    FATFS fs;
    DIR dp;
    FILINFO fil;
    FRESULT mount_res;
    FRESULT open_res;
    FIL fp;
    UINT bytes_read;
    uint8_t file_idx = 0;

    LedMatrix_Fill(0);
    bool card_inserted =  !HAL_GPIO_ReadPin(SDCARD_DET_GPIO_Port, SDCARD_DET_Pin);
    if (card_inserted) {
        mount_res = f_mount(&fs, "", 1);
        if (mount_res == FR_OK) {
            open_res = f_opendir(&dp, "");
            if (open_res == FR_OK) {
                open_res = f_readdir(&dp, &fil);
            }
        }
    }
    if (!card_inserted || mount_res != FR_OK || open_res != FR_OK || fil.fname[0] == 0) {
        LedMatrix_DrawBitmap1(0, 1, BITMAP(microsd_err_icon), 0x10, 0);
        LedMatrix_Display();
        HAL_Delay(1000);
        return;
    }

    while (true) {
        LedMatrix_Fill(0);

        bool error = false;
        animation_header_t header;

        if (f_open(&fp, fil.fname, FA_READ) != FR_OK) {
            error = true;
        } else {
            if (f_read(&fp, &header, sizeof(header), &bytes_read) != FR_OK) {
                error = true;
            } else {
                if (header.magic[0] != '3' || header.magic[1] != '7' || header.magic[2] != '3' || header.magic[3] != '1') {
                    error = true;
                }
            }
        }

        if (error) {
            LedMatrix_DrawBitmap1(0, 1, BITMAP(microsd_err_icon), 0x10, 0);
            LedMatrix_Display();
        }

        uint32_t lastTick = HAL_GetTick() - header.delay_ms - 1;
        uint8_t frame[16 * 18];
        uint32_t frameIdx = 0;
        while (true) {
            if (!error && HAL_GetTick() - lastTick >= header.delay_ms) {
                if (frameIdx >= header.frames) {
                    f_lseek(&fp, sizeof(header));
                }
                lastTick = HAL_GetTick();
                if (f_read(&fp, &frame, sizeof(frame), &bytes_read) != FR_OK || bytes_read != 16 * 18) {
                    error = true;
                    LedMatrix_DrawBitmap1(0, 1, BITMAP(microsd_err_icon), 0x10, 0);
                    LedMatrix_Display();
                } else {
                    LedMatrix_DrawBitmap8(0, 0, 16, 18, frame);
                    LedMatrix_Display();
                    frameIdx++;
                }
            }

            if (Buttons_PUSH1Pressed() && file_idx > 0) {
                f_readdir(&dp, nullptr);
                for (uint8_t i=0; i < file_idx; i++)
                    f_readdir(&dp, &fil);
                file_idx--;
                break;
            }
            if (Buttons_PUSH2Pressed()) {
                f_readdir(&dp, &fil);
                if (fil.fname[0] == 0) {
                    f_readdir(&dp, nullptr);
                    f_readdir(&dp, &fil);
                }
                file_idx++;
                break;
            }
            if (Buttons_PUSH1LongPressed() || Buttons_PUSH2LongPressed()) {
                goto animation_player_end;
            }
        }

        f_close(&fp);
    }

animation_player_end:
    f_close(&fp);
    f_unmount("");
}

void start_menu() {
    uint8_t idx = 0;
    while (true) {
        LedMatrix_Fill(0);
        switch (idx) {
            case 0:
                LedMatrix_DrawBitmap1(0, 0, BITMAP(sand_icon), 0x10, 0);
                break;
            case 1:
                LedMatrix_DrawBitmap1(0, 0, BITMAP(life_icon), 0x10, 0);
                break;
            case 2:
                LedMatrix_DrawBitmap1(0, 0, BITMAP(balls_icon), 0x10, 0);
                break;
            case 3:
                LedMatrix_DrawBitmap1(0, 0, BITMAP(files_icon), 0x10, 0);
                break;
        }
        for (uint8_t x = idx * 4; x < (idx + 1) * 4; x++) {
            LedMatrix_SetPixel(x, 17, 0x10);
        }
        LedMatrix_Display();

        if (Buttons_PUSH1Pressed()) {
            if (idx == 0)
                idx = 3;
            else
                idx--;
        }
        if (Buttons_PUSH2Pressed()) {
            idx++;
            if (idx == 4)
                idx = 0;
        }
        if (Buttons_PUSH1LongPressed() || Buttons_PUSH2LongPressed()) {
            switch (idx) {
                case 0:
                    start_sand_simulation();
                    break;
                case 1:
                    start_game_of_life();
                    break;
                case 2:
//                    physics();
                    break;
                case 3:
                    start_animation_player();
                    break;
            }
        }
//        break;
    }
}

int main() {
    System_Init();

    printf("Started\r\n");

    start_menu();
}
