//
// Created by bakatrouble on 23/10/22.
//

#ifndef LEDS_BOARD_GAME_OF_LIFE_CELL_H
#define LEDS_BOARD_GAME_OF_LIFE_H

#include "cellular_automaton.h"

using namespace cellular_automaton;

class GameOfLife : public CellularAutomaton {
public:
    GameOfLife();

    void run();

protected:
    void regenerate();
};

#endif //LEDS_BOARD_GAME_OF_LIFE_CELL_H
