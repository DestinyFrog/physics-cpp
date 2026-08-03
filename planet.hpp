#ifndef PLANET_H_
#define PLANET_H_

#include <cmath>
#include <iostream>
#include <numbers>
#include <raylib.h>
#include "body.hpp"

using namespace std;

enum PlanetState {
    IDLE,
    DRAGGING,
    AIMING,
    PAUSED,
};

class Planet: public Body {
    private:
    string name;
    Color color;
    Vector2 mouse_offset;
    Vector2 arrow_position;
    bool is_hovering;
    
    void calc_if_hovering();

    public:
    PlanetState state;

    Planet(Color color);

    void draw();
    void update();
    void pause();
    void resume();
};

#endif /* PLANET_H_ */  