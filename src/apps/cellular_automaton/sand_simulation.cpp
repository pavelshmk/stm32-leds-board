//
// Created by bakatrouble on 23/10/22.
//

#include "sand_simulation.h"
#include "elements/wall.h"
#include "elements/sand.h"

using namespace cellular_automaton::elements;

SandSimulation::SandSimulation() : CellularAutomaton() {
    for (int8_t y = 19; y >= 0; y--) {
        for (uint8_t x = 0; x < 18; x++) {
            if (y == 19 || y == 0 || x == 0 || x == 17) {
                matrix[x][y] = new Wall;
            } else {
                matrix[x][y] = nullptr;
            }
        }
    }
    for (uint8_t i=0; i < 144; i++) {
        while (true) {
            uint8_t x = Random_GetRange(1, 16);
            uint8_t y = Random_GetRange(1, 18);
            if (matrix[x][y] == nullptr) {
                matrix[x][y] = new Sand;
                break;
            }
        }
    }
    Accelerometer_Start();
}

void SandSimulation::run() {
    uint32_t frameStart;
    while (true) {
        frameStart = HAL_GetTick();
        if (Buttons_PUSH1LongPressed() || Buttons_PUSH2LongPressed()) {
            break;
        }
        step(frameStart, 1);
        uint32_t dt = HAL_GetTick() - frameStart;
        printf("%d\r\n", dt);
        if (dt < 16) {
            HAL_Delay(16 - dt);
        }
    }
}

