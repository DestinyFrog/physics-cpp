#ifndef GRAVITY_H_
#define GRAVITY_H_

#include <vector>
#include <cmath>
#include <iostream>

#include "body.h"

using namespace std;

struct BodyNode {
    Body* body_a;
    Body* body_b;
    bool is_colliding;
};

class Gravity {
    private:
    vector<BodyNode> nodes;
    vector<Body*> bodies;
    double G;

    public:
    Gravity();
    void add_body(Body* body);
    void update();
};

#endif /* GRAVITY_H_ */