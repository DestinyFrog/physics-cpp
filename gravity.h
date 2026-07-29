#ifndef GRAVITY_H_
#define GRAVITY_H_

#include <vector>
#include <cmath>

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

    double distance_between_node(BodyNode* node);
    double angle_between_node(BodyNode* node);

    public:
    Gravity();
    void add_body(Body* body);
    void update();
};

#endif /* GRAVITY_H_ */