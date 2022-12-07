//
// Created by bakatrouble on 23/10/22.
//

#ifndef LEDS_BOARD_ELEMENT_H
#define LEDS_BOARD_ELEMENT_H

#include <array>
#include <stm32f1xx_hal.h>
#include "vec2.h"

namespace cellular_automaton {
    class CellularAutomaton;
}

namespace cellular_automaton::elements {

    class Element {
    public:
        virtual ~Element() = default;

        virtual void init(CellularAutomaton *ca, vec2ca &pos) {};
        virtual void preStep(CellularAutomaton *ca, vec2ca &pos, uint32_t dt) {};
        virtual void step(CellularAutomaton *ca, vec2ca &pos, uint32_t dt) = 0;
        virtual void postStep(CellularAutomaton *ca, vec2ca &pos, uint32_t dt) {};
        void moveTo(CellularAutomaton *ca, const vec2ca &from, const vec2ca &to);

        virtual uint8_t color() {
            return 0;
        };

        vec2<float> vel;
        uint32_t lastUpdateTick;
    };
}

#endif //LEDS_BOARD_ELEMENT_H
