#ifndef PLANET_H_
#define PLANET_H_

#include <cmath>
#include <raylib.h>
#include "body.h"

using namespace std;

class Planet: public Body {
    private:
    Color color;
    Vector2 mouse_offset;
    enum {
        IDLE,
        DRAGGING,
    } state;

    public:
    Planet(Color color);

    void clear_velocity();

    void draw();
    void update();
    void mouse_button_down();
    void mouse_button_up();
};

#endif /* PLANET_H_ */