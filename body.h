#ifndef BODY_H_
#define BODY_H_

#include <cmath>
#include "util.h"

class Body {
    private:
    vec2 result_force;
    vec2 velocity;
    vec2 acceleration;

    protected:
    double mass;
    double radius;
    vec2 position;

   void move();

    public:    
    Body();

    double get_x();
    double get_y();
    double get_mass();
    double get_radius();

    Body* set_mass(double mass);
    Body* set_radius(double radius);
    Body* set_position(double x, double y);

    void clear_velocity();
    void add_force(double force, double angle);
};

#endif /* BODY_H_ */