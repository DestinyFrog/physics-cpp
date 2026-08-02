#ifndef BODY_H_
#define BODY_H_

#include <cmath>
#include <raylib.h>
#include "util.hpp"

class Body {
    private:
    vec2 result_force;

    protected:
    void move();

    public:
    vec2 velocity;
    vec2 acceleration;
    double restitution;
    double mass;
    double radius;
    vec2 position;

    Body();

    void clear_velocity();
    void inverse_velocity();
    void add_force(double force, double angle);
};

#endif /* BODY_H_ */