//
// Created by bakatrouble on 23/10/22.
//

#ifndef LEDS_BOARD_WALL_H
#define LEDS_BOARD_WALL_H

#include "element.h"

namespace cellular_automaton::elements {

    class Wall : public Element {
    public:
        void step(CellularAutomaton *ca, vec2ca &pos, uint32_t dt) override {};
    };

}

#endif //LEDS_BOARD_WALL_H
