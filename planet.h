#ifndef PLANET_H_
#define PLANET_H_

#include <cmath>
#include <numbers>
#include <raylib.h>
#include "body.h"

using namespace std;

class Planet: public Body {
    private:
    Color color;
    Vector2 mouse_offset;
    Vector2 arrow_position;
    enum {
        IDLE,
        DRAGGING,
        AIMING,
    } state;

    public:
    Planet(Color color);

    void draw();
    void update();
    void left_mouse_button_down();
    void left_mouse_button_up();
    void right_mouse_button_down();
    void right_mouse_button_up();
};

#endif /* PLANET_H_ */