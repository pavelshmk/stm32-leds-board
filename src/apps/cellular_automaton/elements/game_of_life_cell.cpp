//
// Created by bakatrouble on 23/10/22.
//

#include "game_of_life_cell.h"
#include "../cellular_automaton.h"

using namespace cellular_automaton::elements;

void GameOfLifeCell::preStep(cellular_automaton::CellularAutomaton *ca, vec2ca &pos, uint32_t dt) {
    _neighbors = 0;
    for (uint8_t x = pos.x - 1; x <= pos.x + 1; x++) {
        for (uint8_t y = pos.y - 1; y <= pos.y + 1; y++) {
            if (x == pos.x && y == pos.y)
                continue;
            uint8_t actX = x, actY = y;
            if (x == 0) actX = 16;
            if (x == 17) actX = 1;
            if (y == 0) actY = 18;
            if (y == 19) actY = 1;
            if (!((GameOfLifeCell*)ca->matrix[actX][actY])->empty) {
                _neighbors++;
            }
        }
    }
}

void GameOfLifeCell::step(cellular_automaton::CellularAutomaton *ca, vec2ca &pos, uint32_t dt) {
    if (!empty) {
        if (_neighbors < 2 || _neighbors > 3)
            empty = true;
    } else {
        if (_neighbors == 3)
            empty = false;
    }
}
