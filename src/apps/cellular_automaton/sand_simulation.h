//
// Created by bakatrouble on 23/10/22.
//

#ifndef LEDS_BOARD_SAND_SIMULATION_H
#define LEDS_BOARD_SAND_SIMULATION_H

#include "cellular_automaton.h"

using namespace cellular_automaton;

class SandSimulation : public CellularAutomaton {
public:
    SandSimulation();

    void run();
};

#endif //LEDS_BOARD_SAND_SIMULATION_H
