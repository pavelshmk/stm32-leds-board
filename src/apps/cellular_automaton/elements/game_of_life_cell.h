//
// Created by bakatrouble on 23/10/22.
//

#ifndef LEDS_BOARD_GAME_OF_LIFE_CELL_H
#define LEDS_BOARD_GAME_OF_LIFE_CELL_H

#include "element.h"

namespace cellular_automaton::elements {

    class GameOfLifeCell : public Element {
    public:
        explicit GameOfLifeCell(bool empty) : empty(empty) {}
        ~GameOfLifeCell() override {};

        void preStep(cellular_automaton::CellularAutomaton *ca, vec2ca &pos, uint32_t dt) override;
        void step(cellular_automaton::CellularAutomaton *ca, vec2ca &pos, uint32_t dt) override;

        uint8_t color() override {
            return empty ? 0 : 0x10;
        }

        bool empty;

    protected:
        uint8_t _neighbors = 0;
    };
}

#endif //LEDS_BOARD_GAME_OF_LIFE_CELL_H
