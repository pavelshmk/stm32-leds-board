//
// Created by bakatrouble on 22/10/22.
//

#include "cellular_automaton.h"
#include "elements/element.h"

using namespace cellular_automaton;
using namespace cellular_automaton::elements;

CellularAutomaton::CellularAutomaton() {
    for (int8_t y = 19; y >= 0; y--) {
        for (uint8_t x = 0; x < 18; x++) {
            matrix[x][y] = nullptr;
        }
    }
}

void CellularAutomaton::step(uint32_t currentTick, uint32_t dt) {
    float gz;
    Accelerometer::getAccel(gravity.x, gravity.y, gz);

    for (uint8_t y = 18; y >= 1; y--) {
        for (uint8_t x = 1; x < 17; x++) {
            auto el = matrix[x][y];
            if (el != nullptr) {
                auto pos = vec2ca(x, y);
                el->preStep(this, pos, dt);
            }
        }
    }

    for (uint8_t y = 18; y >= 1; y--) {
        for (uint8_t x = 1; x < 17; x++) {
            auto el = matrix[x][y];
            if (el != nullptr && el->lastUpdateTick != currentTick) {
                auto pos = vec2ca(x, y);
                el->step(this, pos, dt);
                el->lastUpdateTick = currentTick;
            }
        }
    }

    for (uint8_t y = 18; y >= 1; y--) {
        for (uint8_t x = 1; x < 17; x++) {
            auto el = matrix[x][y];
            if (el != nullptr) {
                auto pos = vec2ca(x, y);
                el->postStep(this, pos, dt);
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

CellularAutomaton::~CellularAutomaton() {
    for (int8_t y = 19; y >= 0; y--) {
        for (uint8_t x = 0; x < 18; x++) {
            if (matrix[x][y] != nullptr) {
                delete matrix[x][y];
                matrix[x][y] = nullptr;
            }
        }
    }
}
