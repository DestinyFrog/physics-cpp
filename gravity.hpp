#ifndef GRAVITY_H_
#define GRAVITY_H_

#include <vector>
#include <cmath>

#include "body.hpp"

using namespace std;

struct BodyNode {
    Body* A;
    Body* B;
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