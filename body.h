#ifndef BODY_H_
#define BODY_H_

#include <cmath>
#include <raylib.h>
#include "util.h"

class Body {
    private:
    vec2 result_force;
    vec2 velocity;
    vec2 acceleration;

    protected:
    double restitution;
    double mass;
    double radius;
    vec2 position;

   void move();

    public:    
    Body();

    double get_x();
    double get_y();
    double get_velocity_x();
    double get_velocity_y();
    double get_mass();
    double get_radius();

    void set_mass(double mass);
    void set_radius(double radius);
    void set_position(double x, double y);
    void set_velocity(double x, double y);
    void set_restitution(double restitution);

    void clear_velocity();
    void inverse_velocity();
    void add_force(double force, double angle);
};

#endif /* BODY_H_ */