//
// Created by bakatrouble on 23/10/22.
//

#include "game_of_life.h"
#include "elements/game_of_life_cell.h"

using namespace cellular_automaton::elements;

GameOfLife::GameOfLife() : CellularAutomaton() {
    for (int8_t y = 19; y >= 0; y--) {
        for (uint8_t x = 0; x < 18; x++) {
            matrix[x][y] = new GameOfLifeCell(true);
        }
    }

    regenerate();

    Buttons_ClearFlags();
}

void GameOfLife::run() {
    uint32_t frameStart;
    while (true) {
        frameStart = HAL_GetTick();
        if (Buttons_PUSH1Pressed() || Buttons_PUSH2Pressed()) {
            regenerate();
        }
        if (Buttons_PUSH1LongPressed() || Buttons_PUSH2LongPressed()) {
            break;
        }
        step(frameStart, 1);
        uint32_t dt = HAL_GetTick() - frameStart;
        printf("%d\r\n", dt);
        if (dt < 100) {
            HAL_Delay(100 - dt);
        }
    }
}

void GameOfLife::regenerate() {
    for (uint8_t i=0; i < 25; i++) {
        while (true) {
            uint8_t x = Random_GetRange(1, 17);
            uint8_t y = Random_GetRange(1, 19);
            if (((GameOfLifeCell*)matrix[x][y])->empty) {
                ((GameOfLifeCell*)matrix[x][y])->empty = false;
                break;
            }
        }
    }

    for (uint8_t y = 18; y >= 1; y--) {
        for (uint8_t x = 1; x < 17; x++) {
            auto *el = matrix[x][y];
            if (el == nullptr) {
                LedMatrix_SetPixel(x-1, y-1, 0);
            } else {
                LedMatrix_SetPixel(x-1, y-1, el->color());
            }
        }
    }
    LedMatrix_Display();
}
