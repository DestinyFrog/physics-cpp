#ifndef PLANET_H_
#define PLANET_H_

#include <cmath>
#include <numbers>
#include <raylib.h>
#include "body.hpp"

using namespace std;

enum PlanetState {
    IDLE,
    DRAGGING,
    AIMING,
};

class Planet: public Body {
    private:
    Color color;
    Vector2 mouse_offset;
    Vector2 arrow_position;

    public:
    PlanetState state;

    Planet(Color color);

    void draw();
    void update();
};

#endif /* PLANET_H_ */  