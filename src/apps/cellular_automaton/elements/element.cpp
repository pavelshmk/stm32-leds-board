#include "element.h"
#include "../cellular_automaton.h"

using namespace cellular_automaton::elements;

void Element::moveTo(CellularAutomaton *ca, const vec2ca& from, const vec2ca& to) {
    int32_t x0 = from.x, y0 = from.y, x1 = to.x, y1 = to.y;
    int32_t dx = abs(x1 - x0);
    int32_t sx = x0 < x1 ? 1 : -1;
    int32_t dy = -abs(y1 - y0);
    int32_t sy = y0 < y1 ? 1 : -1;
    int32_t error = dx + dy;
    int32_t x = x0, y = y0;
    int32_t prevX = x0, prevY = y0;

    while (true) {
        if (x == x1 && y == y1)
            break;
        int32_t e2 = 2 * error;
        if (e2 >= dy) {
            if (x == x1)
                break;
            error += dy;
            x += sx;
        }
        if (e2 <= dx) {
            if (y == y1)
                break;
            error += dx;
            y += sy;
        }
        if (x != x0 || y != y0) {
            if (ca->matrix[x][y] == nullptr) {
                ca->matrix[x][y] = this;
                ca->matrix[prevX][prevY] = nullptr;
            } else {
                if (x != prevX) {
                    vel.x = 0;
                }
                if (y != prevY) {
                    vel.y = 0;
                }
                break;
            }
            prevX = x;
            prevY = y;
        }
    }
}
