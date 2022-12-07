//
// Created by bakatrouble on 23/10/22.
//

#include "sand.h"
#include "../cellular_automaton.h"

using namespace cellular_automaton::elements;

void Sand::step(CellularAutomaton *ca, vec2ca& pos, uint32_t dt) {
    vel += ca->gravity;
    auto nextPosition = pos.add(vel.x, vel.y);

    if (pos.x != nextPosition.x  || pos.y != nextPosition.y)
        moveTo(ca, pos, nextPosition);
}
