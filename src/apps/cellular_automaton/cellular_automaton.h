//
// Created by bakatrouble on 22/10/22.
//

#ifndef LEDS_BOARD_CELLULAR_AUTOMATON_H
#define LEDS_BOARD_CELLULAR_AUTOMATON_H

#include <stm32f1xx_hal.h>
#include "src/vec2.h"
#include <array>
#include "elements/element.h"

using namespace std;

namespace cellular_automaton {
    class CellularAutomaton {
        friend class elements::Element;

    public:
        CellularAutomaton();
        ~CellularAutomaton();
        void step(uint32_t currentTick, uint32_t dt);

        vec2f gravity;
        array<array<elements::Element *, 20>, 18> matrix;
    };
}

#endif //LEDS_BOARD_CELLULAR_AUTOMATON_H
