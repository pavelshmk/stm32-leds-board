//
// Created by bakatrouble on 23/10/22.
//

#ifndef LEDS_BOARD_SAND_H
#define LEDS_BOARD_SAND_H

#include "element.h"

namespace cellular_automaton::elements {

    class Sand : public Element {
    public:
        void step(CellularAutomaton *ca, vec2ca &pos, uint32_t dt) override;

        uint8_t color() override {
            return 0x10;
        }
    };

}

#endif //LEDS_BOARD_SAND_H
