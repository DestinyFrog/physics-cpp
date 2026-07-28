#ifndef PLANET_H_
#define PLANET_H_

#include <cmath>
#include <raylib.h>

using namespace std;

class Planet {
    private:
    double mass;
    Vector2 result_force;
    Vector2 velocity;
    Vector2 acceleration;
    Color color;

    Vector2 position;
    Vector2 mouse_offset;
    double radius;
    enum {
        IDLE,
        DRAGGING,
    } state;

    public:
    Planet(float x, float y, double radius, double mass, Color color);

    double get_mass();
    Vector2 get_position();
    double get_x();
    double get_y();
    double get_radius();
    void clear_velocity();

    void draw();
    void update();
    void mouse_button_down();
    void mouse_button_up();
    void add_force(double force, double angle);
};

#endif /* PLANET_H_ */